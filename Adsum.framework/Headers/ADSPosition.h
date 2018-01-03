//
//  ADSPosition.h
//  Adsum
//
//  Created by Aiza Simbra on 1/9/17.
//  Copyright © 2017 Adactive. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ADSPosition : NSObject <NSCopying>

/*! This is the x coordinate of a position. */
@property (nonatomic, copy) NSNumber *x;

/*! This is the y coordinate of a position. */
@property (nonatomic, copy) NSNumber *y;

/*! This is the z coordinate of a position. */
@property (nonatomic, copy) NSNumber *z;

/*! Get the Position from a string value */
+ (ADSPosition *)getPositionFromString:(NSString *)pos;

- (instancetype)initWithX:(double)x y:(double)y z:(double)z;

- (BOOL)isEqual:(id)other;

- (BOOL)isEqualToPosition:(ADSPosition *)position;

- (NSUInteger)hash;

- (NSString *)description;

- (id)copyWithZone:(NSZone *)zone;

+ (instancetype)positionWithX:(double)x y:(double)y z:(double)z;

@end
