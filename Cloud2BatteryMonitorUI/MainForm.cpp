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
	struct hid_device_info* devices = hid_enumerate((unsigned short)HEADSET_VENDOR_ID, (unsigned short)HEADSET_PRODUCT_ID);

	// If no devices found, check for the newer vendor/product ID.
	if (devices == NULL) 
	{
		devices = hid_enumerate((unsigned short)HEADSET_VENDOR_ID_NEW, (unsigned short)HEADSET_PRODUCT_ID_NEW);
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
int getBatteryLevel (hid_device* headsetDevice) 
{
	constexpr auto INPUT_BUFFER_SIZE = 160;

	unsigned char buffer[INPUT_BUFFER_SIZE] = { 0 };
	buffer[0] = 6; // Set the first value to the number of the report

	int ret1 = hid_get_input_report(headsetDevice, buffer, INPUT_BUFFER_SIZE);

	constexpr auto WRITE_BUFFER_SIZE = 20;
	unsigned char writeBuffer[WRITE_BUFFER_SIZE] = { 0 };
	writeBuffer[0] = 0x06;
	writeBuffer[2] = 0x02;
	writeBuffer[4] = 0x9a;
	writeBuffer[7] = 0x68;
	writeBuffer[8] = 0x4a;
	writeBuffer[9] = 0x8e;
	writeBuffer[10] = 0x0a;
	writeBuffer[14] = 0xbb;
	writeBuffer[15] = 0x02;

	hid_write(headsetDevice, writeBuffer, WRITE_BUFFER_SIZE);

	constexpr auto DATA_BUFFER_SIZE = 12;
	unsigned char dataBuffer[DATA_BUFFER_SIZE] = { 0 };
	unsigned char dataBufferCmp[DATA_BUFFER_SIZE] = { 0 };

	hid_read_timeout(headsetDevice, dataBuffer, DATA_BUFFER_SIZE, 1000);

	return dataBuffer[7];
}

