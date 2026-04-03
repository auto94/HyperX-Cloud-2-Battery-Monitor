#include "MainForm.h"

using namespace System;
using namespace System::Windows::Forms;

void main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Environment::CurrentDirectory = IO::Path::GetDirectoryName(Application::ExecutablePath);
	Cloud2BatteryMonitorUI::MainForm form;
	Application::Run(% form);
}

/**
 * Enumerates HID devices and returns the HID device path according to logic
 *
 * @return string of the device path with the correct vendor/product ID and the highest usage / specific condition (like in iii 3s).
 */
std::string getHeadsetDevicePath()
{
	struct hid_device_info* devices = NULL;
	int id_index = 0;
	int num_supported_devices = sizeof(VENDORS_ARRAY) / sizeof(VENDORS_ARRAY[0]);

	// Loop through the supported device vendor and product IDs until we find a device.
	while (devices == NULL && id_index < num_supported_devices) {
		devices = hid_enumerate((unsigned short)VENDORS_ARRAY[id_index], (unsigned short)PRODUCTS_ARRAY[id_index]);
		id_index++;
	}

	if (devices == NULL) {
		return ""; // Nothing found
	}

	std::string foundPath = "";

	// Special case for hyperx cloud iii S
	// the 'highest usage' method used below is not applicable here
	for (struct hid_device_info* current = devices; current != nullptr && current->vendor_id == HEADSET_VENDOR_ID_HP && current->product_id == HEADSET_PRODUCT_ID_HP_CLOUD_III_S; current = current->next)
	{
		//looks like the correct condition is usage_page 448 and usage 1 combination
		if (current->usage_page == 448 && current->usage == 1)
		{
			foundPath = current->path; // Copy the path
			hid_free_enumeration(devices); // FREE THE MEMORY
			return foundPath;              // Return early
		}
	}

	// Special case for HyperX Cloud III Wireless
	// the 'highest usage' method used below is not applicable here either
	for (struct hid_device_info* current = devices; current != nullptr && current->vendor_id == HEADSET_VENDOR_ID_HP && (current->product_id == HEADSET_PRODUCT_ID_HP_CLOUD_III_REV4106 || current->product_id == HEADSET_PRODUCT_ID_HP_CLOUD_III_REV4109); current = current->next)
	{
		// From log: the correct interface is usage_page 65299 and usage 1
		if (current->usage_page == 65299 && current->usage == 1)
		{
			foundPath = current->path;   // Copy the path
			hid_free_enumeration(devices); // FREE THE MEMORY
			return foundPath;            // Return early
		}
	}

	int highest_usage = 0; //I think the highest usage device is the one that answers with battery level
	int highest_usage_page = 0; //If all devices have the same usage, use the one with the highest usage page

	for (struct hid_device_info* current = devices; current != nullptr; current = current->next)
	{
		if (current->usage > highest_usage)
		{
			highest_usage = current->usage;
			highest_usage_page = current->usage_page;
			foundPath = current->path; // Keep track of the path
		}
		else if (current->usage == highest_usage && current->usage_page >= highest_usage_page)
		{
			highest_usage_page = current->usage_page;
			foundPath = current->path; // Keep track of the path
		}
	}

	// FREE THE MEMORY before returning
	hid_free_enumeration(devices);

	return foundPath;
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
		else if (wcsstr(productName, L"Cloud II Wireless") != 0 || wcsstr(productName, L"Cloud Stinger 2 Wireless") != 0) {
			// HP Cloud II Wireless data = HP Cloud Stinger 2 Wireless data
			writeBuffer[0] = 0x06;
			writeBuffer[1] = 0xff;
			writeBuffer[2] = 0xbb;
			writeBuffer[3] = 0x02;
		}
		else if (wcsstr(productName, L"Cloud Alpha Wireless") != 0) {
			// HP Cloud Alpha Wireless data
			writeBuffer[0] = 0x21;
			writeBuffer[1] = 0xbb;
			writeBuffer[2] = 0x0b;

			batteryByteInt = 3;
		}
		else if (wcsstr(productName, L"Cloud III S Wireless") != 0) {
			// HP Cloud III S Wireless data
			writeBuffer[0] = 0x0c;
			writeBuffer[1] = 0x02;
			writeBuffer[2] = 0x03;
			writeBuffer[3] = 0x01;
			writeBuffer[4] = 0x00;
			writeBuffer[5] = 0x06;

			batteryByteInt = 6;
		}
		else if (wcsstr(productName, L"Cloud III Wireless") != 0) {
			// HP Cloud III Wireless data
			writeBuffer[0] = 0x66;
			writeBuffer[1] = 0x89;

			batteryByteInt = 4;
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
	const wchar_t* err = hid_error(headsetDevice);
	unsigned char dataBuffer[DATA_BUFFER_SIZE] = { 0 };

	hid_read_timeout(headsetDevice, dataBuffer, DATA_BUFFER_SIZE, 1000);

	//verify the battery level is not more then 100, as Cloud III S returns 0xff (255) at off state
	unsigned char battery = dataBuffer[batteryByteInt];
	if (battery > 100)
		return 0;

	return battery;
}

