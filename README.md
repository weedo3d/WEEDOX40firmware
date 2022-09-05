# WEEDO X40 Community Firmware
![image](http://www.weedo.ltd/wp-content/uploads/2021/04/970x300-ABanner1.jpg)

## Summary
This is the repository that contains the community version firmware for the WEEDO X40 3D Printer. 

The framework of the firmware is based on the Marlin 2.0.x version. 
We fixed some bugs in the dual x carriage modules.

The user interaction and network communication modules are developed by WEEDO3D.

## Hardware Version 
- X40 V1: The first mass production version. The production time is from November 2020 to June 2021.
- X40 V2: The second production version. The production batch start from July 2021.
The length in the Y-axis direction has been shortened. The Y-axis coordinate has been changed from (-2,310) to (-11,303).

## Compile requirements

- Download and install [VSCode](https://code.visualstudio.com/)
- Search and install PlatformIO IDE from store marketplace
- Search and install ST STM32 embedded platform from PIO Home
- Copy framework-arduinoststm32-maple@99.99.99 from /buildroot/lib to PlatformIO library location (user)/.platformio/packages/
- Install the USB driver from /buildroot/driver/CH341SER.ZIP

## Upload firmware

X40 uses a customized bootloader, which requires a customized download program for firmware update.  

The Windows version of the download program WEEDOIAP.exe is located in the [/buildroot/upload/WEEDOIAPV.exe](https://github.com/weedo3d/WEEDOX40firmware/blob/master/buildroot/upload/WEEDOIAPV.exe)

The macos version is available in the [/buildroot/upload/X40IAP_MacOS.zip](https://github.com/weedo3d/WEEDOX40firmware/blob/master/buildroot/upload/X40IAP_MacOS.zip)

Lanuch the WEEDOIAP.exe, open the firmware.bin file from build directory, choice the com port, then click the update.

![image](http://www.weedo.ltd/wp-content/uploads/2021/04/weedoiap.png)

X40 will restart to enter the firmware update mode. Wait for about 1 minute, the printer will automatically restart after the firmware update is completed.

![image](http://www.weedo.ltd/wp-content/uploads/2021/04/iap.jpg)



## The difference between the community version firmware and the official version firmware

The official firmware has the function of upgrading the firmware via TF card. Use the IAP function in the control menu to read the flash.wfm file on the TF card to upgrade the firmware.

The community version firmware does not support the wfm format, so it does not support firmware upgrade via TF card.


## Return to the official vesrion firmware

Use WEEDOIAP.exe to flash X40_Vxxx_Community_to_Official.bin in the /Release directory.
