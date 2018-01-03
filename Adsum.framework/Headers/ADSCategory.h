//
//  ADSCategory.h
//  Adsum
//
//  Created by Aiza Simbra on 10/01/2017.
//  Copyright © 2017 Adactive. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <ADSCategoryChild.h>

@interface ADSCategory : NSObject

/*! Category children. */
@property (nonatomic, strong) NSMutableArray <ADSCategoryChild *> *children;

/*! Category client ID. */
@property (nonatomic, copy) NSNumber *clientId;

/*! Category color. */
@property (nonatomic, copy) NSString *color;

/*! Category ID. */
@property (nonatomic, copy) NSNumber *uid;

/*! Category metadata. */
@property (nonatomic, strong) NSMutableDictionary *metadata;

/*! Category name. */
@property (nonatomic, copy) NSString *name;

/*! Category parameters. */
@property (nonatomic, strong) NSMutableArray <NSString *> *parameters;

/*! Category parents. */
@property (nonatomic, strong) NSMutableArray *parents;

/*! Category POIs. */
@property (nonatomic, strong) NSMutableArray *pois;

/*! Category rank. */
@property (nonatomic, copy) NSNumber *rank;

/*! Category signature. */
@property (nonatomic, copy) NSString *signature;

/*! Category tags. */
@property (nonatomic, strong) NSMutableArray <NSString *> *tags;

/*! Category type. */
@property (nonatomic, copy) NSString *type;

/*! This is the creation date of a Category. */
@property (nonatomic, copy) NSDate *createdAt;

/*! This is the date of last update of a Category. */
@property (nonatomic, copy) NSDate *updatedAt;

/*! Category version. */
@property (nonatomic, copy) NSNumber *version;

- (instancetype)initWithJson:(NSDictionary *)json;

- (NSString *)description;

@end
