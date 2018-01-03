//
//  ADSPlace.h
//  Adsum
//
//  Created by Aiza Simbra on 12/20/16.
//  Copyright © 2016 Aiza Simbra. All rights reserved.
//
#import <Foundation/Foundation.h>
#import "ADSPosition.h"

@interface ADSPlace : NSObject

/*! This is the id of a Place. */
@property (nonatomic, copy) NSNumber *uid;

/*! This is the name of a Place. */
@property (nonatomic, copy) NSString *name;

/*! This is the position coordinates of a Place.
 */
@property (nonatomic, strong) ADSPosition *position;

/*! This is the id of a building. */
@property (nonatomic, copy) NSNumber *buildingId;

/*! This is the id of a floor. */
@property (nonatomic, copy) NSNumber *floorId;

/*! This is the id of a shape. */
@property (nonatomic, copy) NSNumber *shapeId;

/*! This is the array of all the poi linked to a Place. */
@property (nonatomic, strong) NSMutableArray *pois;

/*! This is the array of all the customobjects linked to a Place. */
@property (nonatomic, strong) NSMutableArray *customObjects;

/*! This is the signature of a Place. */
@property (nonatomic, copy) NSString *signature;

/*! This is the version of a Place. */
@property (nonatomic, copy) NSNumber *version;

/*! This is the date of creation of a Place. */
@property (nonatomic, copy) NSDate *createdAt;

/*! This is the date of last update of a Place. */
@property (nonatomic, copy) NSDate *updatedAt;

- (instancetype)initWithJson:(NSDictionary *)json;

- (NSString *)description;

@end
