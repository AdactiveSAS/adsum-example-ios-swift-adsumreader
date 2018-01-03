//
//  ADSPoi.h
//  Adsum
//
//  Created by Aiza Simbra on 1/9/17.
//  Copyright © 2017 Adactive. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <ADSFileEntity.h>

@interface ADSPoi : NSObject

/*! This is the id of a POI. */
@property (nonatomic, copy) NSNumber *uid;

/*! This is the name of a POI. */
@property (nonatomic, copy) NSString *name;

/*! This is the description of a POI. */
@property (nonatomic, copy) NSString *poiDescription;

/*! This is the signature of a POI. */
@property (nonatomic, copy) NSString *signature;

/*! This is the client ID of a POI. */
@property (nonatomic, copy) NSNumber *clientId;

/*! This is the version of a POI. */
@property (nonatomic, copy) NSNumber *version;

/*! Novelty of a POI. */
@property (nonatomic) BOOL isNew;

/*! This is the metadata of a POI. */
@property (nonatomic, strong) NSMutableDictionary *metadata;

/*! This is the array of categories of a POI. */
@property (nonatomic, strong) NSMutableArray *category;

/*! This is the array of custom objects of a POI. */
@property (nonatomic, strong) NSMutableArray *customObjects;

/*! This is the array of logos of a POI. */
@property (nonatomic, strong) NSMutableArray <ADSFileEntity *> *logos;

/*! This is the array of parents of a POI. */
@property (nonatomic, strong) NSMutableArray *parents;

/*! This is the array of pictures of a POI. */
@property (nonatomic, strong) NSMutableArray <ADSFileEntity *> *pictures;

/*! This is the array of places of a POI. */
@property (nonatomic, strong) NSMutableArray *places;

/*! This is the array of tags of a POI. */
@property (nonatomic, strong) NSMutableArray <NSString *> *tags;

/*! This is the date of creation of a POI. */
@property (nonatomic, copy) NSDate *createdAt;

/*! This is the date of last update of a POI. */
@property (nonatomic, copy) NSDate *updatedAt;

- (instancetype)initWithJson:(NSDictionary *)json;

- (NSString *)description;

@end
