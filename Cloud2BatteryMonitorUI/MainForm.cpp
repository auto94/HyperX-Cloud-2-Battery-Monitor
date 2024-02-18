#include "MainForm.h"

using namespace System;
using namespace System::Windows::Forms;

void main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Cloud2BatteryMonitorUI::MainForm form;
	Environment::CurrentDirectory = IO::Path::GetDirectoryName(Application::ExecutablePath);
	Application::Run(% form);
}

/**
 * Enumerates HID devices and returns the HID device info with the highest usage page
 *
 * @return hid_device_info* of the device with the correct vendor/product ID and the highest usage page.
 */
hid_device_info* getHeadsetDeviceInfo() 
{
	struct hid_device_info* devices = NULL;
	
	int id_index = 0;
	int num_supported_devices = sizeof(VENDORS_ARRAY) / sizeof(VENDORS_ARRAY[0]);

	// Loop through the supported device vendor and product IDs until we find a device.
	while (devices == NULL && id_index < num_supported_devices) {
		devices = hid_enumerate((unsigned short)VENDORS_ARRAY[id_index], (unsigned short)PRODUCTS_ARRAY[id_index]);

		id_index++;
	}

	struct hid_device_info* deviceInfo{};

	int highest_usage_page = 0; //I think the highest usage page device is the one that answers with battery level
	for (struct hid_device_info* current = devices; current != nullptr; current = current->next) 
	{
		if (current->usage_page >= highest_usage_page)
		{
			highest_usage_page = current->usage_page;
			deviceInfo = current;
		}
	}

	return deviceInfo;
}
/**
 * Sends a request to the given HID device, waits for the response and retrieves the battery level from it.
 *
 * @param hid_device* headset HID device.
 * @return value of 7th char in the buffer, as an int.
 */
int getBatteryLevel(hid_device* headsetDevice) 
{
	wchar_t manufacturer[20];
	hid_get_manufacturer_string(headsetDevice, manufacturer, 20);
	wchar_t productName[50];
	hid_get_product_string(headsetDevice, productName, 50);

	constexpr auto WRITE_BUFFER_SIZE = 52;
	constexpr auto DATA_BUFFER_SIZE = 20;
	
	unsigned char writeBuffer[WRITE_BUFFER_SIZE] = { 0 };
	// Data buffer is max 20 bytes for the currently supported headsets.

	int batteryByteInt = 7;

	if (wcsstr(manufacturer, L"HP") != 0)
	{
		if (wcsstr(productName, L"Cloud II Core") != 0) {
			// HP Cloud II Core Wireless data
			writeBuffer[0] = 0x66;
			writeBuffer[1] = 0x89;

			batteryByteInt = 4;
		}
		else if (wcsstr(productName, L"Cloud II Wireless") != 0) {
			// HP Cloud II Wireless data
			writeBuffer[0] = 0x06;
			writeBuffer[1] = 0xff;
			writeBuffer[2] = 0xbb;
			writeBuffer[3] = 0x02;
		}
	}
	else 
	{
		// Kingston Cloud II supported but it requires some input report checking before writes.
		constexpr auto INPUT_BUFFER_SIZE = 160;

		unsigned char buffer[INPUT_BUFFER_SIZE] = { 0 };
		buffer[0] = 6; // Set the first value to the number of the report

		int ret1 = hid_get_input_report(headsetDevice, buffer, INPUT_BUFFER_SIZE);

		// Kingston Cloud II Wireless data
		writeBuffer[0] = 0x06;
		writeBuffer[2] = 0x02;
		writeBuffer[4] = 0x9a;
		writeBuffer[7] = 0x68;
		writeBuffer[8] = 0x4a;
		writeBuffer[9] = 0x8e;
		writeBuffer[10] = 0x0a;
		writeBuffer[14] = 0xbb;
		writeBuffer[15] = 0x02;
	}

	int ret = hid_write(headsetDevice, writeBuffer, WRITE_BUFFER_SIZE);

	unsigned char dataBuffer[DATA_BUFFER_SIZE] = { 0 };

	// HP Cloud II Wireless might need extra reads.
	if (wcsstr(manufacturer, L"HP") != 0 && wcsstr(productName, L"Cloud II Wireless") != 0) {
		constexpr auto MAX_READS = 5;
		int curRead = 0;
		while (dataBuffer[3] != writeBuffer[3] && curRead < MAX_READS) {
			hid_read_timeout(headsetDevice, dataBuffer, DATA_BUFFER_SIZE, 1000);
			curRead++;
		}
	}
	else {
		hid_read_timeout(headsetDevice, dataBuffer, DATA_BUFFER_SIZE, 1000);
	}

	return dataBuffer[batteryByteInt];
}

