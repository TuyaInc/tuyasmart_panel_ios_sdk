# 涂鸦智能 iOS Panel SDK

[中文版](README-zh.md) | [English](README.md)

---

## 功能概述

涂鸦智能 iOS Panel SDK 是涂鸦智能设备控制面板的核心容器，在涂鸦智能 iOS Home SDK 的基础上，提供了设备控制面板的加载和控制的接口封装，加速应用开发过程。主要包括以下功能：

- 面板加载（加载多种设备类型，支持：WIFI ，不支持 Zigbee、Mesh、BLE）
  - 扫地机 (需单独依赖组件)
  - IPC (需单独依赖 [IPC Panel SDK](https://github.com/TuyaInc/tuyasmart_camera_panel_ios_sdk))
- 设备控制（支持设备和群组面板的控制，不支持群组管理）
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
   # 若需要扫地机功能，请依赖扫地机相关插件
   pod "TuyaRNApi/Sweeper"
end
```

然后在项目根目录下执行 `pod update` 命令，集成第三方库。

CocoaPods 的使用请参考：[CocoaPods Guides](https://guides.cocoapods.org/) 

### 初始化 SDK

1. 打开项目设置，Target => General，修改`Bundle Identifier`为涂鸦开发者平台上注册的 App 对应的 iOS 包名。

2. 将上面[准备工作](https://tuyainc.github.io/tuyasmart_home_ios_sdk_doc/zh-hans/resource/Preparation.html)中下载的安全图片导入到工程根目录，重命名为`t_s.bmp`，并加入「项目设置 => Target => Build Phases => Copy Bundle Resources」中。

3. 在项目的`PrefixHeader.pch`文件添加以下内容（Swift 项目可以添加在`xxx_Bridging-Header.h`桥接文件中）：

   ```objc
   #import <TuyaSmartBaseKit/TuyaSmartBaseKit.h>
   #import <TuyaSmartPanelSDK/TuyaSmartPanelSDK.h>
   ```

4. 打开`AppDelegate.m`文件，在`[AppDelegate application:didFinishLaunchingWithOptions:]`方法中，使用在涂鸦开发者平台上，App 对应的 `App Key`，`App Secret` 初始化SDK：

   ObjC

   ```objc
   [[TuyaSmartSDK sharedInstance] startWithAppKey:<#your_app_key#> secretKey:<#your_secret_key#>];
   ```

   Swift

   ```swift
   TuyaSmartSDK.sharedInstance()?.start(withAppKey: <#your_app_key#>, secretKey: <#your_secret_key#>)
   ```

至此，涂鸦智能 App SDK 已经成功激活，可以开始 App 开发了。




## 开发文档

更多请参考：[涂鸦智能文档 - iOS SDK](https://tuyainc.github.io/tuyasmart_panel_ios_sdk_doc/)

## 版本更新记录

[CHANGELOG.md](./CHANGELOG.md) 

