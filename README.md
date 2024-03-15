
# HyperX Cloud II Wireless Headset Battery Monitor for Windows(x64)

The aim of the project is simple, to create a somewhat customizable battery monitor for the Cloud II wireless headset. The main feature of the app is a system tray icon displaying the current battery percentage.

## Supported headsets

**Kingston HyperX Cloud II Wireless**

**HP HyperX Cloud II Wireless**

**HP HyperX Cloud II Core Wireless**

**HP HyperX Cloud Alpha Wireless**

If you would like a different Cloud Wireless headset supported, feel free to create an issue here on Github but beware that I will ask you for assistance (eg. Wireshark USB traffic recordings).

## How to install

You can download [release v1.4 here](https://github.com/auto94/HyperX-Cloud-2-Battery-Monitor/releases/download/Release_v1.4/Cloud2BatteryMonitor_v1.4.zip) or select the latest release on the right side of this Github repository and download the zip. After the download is complete, extract the zip and run "Cloud2BatteryMonitorUI.exe". 

No installation is necessary.

## About the app

The app consists of two forms/screens and a system tray icon.

**Example battery icon:**

![icon_example](https://github.com/auto94/Cloud2-Battery-Monitor/assets/36648280/9ee9dc07-c16e-4f36-9f9f-457e2af8634f)

**Main screen:**

![main_screen](https://github.com/auto94/Cloud2-Battery-Monitor/assets/36648280/3546df9f-008a-416b-8d59-2f7526bdea86)


**Settings screen:**

![settings_form](https://github.com/auto94/Cloud2-Battery-Monitor/assets/36648280/bb00d0a5-60b1-4df8-9ab7-e94d2838325c)

## Default settings

|Setting| Default value | Type| Explanation|
|--|--|--|--|
| autostart | false | bool (true/false) | Adds app to start at boot registry
| colorHigh| -16776961 (darkish blue)| int (int of color argb) | System tray icon background (50-100% battery)
| colorHighText| -1 (white)| int (int of color argb) | System tray icon text (50-100% battery)
| colorMed| -8388480 (dark magenta)| int (int of color argb) | System tray icon background (20-49% battery)
| colorMedText| -1 (white)| int (int of color argb) | System tray icon text (20-49% battery)
| colorLow| -3801088 (dark red)| int (int of color argb) | System tray icon background (0-19% battery)
| colorLowText| -1 (white)| int (int of color argb) | System tray icon text (0-19%) battery
| refreshMinutes| 5| positive int | System tray icon refresh timer length

If you accidentally delete the settings file then just download the one in this repository ([settings.xml](Cloud2BatteryMonitorUI/settings.xml)) and place it in the folder which contains your exe.

## FAQ

**Q: The app won't automatically start at boot.**

A: Try running the exe as Administrator and make sure the exe is located at the same location as it was when you enabled auto start in the options.

**Q: Why did you choose this language/framework?**

A: I am mostly familiar with Java/Python but I wanted to try something new and since this was always a Windows-only project, I just downloaded Visual Studio Community 2022, installed all the add-ons and chose a random template. 
The end result is this frankensteinian mess of C# and C++ and while it is a bit wonky, it works and I had fun making it. 

**Q: How did you do it?**

A: Basically I used wireshark to find the data and responses which had the battery level in it and then just reproduced them using HID API. I'll add a longer tutorial/walkthrough at some point in the future.

## Tested on
|Manufacturer| Product name | Release(s)| OS(s)|
|--|--|--|--|
| Kingston | HyperX Cloud II Wireless| v1.0-1.4 | Windows 10
| HP | HyperX Cloud II Wireless | v1.4 | Windows 10, Windows 11
| HP | HyperX Cloud II Core Wireless | v1.4 | Windows 10


## Special thanks

[libusb/hidapi](https://github.com/libusb/hidapi)

[zeux/pugixml](https://github.com/zeux/pugixml)

## License

**MIT license.**
See the file [LICENSE.txt](LICENSE.txt) for more information.

## About

This program is hosted by Github and maintained by me (auto94).
