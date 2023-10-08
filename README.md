# HyperX Cloud II Wireless Headset Battery Monitor for Windows(x64)

The aim of the project is simple, to create a somewhat customizable battery monitor for the Cloud II wireless headset. The main feature of the app is a system tray icon displaying the current battery percentage.

## About the app

The app consists of two forms/screens and a system tray icon.

**Example battery icon:**

![icon_example](https://github.com/auto94/Cloud2-Battery-Monitor/assets/36648280/9ee9dc07-c16e-4f36-9f9f-457e2af8634f)

**Main screen:**

![main_screen](https://github.com/auto94/Cloud2-Battery-Monitor/assets/36648280/3546df9f-008a-416b-8d59-2f7526bdea86)


**Settings screen:**

![settings_form](https://github.com/auto94/Cloud2-Battery-Monitor/assets/36648280/bb00d0a5-60b1-4df8-9ab7-e94d2838325c)


## How to install

I suggest you click the latest available release on the right side of this screen and download Cloud2-Battery-Monitor_v1.zip. 
Then extract the zip and run the file "Cloud2BatteryMonitorUI.exe".

No installation is necessary.

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

A: Try running the exe as Administrator.

**Q: Why did you choose this language/framework?**

A: I am mostly familiar with Java/Python but I wanted to try something new and since this was always a Windows-only project, I just downloaded Visual Studio Community 2022, installed all the add-ons and chose a random template. 
The end result is this frankensteinian mess of C# and C++ and while it is a bit wonky, it works and I had fun making it. 

**Q: Why did you do it this way or that way?**

I don't know man, this is literally the first thing I've made in either C++ or C#, I don't know anything about either.

**Q: Why doesn't the app also do X and Y?**

A: I didn't think it needed anything else. If you do, feel free to either add it yourself or open an issue with a feature request. If I agree with the request, I'll try to find the time and implement it.

**Q: How did you do it?**

A: Basically I used wireshark to find the data and responses which had the battery level in it and then just reproduced them using HID API. I'll add a longer tutorial/walkthrough at some point in the future.

## Tested on

I only tested this on my own HyperX Cloud II Headset and Windows 10. It is a few years old and so it still uses the old Kingston vendor ID. 

## Special thanks

[libusb/hidapi](https://github.com/libusb/hidapi)

[zeux/pugixml](https://github.com/zeux/pugixml)

## License

**MIT license.**
See the file [LICENSE.txt](LICENSE.txt) for more information.

## About

This program is hosted by Github and maintained by me (auto94).
