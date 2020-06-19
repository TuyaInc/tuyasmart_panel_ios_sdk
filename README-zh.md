# 涂鸦智能 iOS 设备控制业务包

## [迁移指南](Upgrading-zh.md)

[中文版](README-zh.md) | [English](README.md)

---

## 功能概述

涂鸦智能 iOS 设备控制业务包是涂鸦智能设备控制面板的核心容器，在涂鸦智能 iOS Home SDK 的基础上，提供了设备控制面板的加载和控制的接口封装，加速应用开发过程。主要包括以下功能：

- 面板加载（加载多种设备类型，支持：WIFI、ZigBee、Mesh、BLE）
- 设备控制（支持单设备和群组的控制，不支持群组管理）
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

1. 打开项目设置，Target => General，修改 `Bundle Identifier` 为涂鸦开发者平台对应的 iOS 包名
2. 将[准备工作](https://tuyainc.github.io/tuyasmart_home_ios_sdk_doc/zh-hans/resource/Preparation.html)中下载的安全图片导入到工程根目录，重命名为 `t_s.bmp`，并加入「项目设置 => Target => Build Phases => Copy Bundle Resources」中。
3. 在项目的`PrefixHeader.pch`文件添加以下内容：

```objc
#import <TuyaSmartBaseKit/TuyaSmartBaseKit.h>
#import <TuyaSmartPanelSDK/TuyaSmartPanelSDK.h>
```

Swift 项目可以添加在 `xxx_Bridging-Header.h` 桥接文件中添加以下内容

```
#import <TuyaSmartBaseKit/TuyaSmartBaseKit.h>
#import <TuyaSmartPanelSDK/TuyaSmartPanelSDK.h>
```

1. 打开`AppDelegate.m`文件，在`[AppDelegate application:didFinishLaunchingWithOptions:]`方法中初始化SDK：

**接口说明**

初始化 SDK

```objc
- (void)startWithAppKey:(NSString *)appKey secretKey:(NSString *)secretKey;
```

**参数说明**

| **参数**  | **说明**    |
| --------- | ----------- |
| appKey    | App key     |
| secretKey | App 密钥key |

**示例代码**

Objc:

```objc
[[TuyaSmartSDK sharedInstance] startWithAppKey:<#your_app_key#> secretKey:<#your_secret_key#>];
```

Swift:

```swift
 TuyaSmartSDK.sharedInstance()?.start(withAppKey: <#your_app_key#>, secretKey: <#your_secret_key#>)
```

至此，准备工作已经全部完毕，可以开始 App 开发啦。




## 开发文档

更多请参考：[涂鸦智能设备控制业务包 iOS 开发文档](https://tuyainc.github.io/tuyasmart_panel_ios_sdk_doc/)

## 版本更新记录

[CHANGELOG.md](./CHANGELOG.md) 

