//
//  TuyaSmartPanelSDK.h
//  TuyaSmartPanelSDK
//
//  Created by 黄凯 on 2018/8/30.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class TuyaSmartPanelSDK;
@class TuyaSmartDeviceModel;
@class TuyaSmartGroupModel;
@protocol TuyaSmartPanelSDKDelegate <NSObject>

/// 当右上角按钮点击时回调
/// @param device 被触发面板的设备实体
/// @param group 被触发面板的群组实体
- (void)tyPanelDidPressedRightMenuWithDevice:(nullable TuyaSmartDeviceModel *)device
                                     orGroup:(nullable TuyaSmartGroupModel *)group;

/// 当面板触发短链跳转时触发
/// 你需要根据短链含义实现自己的业务逻辑
/// @param device 被触发面板的设备实体
/// @param group 被触发面板的群组实体
/// @param urlString 跳转短链（各短链含义请联系）
- (void)tyPanelDevice:(nullable TuyaSmartDeviceModel *)device
              orGroup:(nullable TuyaSmartGroupModel *)group
  handleOpenURLString:(nonnull NSString *)urlString;

/// 当找不到设备对应的面板容器时（IPC 面板、原生面板等）
/// 你需要根据设备实现你自己的面板容器 VC
/// @param device 设备实体
/// @param group 群组实体
- (nullable UIViewController *)requireSpecialPanelForDevice:(nullable TuyaSmartDeviceModel *)device
                                                    orGroup:(nullable TuyaSmartGroupModel *)group;

#pragma mark - DEPRECATED Delegate Methods

- (void)didPressedRightMenu DEPRECATED_MSG_ATTRIBUTE("tyPanelDidPressedRightMenuWithDevice:orGroup:");

- (void)tuyaSmartPanelSDK:(nonnull TuyaSmartPanelSDK *)tuyaSmartPanelSDK handleOpenURLString:(nonnull NSString *)urlString DEPRECATED_MSG_ATTRIBUTE("tyPanelDevice:orGroup:handleOpenURLString:");

- (nullable UIViewController *)vcForSpecialPanelWithDeviceModel:(nonnull TuyaSmartDeviceModel *)device DEPRECATED_MSG_ATTRIBUTE("requireSpecialPanelForDevice:orGroup:");

@end

@class TuyaSmartDeviceModel;
@class TuyaSmartGroupModel;
@interface TuyaSmartPanelSDK : NSObject

+ (nonnull instancetype)sharedInstance;

@property (nonatomic, weak, nullable) id<TuyaSmartPanelSDKDelegate> delegate;

/**
 当前面板 sdk 版本
 */
@property (nonatomic, strong, readonly, nonnull) NSString *sdkVersion;

/**
 当前 sdk 中使用的面板 RN 版本，此标记为云端特有，作为拉取面板资源条件
 */
@property (nonatomic, strong, readonly, nonnull) NSString *sdkRnVersion;

/**
 当前 sdk 中使用的家庭 id，标记为用户当前所属家庭，作为设备更新条件。在每次切换家庭时，需要同步的更新此数据
 */
@property (nonatomic, assign) long long homeId;

/**
 /-- 涂鸦 iOS 设备面板入口; 默认入口，Push 方式 --/
 
 需要传入对应的 device
 在这之前，请确定已设定好对应的代理
 
 @param device 设备 model
 @param completion 结果回调，成功加载面板 error == nil
 */
- (void)gotoPanelViewControllerWithDevice:(nonnull TuyaSmartDeviceModel *)device
                               completion:(void (^ _Nullable)(NSError *_Nullable error))completion;

/**
 /-- 涂鸦 iOS 设备面板入口; Present 方式 --/
 Present 方式接入方不需要依赖 TPNavigationController 作为导航控制器
 
 需要传入对应的 device
 在这之前，请确定已设定好对应的代理
 
 @param device 设备 model
 @param completion 结果回调，成功加载面板 error == nil
 */
- (void)presentPanelViewControllerWithDevice:(nonnull TuyaSmartDeviceModel *)device
                                  completion:(void (^ _Nullable)(NSError *_Nullable error))completion;

/**
 /-- 涂鸦 iOS 群组面板入口; 默认入口，Push 方式 --/
 
 需要传入对应的 group
 在这之前，请确定已设定好对应的代理
 
 @param group 群组 model
 @param completion 结果回调，成功加载面板 error == nil
 */
- (void)gotoPanelViewControllerWithGroup:(nonnull TuyaSmartGroupModel *)group
                              completion:(void (^ _Nullable)(NSError *_Nullable error))completion;

/**
 /-- 涂鸦 iOS 群组面板入口; Present 方式 --/
 Present 方式接入方不需要依赖 TPNavigationController 作为导航控制器
 
 需要传入对应的 group
 在这之前，请确定已设定好对应的代理
 
 @param group 群组 model
 @param completion 结果回调，成功加载面板 error == nil
 */
- (void)presentPanelViewControllerWithGroup:(nonnull TuyaSmartGroupModel *)group
                                 completion:(void (^ _Nullable)(NSError *_Nullable error))completion;
/**
 清理缓存
 */
- (void)clearPanelCache;

@end
