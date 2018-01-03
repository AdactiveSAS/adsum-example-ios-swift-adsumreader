//
//  ADSLabelRepository.h
//  Adsum
//
//  Created by Aiza Simbra on 1/13/17.
//  Copyright © 2017 Adactive. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ADSAbstractRepository.h"

@interface ADSLabelRepository : ADSAbstractRepository

/*!
 @brief Fetch Labels from our server and store them in the @see ADSAbstractRepository#objects property.
 */
- (void)fetchLabel:(void (^)(NSArray * labels))success fail:(void (^)(int errorCode, NSError * error))fail;
- (id)initWithADSHttpClient:(ADSHttpClient *)httpClient;

@end
