# Upgrading

**Panel SDK has been renamed as Device Control BizBundle, and the code warehouse has been migrated to Github. [TuyaSmartPanelBizBundle](https://tuyainc.github.io/tuyasmart_bizbundle_ios_doc/zh-hans/pages/panel/)**

## Integrated Migration

The `Podfile` reference is changed to the following form:

```ruby
source "https://github.com/TuyaInc/TuyaPublicSpecs.git"
source 'https://cdn.cocoapods.org/'

target 'your_target_name' do
  # TuyaSmart SDK
  pod "TuyaSmartHomeKit"
  # Add device control biz bundle, need to specify a fixed version number
  pod 'TuyaSmartPanelBizBundle', 'xxx'
  # If you need the sweeper function, please rely on the relevant plug-in of the sweeper
  # pod 'TuyaRNApi/Sweeper'
end
```



## Interface Migration

The old version of the SDK provides the `TuyaSmartPanelSDK` class to implement the loading device control panel, and the new version of the business package provides a set of component solutions to call the functional interface of each business package.

**Note：** The new version and the old version are incompatible and cannot be integrated at the same time.



### Open Panel

**The old calling method is:**

```objc
[TuyaSmartPanelSDK sharedInstance].homeId = deviceModel.homeId;
[[TuyaSmartPanelSDK sharedInstance] gotoPanelViewControllerWithDevice:deviceModel completion:^(NSError *error) {
     NSLog(@"load error: %@", error);
}];
```

**Switch to the new calling method：**

> Please check the [TuyaSmartPanelBizBundle] (https://tuyainc.github.io/tuyasmart_bizbundle_ios_doc/zh-hans/pages/panel/) User Guide

```objc
id<TYPanelProtocol> impl = [[TuyaSmartBizCore sharedInstance] serviceOfProtocol:@protocol(TYPanelProtocol)];
[impl gotoPanelViewControllerWithDevice:deviceModel group:nil initialProps:nil contextProps:nil completion:^(NSError * _Nullable error) {
    if (error) {
        NSLog(@"Load error: %@", error);
    }
}];
```



## Clear Panel Cache

**The old calling method is:**

```objc
[[TuyaSmartPanelSDK sharedInstance] clearPanelCache];
```

**Switch to the new calling method：**

```objc
id<TYPanelProtocol> impl = [[TuyaSmartBizCore sharedInstance] serviceOfProtocol:@protocol(TYPanelProtocol)];
[impl cleanPanelCache];
```



## Panel Delegate

The old version provides `TuyaSmartPanelSDKDelegate` callback events in the panel, and the new version provides multiple Protocol callback events of different types.

### Click Panel Toolbar Right Menu

**The old calling method is:**

```objc
#pragma mark - TuyaSmartPanelSDKDelegate

- (void)tyPanelDidPressedRightMenuWithDevice:(nullable TuyaSmartDeviceModel *)device orGroup:(nullable TuyaSmartGroupModel *)group {

}
```

**Switch to the new calling method：**

```objc
[[TuyaSmartBizCore sharedInstance] registerService:@protocol(TYDeviceDetailProtocol) withInstance:self];

#pragma mark - TYDeviceDetailProtocol
- (void)gotoDeviceDetailDetailViewControllerWithDevice:(TuyaSmartDeviceModel *)device group:(TuyaSmartGroupModel *)group {
    
}
```

### The Callback for Can Not Find Panel Container

**The old calling method is:**

```objc
#pragma mark - TuyaSmartPanelSDKDelegate

- (nullable UIViewController *)requireSpecialPanelForDevice:(nullable TuyaSmartDeviceModel *)device orGroup:(nullable TuyaSmartGroupModel *)group {

}
```

**Switch to the new calling method：**

Different protocols are provided for different types of devices. E.g:

- `TYRNCameraProtocol`：IPC ReactNative Panel. You can choose to implement it yourself, or directly access the IPC ReactNative  Bizbundle `TuyaSmartCameraRNPanelBizBundle`
- `TYCameraProtocol`：IPC Native Panel。You can choose to implement it yourself，or directly access the IPC Native Bizbundle `TuyaSmartCameraPanelBizBundle`

Example：

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

### Get the Panel Router Url

**The old calling method is:**

```objc
#pragma mark - TuyaSmartPanelSDKDelegate

- (void)tyPanelDevice:(nullable TuyaSmartDeviceModel *)device
              orGroup:(nullable TuyaSmartGroupModel *)group
  handleOpenURLString:(nonnull NSString *)urlString {

}
```

**Switch to the new calling method：**

```objc
[[TuyaSmartBizCore sharedInstance] registerRouteWithHandler:^BOOL(NSString * _Nonnull url, NSDictionary * _Nonnull raw) {
    NSLog(@"route: %@", url);
  	NSLog(@"params: %@", raw);
    return false;
}];
```

