#include <pugixml.hpp>
#include <windows.h>
#include "SettingsHelper.h"

using namespace System::Drawing;

SettingsHelper::SettingsHelper() 
{
    loadSettings();
}

void SettingsHelper::loadSettings() 
{
    doc.load_file(XML_SETTINGS_FILE);
    settingsNode = doc.child(XML_NODE_SETTINGS);
}

void SettingsHelper::saveSettings() 
{
    doc.save_file(XML_SETTINGS_FILE);

    const char APP_NAME[] = "Cloud2BatteryMonitor";
    const char REG_KEY_PATH[] = "SOFTWARE\\Microsoft\\Windows\\Currentversion\\Run";

    if (getAutostart()) 
    {
        char re[MAX_PATH];
        string FP = "\"" + string(re, GetModuleFileNameA(NULL, re, MAX_PATH)) + "\" -hidden";

        HKEY hkey = HKEY_CURRENT_USER;
        RegOpenKeyA(HKEY_CURRENT_USER, REG_KEY_PATH, &hkey);
        LONG key = RegOpenKeyExA(HKEY_CURRENT_USER, REG_KEY_PATH, 0, KEY_WRITE, &hkey);
        if (ERROR_SUCCESS == key) 
        {
            key = RegSetValueExA(hkey, APP_NAME, 0, REG_SZ, (BYTE*)FP.c_str(), strlen(FP.c_str()));
        }
        RegCloseKey(hkey);
    }
    else 
    {
        HKEY hkey = HKEY_CURRENT_USER;
        RegOpenKeyA(HKEY_CURRENT_USER, REG_KEY_PATH, &hkey);
        RegDeleteValueA(hkey, APP_NAME);
        RegCloseKey(hkey);
    }
}

int SettingsHelper::getRefreshMinutes() 
{
    return settingsNode.find_child_by_attribute(XML_ELEM_SETTING, XML_ATTR_NAME, "refreshMinutes").text().as_int();
}

void SettingsHelper::setRefreshMinutes(int refreshMinutes) 
{
    settingsNode.find_child_by_attribute(XML_ELEM_SETTING, XML_ATTR_NAME, "refreshMinutes").text().set(refreshMinutes);
}

Color SettingsHelper::getColorHigh() 
{
    int colorHighInt = settingsNode.find_child_by_attribute(XML_ELEM_SETTING, XML_ATTR_NAME, "colorHigh").text().as_int();
    return Color::FromArgb(colorHighInt);
}

void SettingsHelper::setColorHigh(Color colorHigh) 
{
    settingsNode.find_child_by_attribute(XML_ELEM_SETTING, XML_ATTR_NAME, "colorHigh").text().set(colorHigh.ToArgb());
}

Color SettingsHelper::getColorHighText() 
{
    int colorHighTextInt = settingsNode.find_child_by_attribute(XML_ELEM_SETTING, XML_ATTR_NAME, "colorHighText").text().as_int();
    return Color::FromArgb(colorHighTextInt);
}

void SettingsHelper::setColorHighText(Color colorHighText) 
{
    settingsNode.find_child_by_attribute(XML_ELEM_SETTING, XML_ATTR_NAME, "colorHighText").text().set(colorHighText.ToArgb());
}

Color SettingsHelper::getColorMed() 
{
    int colorMedInt = settingsNode.find_child_by_attribute(XML_ELEM_SETTING, XML_ATTR_NAME, "colorMed").text().as_int();
    return Color::FromArgb(colorMedInt);
}

void SettingsHelper::setColorMed(Color colorMed) 
{
    settingsNode.find_child_by_attribute(XML_ELEM_SETTING, XML_ATTR_NAME, "colorMed").text().set(colorMed.ToArgb());
}

Color SettingsHelper::getColorMedText() 
{
    int colorMedTextInt = settingsNode.find_child_by_attribute(XML_ELEM_SETTING, XML_ATTR_NAME, "colorMedText").text().as_int();
    return Color::FromArgb(colorMedTextInt);
}

void SettingsHelper::setColorMedText(Color colorMedText) 
{
    settingsNode.find_child_by_attribute(XML_ELEM_SETTING, XML_ATTR_NAME, "colorMedText").text().set(colorMedText.ToArgb());
}

Color SettingsHelper::getColorLow() 
{
    int colorLowInt = settingsNode.find_child_by_attribute(XML_ELEM_SETTING, XML_ATTR_NAME, "colorLow").text().as_int();
    return Color::FromArgb(colorLowInt);
}

void SettingsHelper::setColorLow(Color colorLow) 
{
    settingsNode.find_child_by_attribute(XML_ELEM_SETTING, XML_ATTR_NAME, "colorLow").text().set(colorLow.ToArgb());
}

Color SettingsHelper::getColorLowText() 
{
    int colorLowTextInt = settingsNode.find_child_by_attribute(XML_ELEM_SETTING, XML_ATTR_NAME, "colorLowText").text().as_int();
    return Color::FromArgb(colorLowTextInt);
}

void SettingsHelper::setColorLowText(Color colorLowText) 
{
    settingsNode.find_child_by_attribute(XML_ELEM_SETTING, XML_ATTR_NAME, "colorLowText").text().set(colorLowText.ToArgb());
}

bool SettingsHelper::getAutostart() 
{
    return settingsNode.find_child_by_attribute(XML_ELEM_SETTING, XML_ATTR_NAME, "autostart").text().as_bool();
}

void SettingsHelper::setAutostart(bool autostart) 
{
    settingsNode.find_child_by_attribute(XML_ELEM_SETTING, XML_ATTR_NAME, "autostart").text().set(autostart);
}