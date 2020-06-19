# 迁移指南

**Panel SDK 已改名为设备控制业务包，新版业务包提供全新的接入方式，通过组件化快速集成多个业务包。接入文档查看 [涂鸦智能设备控制业务包](https://tuyainc.github.io/tuyasmart_bizbundle_ios_doc/zh-hans/pages/panel/)**

## 集成方式迁移

`Podfile` 引用改为如下形式：

```ruby
source "https://github.com/TuyaInc/TuyaPublicSpecs.git"
source 'https://cdn.cocoapods.org/'

target 'your_target_name' do
  # TuyaSmart SDK
  pod "TuyaSmartHomeKit"
  # 添加设备控制业务包，需要指定固定版本号
  pod 'TuyaSmartPanelBizBundle', 'xxx'
  # 若需要扫地机功能，请依赖扫地机相关插件
  # pod 'TuyaRNApi/Sweeper'
end
```



## 接口迁移

旧版 SDK 提供 `TuyaSmartPanelSDK` 类来实现加载设备控制面板，新版业务包提供一套组件化方案来调用各个业务包的功能接口。

**注意：** 新版和旧版不兼容，不能同时集成



### 打开面板

**旧版调用方式为：**

```objc
[TuyaSmartPanelSDK sharedInstance].homeId = deviceModel.homeId;
[[TuyaSmartPanelSDK sharedInstance] gotoPanelViewControllerWithDevice:deviceModel completion:^(NSError *error) {
     NSLog(@"load error: %@", error);
}];
```

**切换到新版调用方式：**

> 注意事项查看[涂鸦智能设备控制业务包](https://tuyainc.github.io/tuyasmart_bizbundle_ios_doc/zh-hans/pages/panel/)使用指南

```objc
id<TYPanelProtocol> impl = [[TuyaSmartBizCore sharedInstance] serviceOfProtocol:@protocol(TYPanelProtocol)];
[impl gotoPanelViewControllerWithDevice:deviceModel group:nil initialProps:nil contextProps:nil completion:^(NSError * _Nullable error) {
    if (error) {
        NSLog(@"Load error: %@", error);
    }
}];
```



### 清除面板缓存

**旧版调用方式为：**

```objc
[[TuyaSmartPanelSDK sharedInstance] clearPanelCache];
```

**切换到新版调用方式：**

```objc
id<TYPanelProtocol> impl = [[TuyaSmartBizCore sharedInstance] serviceOfProtocol:@protocol(TYPanelProtocol)];
[impl cleanPanelCache];
```



### 面板事件回调

旧版提供 `TuyaSmartPanelSDKDelegate` 回调面板内事件，新版提供多个 Protocol 回调不同类型的事件。

#### 点击面板右上角事件

**旧版调用方式为：**

```objc
#pragma mark - TuyaSmartPanelSDKDelegate

- (void)tyPanelDidPressedRightMenuWithDevice:(nullable TuyaSmartDeviceModel *)device orGroup:(nullable TuyaSmartGroupModel *)group {

}
```

**切换到新版调用方式：**

```objc
[[TuyaSmartBizCore sharedInstance] registerService:@protocol(TYDeviceDetailProtocol) withInstance:self];

#pragma mark - TYDeviceDetailProtocol
- (void)gotoDeviceDetailDetailViewControllerWithDevice:(TuyaSmartDeviceModel *)device group:(TuyaSmartGroupModel *)group {
    
}
```

#### 当找不到设备对应的面板容器时

**旧版调用方式为：**

```objc
#pragma mark - TuyaSmartPanelSDKDelegate

- (nullable UIViewController *)requireSpecialPanelForDevice:(nullable TuyaSmartDeviceModel *)device orGroup:(nullable TuyaSmartGroupModel *)group {

}
```

**切换到新版调用方式：**

针对不同类型的设备，提供不同的 Protocol。例如：

- `TYRNCameraProtocol`：IPC RN 面板。可以选择自行实现，或者直接接入摄像头面板业务包 `TuyaSmartCameraRNPanelBizBundle`
- `TYCameraProtocol`：IPC 原生面板。可以选择自行实现，或者直接接入摄像头面板业务包 `TuyaSmartCameraPanelBizBundle`

自行实现示例：

```objc
[[TuyaSmartBizCore sharedInstance] registerService:@protocol(TYRNCameraProtocol) withInstance:self];

#pragma mark - TYRNCameraProtocol
- (UIViewController *)cameraRNPanelViewControllerWithDeviceId:(NSString *)devId {
    
}
```

```objc
[[TuyaSmartBizCore sharedInstance] registerService:@protocol(TYCameraProtocol) withInstance:self];

#pragma mark - TYCameraProtocol

- (UIViewController *)viewControllerWithDeviceId:(NSString *)devId uiName:(NSString *)uiName {
    
}
```

#### 获取面板内路由

**旧版调用方式为：**

```objc
#pragma mark - TuyaSmartPanelSDKDelegate

// 面板内部路由事件
- (void)tyPanelDevice:(nullable TuyaSmartDeviceModel *)device
              orGroup:(nullable TuyaSmartGroupModel *)group
  handleOpenURLString:(nonnull NSString *)urlString {

}
```

**切换到新版调用方式：**

```objc
[[TuyaSmartBizCore sharedInstance] registerRouteWithHandler:^BOOL(NSString * _Nonnull url, NSDictionary * _Nonnull raw) {
    NSLog(@"路由: %@", url);
  	NSLog(@"参数: %@", raw);
    return false;
}];
```

