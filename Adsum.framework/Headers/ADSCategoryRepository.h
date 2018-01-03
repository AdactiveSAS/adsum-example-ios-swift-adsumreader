//
//  ADSCategoryRepository.h
//  Adsum
//
//  Created by Aiza Simbra on 1/13/17.
//  Copyright © 2017 Adactive. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ADSAbstractRepository.h"

@interface ADSCategoryRepository : ADSAbstractRepository

/*!
 @brief Fetch Categories from our server and store them in the @see ADSAbstractRepository#objects property.
 */
- (void)fetchCategory:(void (^)(NSArray * categories))success fail:(void (^)(int errorCode , NSError * error))fail;
- (id)initWithADSHttpClient:(ADSHttpClient *)httpClient;

@end
