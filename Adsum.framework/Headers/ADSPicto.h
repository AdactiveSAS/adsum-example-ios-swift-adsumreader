//
//  ADSPicto.h
//  Adsum
//
//  Created by Aiza Simbra on 10/01/2017.
//  Copyright © 2017 Adactive. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <ADSCustomObject.h>
#import <ADSFileEntity.h>

@interface ADSPicto : ADSCustomObject

/*! Picto File */
@property (nonatomic, strong) ADSFileEntity *file;

/*! Picto width */
@property (nonatomic, copy) NSNumber *width;

/*! Picto height */
@property (nonatomic, copy) NSNumber *height;

- (id)initWithJson:(NSDictionary *)json;

- (id)initWithImagePath:(NSString *)path;

- (NSString *)description;

@end
