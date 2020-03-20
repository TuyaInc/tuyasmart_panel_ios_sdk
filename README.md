# Tuya Smart iOS Panel SDK

[中文版](README-zh.md) | [English](README.md)

---

## Features Overview

Tuya Smart iOS Panel SDK is the core container of Tuya Smart Device Control Panel, based on the Tuya Smart iOS Home SDK, it provides the interface package for loading and controlling the device control panel to speed up the application development process. It mainly includes the following functions:

- Load Device Panel (Supported hardware device type: WIFI, Unsupported: Zigbee、Mesh、BLE)
  - Sweeper Plugin (Requires additional dependencies)
  - IPC Plugin (Requires additional dependencies [IPC Panel SDK](https://github.com/TuyaInc/tuyasmart_camera_panel_ios_sdk))
- Device Panel Control (Supported Device and Group Control, Unsupported Group Manager)
- Device Alarm

## Fast Integration

### Using CocoaPods

Add the following content in file `Podfile`:

```ruby
source "https://github.com/TuyaInc/TYPublicSpecs.git"
source 'https://cdn.cocoapods.org/'

platform :ios, '9.0'

target 'your_target_name' do
   pod "TuyaSmartPanelSDK"
   # If you need the sweeper, please rely on the relevant plug-in of the sweeper
   pod "TuyaRNApi/Sweeper"
end
```

Execute command `pod update` in the project's root directory to begin integration.

For the instructions of CocoaPods, please refer to: [CocoaPods Guides](https://guides.cocoapods.org/) 

### Initialize SDK

1. Open project setting, `Target => General`, edit `Bundle Identifier` to the value from Tuya develop center.

2. Import security image to the project and rename as `t_s.bmp`, then add it into `Project Setting => Target => Build Phases => Copy Bundle Resources`.

3. Add the following to the project file `PrefixHeader.pch`, Swift project add the following to the `xxx_Bridging-Header.h` file:

   ```objc
   #import <TuyaSmartBaseKit/TuyaSmartBaseKit.h>
   #import <TuyaSmartPanelSDK/TuyaSmartPanelSDK.h>
   ```
   
4. Open file `AppDelegate.m`，and use the `App Key` and `App Secret` obtained from the development platform in the `[AppDelegate application:didFinishLaunchingWithOptions:]`method to initialize SDK:

   ObjC

   ```objc
   [[TuyaSmartSDK sharedInstance] startWithAppKey:<#your_app_key#> secretKey:<#your_secret_key#>];
   ```

   Swift

   ```swift
   TuyaSmartSDK.sharedInstance()?.start(withAppKey: <#your_app_key#>, secretKey: <#your_secret_key#>)
   ```

Now all the prepare work has been completed. You can use the sdk to develop your application now.



## Doc

Refer to details：[Tuya Smart Panel Doc - iOS SDK](https://tuyainc.github.io/tuyasmart_panel_ios_sdk_doc/en/)

## ChangeLog

[CHANGELOG.md](./CHANGELOG.md) 