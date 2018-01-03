//
//  ADSCategoryChild.h
//  Adsum
//
//  Created by Aiza Simbra on 10/01/2017.
//  Copyright © 2017 Adactive. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ADSCategoryChild : NSObject

/*! Category child ID */
@property (nonatomic, copy) NSNumber *uid;

/*! Category child position */
@property (nonatomic, copy) NSNumber *position;

- (NSString *)description;

- (id)initWithJson:(id)o;

@end
