//
//  ADSAbstractRepository.m
//  Adsum
//
//  Created by Quentin Coursodon on 18/01/2017.
//  Copyright © 2017 Adactive. All rights reserved.
//

#import <Foundation/Foundation.h>

@class ADSHttpClient;

@interface ADSAbstractRepository : NSObject

- (id)initWithADSHttpClient:(ADSHttpClient*)httpClient;

/*!
 @brief An NSMutableArray containing the fecthed data.
 */
@property (nonatomic, strong) NSMutableArray* objects;

@end
