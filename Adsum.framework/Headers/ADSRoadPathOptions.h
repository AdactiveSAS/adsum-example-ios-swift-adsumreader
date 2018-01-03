//
// Created by Quentin Coursodon on 02/08/2017.
// Copyright (c) 2017 Adactive. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ADSPathOptions.h"

/**
 * Allow you to customize the behaviour of RoadPath
 */
@interface ADSRoadPathOptions : ADSPathOptions

/**
 * Hide or show the red Sphere at the start / end of the path (default is false)
 * @param state
 * @return
 */
- (ADSRoadPathOptions *)setStartEndGizmosVisible:(BOOL)state;

/**
 * Set the path of the width (default is 15.0)
 * @param value
 * @return
 */
- (ADSRoadPathOptions *)setPathWidth:(float)value;

/**
 * Set the offset of the path relative to the floor (default is 5.0)
 * @param value
 * @return
 */
- (ADSRoadPathOptions *)setPathHeightOffset:(float)value;

/**
 * Set the offset of the travelling arrow relative to the path (default is 5.0)
 * @param value
 * @return
 */
- (ADSRoadPathOptions *)setTravellerHeightOffset:(float)value;

/**
 * Set the speed of the travelling arrow (default is 0.7)
 * @param value
 * @return
 */
- (ADSRoadPathOptions *)setTravellerVelocity:(float)value;

/**
 * Set the distance between the travelling arrows
 * @param value
 * @return
 */
- (ADSRoadPathOptions *)setTravellerInterDistance:(float)value;

/**
 * Set the travelling arrow size (default is 15.0)
 * @param value
 * @return
 */
- (ADSRoadPathOptions *)setTravellerSize:(float)value;
@end