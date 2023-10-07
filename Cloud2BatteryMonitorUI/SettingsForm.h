#pragma once

#include <iostream>
#include <string>
#include "SettingsHelper.h"

namespace Cloud2BatteryMonitorUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Windows::Forms;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for SettingsForm
	/// </summary>
	public ref class SettingsForm : public Form
	{
	public:
		SettingsForm(void)
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
		~SettingsForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ lbSettingsHigh;
	private: System::Windows::Forms::Label^ lbSettingsMid;
	private: System::Windows::Forms::Label^ lbSettingsLow;
	private: System::Windows::Forms::CheckBox^ cbStart;
	private: System::Windows::Forms::Button^ btnHigh;
	private: System::Windows::Forms::Button^ btnMed;
	private: System::Windows::Forms::Button^ btnLow;
	private: System::Windows::Forms::Button^ btnLowText;
	private: System::Windows::Forms::Button^ btnMedText;
	private: System::Windows::Forms::Button^ btnHighText;
	private: System::Windows::Forms::Button^ btnSaveSettings;
	private: System::Windows::Forms::Label^ lbBackground;
	private: System::Windows::Forms::Label^ lbText;
	private: System::Windows::Forms::Label^ lbRefresh;
	private: System::Windows::Forms::NumericUpDown^ numRefreshMinutes;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(SettingsForm::typeid));
			this->lbSettingsHigh = (gcnew System::Windows::Forms::Label());
			this->lbSettingsMid = (gcnew System::Windows::Forms::Label());
			this->lbSettingsLow = (gcnew System::Windows::Forms::Label());
			this->cbStart = (gcnew System::Windows::Forms::CheckBox());
			this->btnHigh = (gcnew System::Windows::Forms::Button());
			this->btnMed = (gcnew System::Windows::Forms::Button());
			this->btnLow = (gcnew System::Windows::Forms::Button());
			this->btnLowText = (gcnew System::Windows::Forms::Button());
			this->btnMedText = (gcnew System::Windows::Forms::Button());
			this->btnHighText = (gcnew System::Windows::Forms::Button());
			this->btnSaveSettings = (gcnew System::Windows::Forms::Button());
			this->lbBackground = (gcnew System::Windows::Forms::Label());
			this->lbText = (gcnew System::Windows::Forms::Label());
			this->lbRefresh = (gcnew System::Windows::Forms::Label());
			this->numRefreshMinutes = (gcnew System::Windows::Forms::NumericUpDown());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numRefreshMinutes))->BeginInit();
			this->SuspendLayout();
			// 
			// lbSettingsHigh
			// 
			this->lbSettingsHigh->AutoSize = true;
			this->lbSettingsHigh->Location = System::Drawing::Point(12, 35);
			this->lbSettingsHigh->Name = L"lbSettingsHigh";
			this->lbSettingsHigh->Size = System::Drawing::Size(133, 13);
			this->lbSettingsHigh->TabIndex = 0;
			this->lbSettingsHigh->Text = L"Battery level high (50-100):";
			// 
			// lbSettingsMid
			// 
			this->lbSettingsMid->AutoSize = true;
			this->lbSettingsMid->Location = System::Drawing::Point(12, 65);
			this->lbSettingsMid->Name = L"lbSettingsMid";
			this->lbSettingsMid->Size = System::Drawing::Size(143, 13);
			this->lbSettingsMid->TabIndex = 1;
			this->lbSettingsMid->Text = L"Battery level medium (20-49):";
			// 
			// lbSettingsLow
			// 
			this->lbSettingsLow->AutoSize = true;
			this->lbSettingsLow->Location = System::Drawing::Point(12, 95);
			this->lbSettingsLow->Name = L"lbSettingsLow";
			this->lbSettingsLow->Size = System::Drawing::Size(117, 13);
			this->lbSettingsLow->TabIndex = 2;
			this->lbSettingsLow->Text = L"Battery level low (0-19):";
			// 
			// cbStart
			// 
			this->cbStart->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->cbStart->AutoSize = true;
			this->cbStart->Location = System::Drawing::Point(12, 154);
			this->cbStart->Name = L"cbStart";
			this->cbStart->Size = System::Drawing::Size(139, 17);
			this->cbStart->TabIndex = 6;
			this->cbStart->Text = L"Start program at startup.";
			this->cbStart->UseVisualStyleBackColor = true;
			// 
			// btnHigh
			// 
			this->btnHigh->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->btnHigh->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->btnHigh->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnHigh->ForeColor = System::Drawing::SystemColors::ControlText;
			this->btnHigh->Location = System::Drawing::Point(165, 30);
			this->btnHigh->Name = L"btnHigh";
			this->btnHigh->Size = System::Drawing::Size(62, 23);
			this->btnHigh->TabIndex = 10;
			this->btnHigh->UseVisualStyleBackColor = true;
			this->btnHigh->Click += gcnew System::EventHandler(this, &SettingsForm::colorBtnClick);
			// 
			// btnMed
			// 
			this->btnMed->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->btnMed->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->btnMed->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnMed->Location = System::Drawing::Point(165, 60);
			this->btnMed->Name = L"btnMed";
			this->btnMed->Size = System::Drawing::Size(62, 23);
			this->btnMed->TabIndex = 11;
			this->btnMed->UseVisualStyleBackColor = true;
			this->btnMed->Click += gcnew System::EventHandler(this, &SettingsForm::colorBtnClick);
			// 
			// btnLow
			// 
			this->btnLow->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->btnLow->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->btnLow->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnLow->Location = System::Drawing::Point(165, 90);
			this->btnLow->Name = L"btnLow";
			this->btnLow->Size = System::Drawing::Size(62, 23);
			this->btnLow->TabIndex = 12;
			this->btnLow->UseVisualStyleBackColor = true;
			this->btnLow->Click += gcnew System::EventHandler(this, &SettingsForm::colorBtnClick);
			// 
			// btnLowText
			// 
			this->btnLowText->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->btnLowText->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->btnLowText->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnLowText->Location = System::Drawing::Point(241, 90);
			this->btnLowText->Name = L"btnLowText";
			this->btnLowText->Size = System::Drawing::Size(62, 23);
			this->btnLowText->TabIndex = 15;
			this->btnLowText->UseVisualStyleBackColor = true;
			this->btnLowText->Click += gcnew System::EventHandler(this, &SettingsForm::colorBtnClick);
			// 
			// btnMedText
			// 
			this->btnMedText->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->btnMedText->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->btnMedText->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnMedText->Location = System::Drawing::Point(241, 60);
			this->btnMedText->Name = L"btnMedText";
			this->btnMedText->Size = System::Drawing::Size(62, 23);
			this->btnMedText->TabIndex = 14;
			this->btnMedText->UseVisualStyleBackColor = true;
			this->btnMedText->Click += gcnew System::EventHandler(this, &SettingsForm::colorBtnClick);
			// 
			// btnHighText
			// 
			this->btnHighText->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->btnHighText->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->btnHighText->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnHighText->Location = System::Drawing::Point(241, 30);
			this->btnHighText->Name = L"btnHighText";
			this->btnHighText->Size = System::Drawing::Size(62, 23);
			this->btnHighText->TabIndex = 13;
			this->btnHighText->UseVisualStyleBackColor = true;
			this->btnHighText->Click += gcnew System::EventHandler(this, &SettingsForm::colorBtnClick);
			// 
			// btnSaveSettings
			// 
			this->btnSaveSettings->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->btnSaveSettings->BackColor = System::Drawing::Color::LightGray;
			this->btnSaveSettings->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnSaveSettings->Location = System::Drawing::Point(165, 150);
			this->btnSaveSettings->Name = L"btnSaveSettings";
			this->btnSaveSettings->Size = System::Drawing::Size(138, 23);
			this->btnSaveSettings->TabIndex = 16;
			this->btnSaveSettings->Text = L"Save";
			this->btnSaveSettings->UseVisualStyleBackColor = false;
			this->btnSaveSettings->Click += gcnew System::EventHandler(this, &SettingsForm::btnSaveSettings_Click);
			// 
			// lbBackground
			// 
			this->lbBackground->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->lbBackground->AutoSize = true;
			this->lbBackground->Location = System::Drawing::Point(162, 9);
			this->lbBackground->Name = L"lbBackground";
			this->lbBackground->Size = System::Drawing::Size(65, 13);
			this->lbBackground->TabIndex = 17;
			this->lbBackground->Text = L"Background";
			// 
			// lbText
			// 
			this->lbText->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->lbText->AutoSize = true;
			this->lbText->Location = System::Drawing::Point(238, 9);
			this->lbText->Name = L"lbText";
			this->lbText->Size = System::Drawing::Size(28, 13);
			this->lbText->TabIndex = 18;
			this->lbText->Text = L"Text";
			// 
			// lbRefresh
			// 
			this->lbRefresh->AutoSize = true;
			this->lbRefresh->Location = System::Drawing::Point(12, 125);
			this->lbRefresh->Name = L"lbRefresh";
			this->lbRefresh->Size = System::Drawing::Size(148, 13);
			this->lbRefresh->TabIndex = 19;
			this->lbRefresh->Text = L"Refresh icon every X minutes:";
			// 
			// numRefreshMinutes
			// 
			this->numRefreshMinutes->BackColor = System::Drawing::Color::LightGray;
			this->numRefreshMinutes->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->numRefreshMinutes->Location = System::Drawing::Point(241, 123);
			this->numRefreshMinutes->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 999, 0, 0, 0 });
			this->numRefreshMinutes->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numRefreshMinutes->Name = L"numRefreshMinutes";
			this->numRefreshMinutes->Size = System::Drawing::Size(62, 20);
			this->numRefreshMinutes->TabIndex = 20;
			this->numRefreshMinutes->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// SettingsForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Silver;
			this->ClientSize = System::Drawing::Size(316, 183);
			this->Controls->Add(this->numRefreshMinutes);
			this->Controls->Add(this->lbRefresh);
			this->Controls->Add(this->lbText);
			this->Controls->Add(this->lbBackground);
			this->Controls->Add(this->btnSaveSettings);
			this->Controls->Add(this->btnLowText);
			this->Controls->Add(this->btnMedText);
			this->Controls->Add(this->btnHighText);
			this->Controls->Add(this->btnLow);
			this->Controls->Add(this->btnMed);
			this->Controls->Add(this->btnHigh);
			this->Controls->Add(this->cbStart);
			this->Controls->Add(this->lbSettingsLow);
			this->Controls->Add(this->lbSettingsMid);
			this->Controls->Add(this->lbSettingsHigh);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(332, 222);
			this->MinimumSize = System::Drawing::Size(332, 222);
			this->Name = L"SettingsForm";
			this->Text = L"Settings";
			this->Load += gcnew System::EventHandler(this, &SettingsForm::SettingsForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numRefreshMinutes))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void SettingsForm_Load(System::Object^ sender, System::EventArgs^ e) {

		SettingsHelper* settingsHelper = new SettingsHelper();
		this->numRefreshMinutes->Value = settingsHelper->getRefreshMinutes();
		this->btnHigh->BackColor = settingsHelper->getColorHigh();
		this->btnHighText->BackColor = settingsHelper->getColorHighText();
		this->btnMed->BackColor = settingsHelper->getColorMed();
		this->btnMedText->BackColor = settingsHelper->getColorMedText();
		this->btnLow->BackColor = settingsHelper->getColorLow();
		this->btnLowText->BackColor = settingsHelper->getColorLowText();
		this->cbStart->Checked = settingsHelper->getAutostart();

		delete settingsHelper;
	}

	private: System::Void colorBtnClick(System::Object^ sender, System::EventArgs^ e) {
		ColorDialog^ colorDlg = gcnew ColorDialog();
		colorDlg->AllowFullOpen = true;
		colorDlg->AnyColor = true;
		colorDlg->SolidColorOnly = false;
		colorDlg->Color = Color::Red;

		if (colorDlg->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			Button^ button = (Button^)sender;
			button->BackColor = colorDlg->Color;
		}
	}

	private: System::Void btnSaveSettings_Click(System::Object^ sender, System::EventArgs^ e) {
		SettingsHelper* settingsHelper = new SettingsHelper();
		settingsHelper->setRefreshMinutes((int)this->numRefreshMinutes->Value);
		settingsHelper->setColorHigh(this->btnHigh->BackColor);
		settingsHelper->setColorHighText(this->btnHighText->BackColor);
		settingsHelper->setColorMed(this->btnMed->BackColor);
		settingsHelper->setColorMedText(this->btnMedText->BackColor);
		settingsHelper->setColorLow(this->btnLow->BackColor);
		settingsHelper->setColorLowText(this->btnLowText->BackColor);
		settingsHelper->setAutostart(this->cbStart->Checked);

		settingsHelper->saveSettings();

		delete settingsHelper;

		Close();
	}
};
}
