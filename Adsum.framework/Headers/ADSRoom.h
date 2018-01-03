//
//  ADSRoom.h
//  Adsum
//
//  Created by Aiza Simbra on 1/9/17.
//  Copyright © 2017 Adactive. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <ADSPoi.h>

@interface ADSRoom : ADSPoi

/*! Room reference */
@property (nonatomic, copy) NSString *reference;

/*! Room kind */
@property (nonatomic, copy) NSString *kind;

/*! Room capacity */
@property (nonatomic, copy) NSNumber *capacity;

/*! Room phone number */
@property (nonatomic, copy) NSString *phone;

- (instancetype)initWithJson:(NSDictionary *)json;

- (NSString *)description;

@end
