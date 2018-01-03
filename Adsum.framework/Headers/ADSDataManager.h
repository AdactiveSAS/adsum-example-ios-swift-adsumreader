//
//  ADSDataManager.h
//  Adsum
//
//  Created by Aiza Simbra on 12/20/16.
//  Copyright © 2016 Aiza Simbra. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ADSOptions.h"
#import "ADSCategoryRepository.h"
#import "ADSLabelRepository.h"
#import "ADSPlaceRepository.h"
#import "ADSPictoRepository.h"
#import "ADSPoiRepository.h"

@interface ADSDataManager : NSObject

typedef void (^ErrorBlock)(int statusCode, NSError *error);

typedef void (^SuccessBlock)(NSArray *items, NSUInteger size);


@property(nonatomic, strong) ADSCategoryRepository *categoryRepository;
@property(nonatomic, strong) ADSLabelRepository *labelRepository;
@property(nonatomic, strong) ADSPictoRepository *pictoRepository;
@property(nonatomic, strong) ADSPlaceRepository *placeRepository;
@property(nonatomic, strong) ADSPoiRepository *poiRepository;

@property(nonatomic, strong) ADSOptions *options;

- (id)initWithADSOptions:(ADSOptions *)options;

/*!
 * @brief Fetch Pois, Categories and Places
 * @param success
 * @param fail 
 */
- (void)fetch:(void (^)(void))success fail:(void (^)(NSArray<NSError *> *))fail;

@end
