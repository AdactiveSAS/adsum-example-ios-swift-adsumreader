//
//  ADSStore.h
//  Adsum
//
//  Created by Aiza Simbra on 1/9/17.
//  Copyright © 2017 Adactive. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <ADSPoi.h>

@interface ADSStore : ADSPoi

/*! The Store priority */
@property (nonatomic, copy) NSNumber *priority;

/*! The Store opening time */
@property (nonatomic, copy) NSString *openingTime;

/*! The Store phone number */
@property (nonatomic, copy) NSString *phone;

/*! The Store URL address */
@property (nonatomic, copy) NSString *url;

- (instancetype)initWithJson:(NSDictionary *)json;

- (NSString *)description;

@end
