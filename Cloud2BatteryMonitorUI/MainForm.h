#pragma once

#include <iostream>
#include <hidapi.h>
#include <stdlib.h>
#include "SettingsForm.h"

constexpr auto HEADSET_VENDOR_ID = 2385;
constexpr auto HEADSET_PRODUCT_ID = 5912;
constexpr auto HEADSET_USAGE_PAGE = 65299;
constexpr auto HEADSET_VENDOR_ID_NEW = 1008;
constexpr auto HEADSET_PRODUCT_ID_NEW = 395;

hid_device_info* getHeadsetDeviceInfo();
int getBatteryLevel(hid_device*);

bool isTimerSet = false;


namespace Cloud2BatteryMonitorUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ lbStatus;
	protected:
	private: System::Windows::Forms::Label^ lbHeadsetInfoManu;
	private: System::Windows::Forms::Label^ lbBatteryLevel;
	private: System::Windows::Forms::Label^ lbHeadsetInfoProd;
	private: System::Windows::Forms::NotifyIcon^ iconSystemTray;
	private: System::Windows::Forms::Button^ btnRefresh;
	private: System::Windows::Forms::ContextMenuStrip^ contextMenuNotifyIcon;
	private: System::Windows::Forms::ToolStripMenuItem^ itemSettings;

	private: System::Windows::Forms::ToolStripMenuItem^ itemExit;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ menuTitleSettings;
	private: System::Windows::Forms::ToolStripMenuItem^ menuTitleAbout;
	private: System::Windows::Forms::ToolStripMenuItem^ itemOpen;

	private: System::ComponentModel::IContainer^ components;
	protected:
	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			this->lbStatus = (gcnew System::Windows::Forms::Label());
			this->lbHeadsetInfoManu = (gcnew System::Windows::Forms::Label());
			this->lbBatteryLevel = (gcnew System::Windows::Forms::Label());
			this->lbHeadsetInfoProd = (gcnew System::Windows::Forms::Label());
			this->iconSystemTray = (gcnew System::Windows::Forms::NotifyIcon(this->components));
			this->contextMenuNotifyIcon = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->itemSettings = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->itemExit = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->btnRefresh = (gcnew System::Windows::Forms::Button());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->menuTitleSettings = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuTitleAbout = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->itemOpen = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->contextMenuNotifyIcon->SuspendLayout();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// lbStatus
			// 
			this->lbStatus->AutoSize = true;
			this->lbStatus->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbStatus->Location = System::Drawing::Point(12, 32);
			this->lbStatus->Name = L"lbStatus";
			this->lbStatus->Size = System::Drawing::Size(146, 18);
			this->lbStatus->TabIndex = 0;
			this->lbStatus->Text = L"No headset found.";
			// 
			// lbHeadsetInfoManu
			// 
			this->lbHeadsetInfoManu->AutoSize = true;
			this->lbHeadsetInfoManu->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lbHeadsetInfoManu->Location = System::Drawing::Point(12, 59);
			this->lbHeadsetInfoManu->Name = L"lbHeadsetInfoManu";
			this->lbHeadsetInfoManu->Size = System::Drawing::Size(91, 18);
			this->lbHeadsetInfoManu->TabIndex = 4;
			this->lbHeadsetInfoManu->Text = L"Headset info";
			this->lbHeadsetInfoManu->Visible = false;
			// 
			// lbBatteryLevel
			// 
			this->lbBatteryLevel->AutoSize = true;
			this->lbBatteryLevel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbBatteryLevel->Location = System::Drawing::Point(12, 104);
			this->lbBatteryLevel->Name = L"lbBatteryLevel";
			this->lbBatteryLevel->Size = System::Drawing::Size(91, 18);
			this->lbBatteryLevel->TabIndex = 5;
			this->lbBatteryLevel->Text = L"Battery level:";
			this->lbBatteryLevel->Visible = false;
			// 
			// lbHeadsetInfoProd
			// 
			this->lbHeadsetInfoProd->AutoSize = true;
			this->lbHeadsetInfoProd->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lbHeadsetInfoProd->Location = System::Drawing::Point(12, 77);
			this->lbHeadsetInfoProd->Name = L"lbHeadsetInfoProd";
			this->lbHeadsetInfoProd->Size = System::Drawing::Size(91, 18);
			this->lbHeadsetInfoProd->TabIndex = 7;
			this->lbHeadsetInfoProd->Text = L"Headset info";
			this->lbHeadsetInfoProd->Visible = false;
			// 
			// iconSystemTray
			// 
			this->iconSystemTray->ContextMenuStrip = this->contextMenuNotifyIcon;
			this->iconSystemTray->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"iconSystemTray.Icon")));
			this->iconSystemTray->Text = L"Battery monitor";
			this->iconSystemTray->Visible = true;
			this->iconSystemTray->MouseDoubleClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::TrayIcon_DoubleClick);
			// 
			// contextMenuNotifyIcon
			// 
			this->contextMenuNotifyIcon->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->itemOpen,
				this->itemSettings, 
				this->itemExit
			});
			this->contextMenuNotifyIcon->Name = L"contextMenuStrip1";
			this->contextMenuNotifyIcon->Size = System::Drawing::Size(181, 92);
			// 
			// itemSettings
			// 
			this->itemSettings->Name = L"itemSettings";
			this->itemSettings->Size = System::Drawing::Size(180, 22);
			this->itemSettings->Text = L"Settings";
			this->itemSettings->Click += gcnew System::EventHandler(this, &MainForm::ItemSettings_Click);
			// 
			// itemExit
			// 
			this->itemExit->Name = L"itemExit";
			this->itemExit->Size = System::Drawing::Size(180, 22);
			this->itemExit->Text = L"Exit";
			this->itemExit->Click += gcnew System::EventHandler(this, &MainForm::ItemExit_Click);
			// 
			// btnRefresh
			// 
			this->btnRefresh->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->btnRefresh->BackColor = System::Drawing::Color::DarkGray;
			this->btnRefresh->FlatAppearance->BorderColor = System::Drawing::Color::DimGray;
			this->btnRefresh->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnRefresh->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnRefresh->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnRefresh.Image")));
			this->btnRefresh->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnRefresh->Location = System::Drawing::Point(258, 29);
			this->btnRefresh->Name = L"btnRefresh";
			this->btnRefresh->Size = System::Drawing::Size(83, 27);
			this->btnRefresh->TabIndex = 8;
			this->btnRefresh->Text = L"Refresh";
			this->btnRefresh->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->btnRefresh->UseVisualStyleBackColor = false;
			this->btnRefresh->Click += gcnew System::EventHandler(this, &MainForm::BtnRefresh_Click);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->menuTitleSettings,
					this->menuTitleAbout
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(353, 24);
			this->menuStrip1->TabIndex = 9;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// menuTitleSettings
			// 
			this->menuTitleSettings->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->menuTitleSettings->Name = L"menuTitleSettings";
			this->menuTitleSettings->Size = System::Drawing::Size(61, 20);
			this->menuTitleSettings->Text = L"Settings";
			this->menuTitleSettings->Click += gcnew System::EventHandler(this, &MainForm::MenuTitleSettings_Click);
			// 
			// menuTitleAbout
			// 
			this->menuTitleAbout->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->menuTitleAbout->Name = L"menuTitleAbout";
			this->menuTitleAbout->Size = System::Drawing::Size(52, 20);
			this->menuTitleAbout->Text = L"About";
			this->menuTitleAbout->Click += gcnew System::EventHandler(this, &MainForm::MenuTitleAbout_Click);
			// 
			// itemOpen
			// 
			this->itemOpen->Name = L"itemOpen";
			this->itemOpen->Size = System::Drawing::Size(180, 22);
			this->itemOpen->Text = L"Open";
			this->itemOpen->Click += gcnew System::EventHandler(this, &MainForm::ItemOpen_Click);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Silver;
			this->ClientSize = System::Drawing::Size(353, 137);
			this->Controls->Add(this->menuStrip1);
			this->Controls->Add(this->btnRefresh);
			this->Controls->Add(this->lbHeadsetInfoProd);
			this->Controls->Add(this->lbBatteryLevel);
			this->Controls->Add(this->lbHeadsetInfoManu);
			this->Controls->Add(this->lbStatus);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip1;
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(369, 176);
			this->MinimumSize = System::Drawing::Size(369, 176);
			this->Name = L"MainForm";
			this->Text = L"HyperX Cloud II Battery Monitor";
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->Shown += gcnew System::EventHandler(this, &MainForm::Form_Shown);
			this->Resize += gcnew System::EventHandler(this, &MainForm::MainForm_Resize);
			this->contextMenuNotifyIcon->ResumeLayout(false);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void MainForm_Load(System::Object^ sender, System::EventArgs^ e) {
		struct hid_device_info* cloud2DeviceInfo = getHeadsetDeviceInfo();

		if (cloud2DeviceInfo != NULL)
		{
			hid_device* headsetDevice = hid_open_path(cloud2DeviceInfo->path);

			if (headsetDevice != NULL) {
				int batteryLevel = getBatteryLevel(headsetDevice);

				// If the app is minized, only refresh the icon.
				if (this->WindowState != FormWindowState::Minimized) {
					wchar_t manufacturer[20];
					hid_get_manufacturer_string(headsetDevice, manufacturer, 20);
					wchar_t productName[50];
					hid_get_product_string(headsetDevice, productName, 50);

					const wchar_t* const pManuStr = manufacturer;
					System::String^ const strManu = gcnew System::String(pManuStr);
					this->lbHeadsetInfoManu->Visible = true;
					this->lbHeadsetInfoManu->Text = strManu;

					const wchar_t* const pProdStr = productName;
					System::String^ const strProd = gcnew System::String(pProdStr);
					this->lbHeadsetInfoProd->Visible = true;
					this->lbHeadsetInfoProd->Text = strProd;

					// If battery level returned is 0 => headset is turned off but USB is in PC.
					if (batteryLevel == 0) {
						this->lbStatus->Text = "Headset found but not active.";
						this->lbBatteryLevel->Visible = false;
					}
					else {
						this->btnRefresh->Visible = false;
						this->lbStatus->Text = "Headset found.";
						this->lbBatteryLevel->Visible = true;
						this->lbBatteryLevel->Text = "Battery level: " + batteryLevel + " %";
					}
				}

				System::String^ batStr2 = gcnew System::String(to_string(batteryLevel).c_str());
				RefreshTrayIcon(batStr2);
			}
			else {
				this->iconSystemTray->Text = "Battery level N/A";
				this->iconSystemTray->Icon = System::Drawing::Icon::ExtractAssociatedIcon("icons\\headset_icon_light.ico");
				this->lbStatus->Text = "Could not connect to headset.";
				this->btnRefresh->Visible = true;
			}

			hid_close(headsetDevice);
		}
		else {
			this->iconSystemTray->Text = "Battery level N/A";
			this->iconSystemTray->Icon = System::Drawing::Icon::ExtractAssociatedIcon("icons\\headset_icon_light.ico");
			this->lbStatus->Text = "No headset device detected.";
			this->btnRefresh->Visible = true;
		}

		if (isTimerSet == false) {
			// Prep and start the refresh timer.
			SettingsHelper* settingsHelper = new SettingsHelper();
			System::Windows::Forms::Timer^ timerRefresh = gcnew System::Windows::Forms::Timer();
			timerRefresh->Interval = (60 * 1000 * settingsHelper->getRefreshMinutes());
			timerRefresh->Tick += gcnew EventHandler(this, &MainForm::MainForm_Load);
			timerRefresh->Start();

			delete settingsHelper;

			MainForm::FormClosing += gcnew FormClosingEventHandler(this, &MainForm::MainForm_Closing);
			isTimerSet = true;
		}
	}

	private: System::Void Form_Shown(System::Object^ sender, System::EventArgs^ e)
	{
		System::Array^ args = Environment::GetCommandLineArgs();
		if (args->Length > 1) {
			// For application silent start (auto start)
			if (String::Equals(args->GetValue(1), "-hidden")) {
			this->WindowState = FormWindowState::Minimized;
			this->Hide();
			}
		}
	}

	private: System::Void TrayIcon_DoubleClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		// Opens the application
		this->MainForm_Load(sender, e);
		Show();
		this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
	}

	private: System::Void MainForm_Closing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e)
	{
		// Remove the system tray icon (otherwise it remaing visible until mouse hover over).
		this->iconSystemTray->Visible = false;
	}

	private: System::Void MainForm_Resize(System::Object^ sender, System::EventArgs^ e)
	{
		// When minimized, hide app from taskbar.
		if (this->WindowState == System::Windows::Forms::FormWindowState::Minimized) {
			Hide();
		}
	}

	private: System::Void RefreshTrayIcon(System::String^ batteryLevel)
	{
		int battLvl = System::Int32::Parse(batteryLevel);
		System::Drawing::Font^ iconFont;
		if (battLvl == 100) {
			iconFont = gcnew System::Drawing::Font("Tahoma", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Pixel);
		}
		else if (battLvl < 10) {
			iconFont = gcnew System::Drawing::Font("Tahoma", 13, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Pixel);
		}
		else {
			iconFont = gcnew System::Drawing::Font("Tahoma", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Pixel);
		}

		System::Drawing::Brush^ iconBrush = gcnew System::Drawing::SolidBrush(System::Drawing::Color::White);
		System::Drawing::Bitmap^ textBitmap = gcnew System::Drawing::Bitmap(16, 16);
		System::Drawing::Graphics^ iconGraphics;
		iconGraphics = iconGraphics->FromImage(textBitmap);

		System::IntPtr ptrIcon;
		SettingsHelper* settingsHelper = new SettingsHelper();

		if (battLvl > 49) {
			iconBrush = gcnew System::Drawing::SolidBrush(settingsHelper->getColorHighText());
			iconGraphics->Clear(settingsHelper->getColorHigh());
		}
		else if (battLvl > 19) {
			iconBrush = gcnew System::Drawing::SolidBrush(settingsHelper->getColorMedText());
			iconGraphics->Clear(settingsHelper->getColorMed());
		}
		else {
			iconBrush = gcnew System::Drawing::SolidBrush(settingsHelper->getColorLowText());
			iconGraphics->Clear(settingsHelper->getColorLow());
		}

		iconGraphics->TextRenderingHint = System::Drawing::Text::TextRenderingHint::SingleBitPerPixelGridFit;
		iconGraphics->DrawString(batteryLevel, iconFont, iconBrush, 0, 0);

		ptrIcon = (textBitmap->GetHicon());
		if (battLvl > 0) {
			this->iconSystemTray->Icon = System::Drawing::Icon::FromHandle(ptrIcon);
			this->iconSystemTray->Text = "Battery level: " + batteryLevel + " %";
		}
		else {
			this->iconSystemTray->Icon = System::Drawing::Icon::ExtractAssociatedIcon("icons\\headset_icon_light.ico");
			this->iconSystemTray->Text = "Battery level N/A";
		}

		delete iconBrush;
		delete textBitmap;
		delete iconFont;
		delete iconGraphics;
		delete settingsHelper;
	}

	private: System::Void BtnRefresh_Click(System::Object^ sender, System::EventArgs^ e) {
		//Refresh UI/Search for headset
		MainForm_Load(sender, e);
	}

	private: System::Void ItemExit_Click(System::Object^ sender, System::EventArgs^ e) {
		this->iconSystemTray->Visible = false;
		System::Environment::Exit(1);
	}

	private: System::Void ItemSettings_Click(System::Object^ sender, System::EventArgs^ e) {
		SettingsForm^ SettingsForm1 = gcnew SettingsForm();
		SettingsForm1->ShowDialog();
		delete SettingsForm1;
		MainForm_Load(gcnew System::Object(), gcnew System::EventArgs());
	}

	private: System::Void ItemOpen_Click(System::Object^ sender, System::EventArgs^ e) {
		Show();
		this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
	}

	private: System::Void MenuTitleSettings_Click(System::Object^ sender, System::EventArgs^ e) {
		SettingsForm^ SettingsForm1 = gcnew SettingsForm();
		SettingsForm1->ShowDialog();
		delete SettingsForm1;
		MainForm_Load(gcnew System::Object(), gcnew System::EventArgs());
	}

	private: System::Void MenuTitleAbout_Click(System::Object^ sendar, System::EventArgs^ e) {
		system("start https://github.com/auto94/Cloud2-Battery-Monitor");
	}
};
}
