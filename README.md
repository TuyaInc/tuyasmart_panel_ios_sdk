# 涂鸦智能 iOS Panel SDK

## 功能概述

涂鸦智能 iOS Panel SDK 是涂鸦智能设备控制面板的核心容器，在涂鸦智能 iOS Home SDK 的基础上，提供了设备控制面板的加载和控制的接口封装，加速应用开发过程。主要包括以下功能：

- 面板加载（加载多种设备类型，支持：WIFI ，不支持 Zigbee、Mesh、BLE）
- 设备控制（支持单设备的控制，不支持群组）
- 设备定时

## 快速集成

### 使用 CocoaPods 集成

在 `Podfile` 文件中添加以下内容：

```ruby
source "https://github.com/TuyaInc/TYPublicSpecs.git"
source 'https://cdn.cocoapods.org/'

platform :ios, '9.0'

target 'your_target_name' do
   pod "TuyaSmartPanelSDK"
end
```

然后在项目根目录下执行 `pod update` 命令，集成第三方库。

CocoaPods 的使用请参考：[CocoaPods Guides](https://guides.cocoapods.org/) 

## 集成 SDK

### 头文件导入

Objective-C 项目在需要使用的地方添加

```objective-c
#import <TuyaSmartPanelSDK/TuyaSmartPanelSDK.h>
```

Swift 请现在 `xxx_Bridging-Header.h` 桥接文件中添加以下内容

```swift
#import <TuyaSmartPanelSDK/TuyaSmartPanelSDK.h>
```

然后在项目在需要使用的地方添加

```swift
import TuyaSmartPanelSDK
```




## 开发文档

更多请参考：[涂鸦智能 iOS Panel SDK](https://tuyainc.github.io/tuyasmart_panel_ios_sdk_doc/)

## 版本更新记录

[CHANGELOG.md](./CHANGELOG.md) 