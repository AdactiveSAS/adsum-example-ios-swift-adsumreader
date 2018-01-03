//
// Created by Quentin Coursodon on 23/02/2017.
// Copyright (c) 2017 Adactive. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface ADSGpsPosition : NSObject <NSCopying>
@property(nonatomic, copy) NSNumber* latitude;
@property(nonatomic, copy) NSNumber* longitude;

- (id)copyWithZone:(NSZone *)zone;
- (instancetype)initWithLatitude:(NSNumber *)latitude longitude:(NSNumber *)longitude;

+ (instancetype)positionWithLatitude:(NSNumber *)latitude longitude:(NSNumber *)longitude;

- (BOOL)isEqual:(id)other;

- (BOOL)isEqualToPosition:(ADSGpsPosition *)position;

- (NSUInteger)hash;

- (NSString *)description;
@end