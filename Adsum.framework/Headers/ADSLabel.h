//
//  ADSLabel.h
//  Adsum
//
//  Created by Aiza Simbra on 10/01/2017.
//  Copyright © 2017 Adactive. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <ADSCustomObject.h>

@interface ADSLabel : ADSCustomObject

/*! Label */
@property (nonatomic, copy) NSString *label;

/*! Label font */
@property (nonatomic, copy) NSString *font;

/*! Label alignment */
@property (nonatomic, copy) NSString *alignment;

/*! Label font size */
@property (nonatomic, copy) NSNumber *fontSize;

/*! Label font color */
@property (nonatomic, copy) NSString *fontColor;

/*! Label background color */
@property (nonatomic, copy) NSString *backgroundColor;

@property(nonatomic, copy) NSString *fontPath;

- (instancetype)initWithJson:(NSDictionary *)json;

- (NSString *)description;

@end
