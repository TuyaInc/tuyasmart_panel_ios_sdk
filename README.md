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

## Integrated SDK

### Import Header

Add the following header in Use for Objective-C project:

```objective-c
#import <TuyaSmartPanelSDK/TuyaSmartPanelSDK.h>
```

Add the following Bridge Header in Use for Swift project: 

```swift
#import <TuyaSmartPanelSDK/TuyaSmartPanelSDK.h>
```



## Doc

Refer to details：[Tuya Smart Panel Doc - iOS SDK](https://tuyainc.github.io/tuyasmart_panel_ios_sdk_doc/en/)

## ChangeLog

[CHANGELOG.md](./CHANGELOG.md) 