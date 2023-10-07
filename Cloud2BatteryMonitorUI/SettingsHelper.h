#include <pugixml.hpp>

static const char XML_ELEM_SETTING[] = "setting";
static const char XML_ATTR_NAME[] = "name";
static const char XML_SETTINGS_FILE[] = "settings.xml";
static const char XML_NODE_SETTINGS[] = "settings";

using namespace std;
using namespace System::Drawing;

class SettingsHelper {
private:
    pugi::xml_document doc;
    pugi::xml_node settingsNode;

    void loadSettings();

public:
    SettingsHelper();

    void saveSettings();
    int getRefreshMinutes();
    void setRefreshMinutes(int);
    Color getColorHigh();
    void setColorHigh(Color);
    Color getColorHighText();
    void setColorHighText(Color);
    Color getColorMed();
    void setColorMed(Color);
    Color getColorMedText();
    void setColorMedText(Color);
    Color getColorLow();
    void setColorLow(Color);
    Color getColorLowText();
    void setColorLowText(Color);
    bool getAutostart();
    void setAutostart(bool);

};