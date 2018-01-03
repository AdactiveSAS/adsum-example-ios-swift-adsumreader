//
//  ADSExhibitor.h
//  Adsum
//
//  Created by Aiza Simbra on 10/01/2017.
//  Copyright © 2017 Adactive. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <ADSPoi.h>

@interface ADSExhibitor : ADSPoi

/*! Exhibitor phone */
@property (nonatomic, copy) NSString *phone;

/*! Exhibitor URL */
@property (nonatomic, copy) NSString *url;

- (instancetype)initWithJson:(NSDictionary *)json;

- (NSString *)description;

@end
