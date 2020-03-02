//
//  TYPSmartHomeManager.m
//  TuyaSmartPanelSDK
//
//  Created by TuyaInc on 02/28/2020.
//  Copyright (c) 2020 TuyaInc. All rights reserved.
//

#import "TYPSmartHomeManager.h"

@implementation TYPSmartHomeManager

+ (instancetype)sharedInstance {
    
    static TYPSmartHomeManager *sharedInstance = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        if (!sharedInstance) {
            sharedInstance = [TYPSmartHomeManager new];
        }
    });
    return sharedInstance;
}

- (TuyaSmartHomeManager *)homeManager {
    if (!_homeManager) {
        _homeManager = [TuyaSmartHomeManager new];
    }
    return _homeManager;
}

- (instancetype)init {
    self = [super init];
    if (self) {
        _currentHome = [TuyaSmartHome homeWithHomeId:self.homeManager.homes.firstObject.homeId];
    }
    return self;
}

@end
