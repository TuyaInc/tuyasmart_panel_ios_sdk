//
//  TYPSmartHomeManager.h
//  TuyaSmartPanelSDK
//
//  Created by TuyaInc on 02/28/2020.
//  Copyright (c) 2020 TuyaInc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <TuyaSmartDeviceKit/TuyaSmartDeviceKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface TYPSmartHomeManager : NSObject

@property (nonatomic, strong) TuyaSmartHome *currentHome;
@property (nonatomic, strong) TuyaSmartHomeManager *homeManager;

+ (instancetype)sharedInstance;

@end

NS_ASSUME_NONNULL_END
