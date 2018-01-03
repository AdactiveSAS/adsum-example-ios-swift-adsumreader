//
// Created by Quentin Coursodon on 28/02/2017.
// Copyright (c) 2017 Adactive. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol ADSMapDelegate <NSObject>

@optional
- (void)mapLoaded;

@optional
- (void)floorChanged:(long)id;
@end