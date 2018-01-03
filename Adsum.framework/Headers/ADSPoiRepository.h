//
//  ADSPoiRepository.h
//  Adsum
//
//  Created by Aiza Simbra on 1/12/17.
//  Copyright © 2017 Adactive. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ADSAbstractRepository.h"

@interface ADSPoiRepository : ADSAbstractRepository

/*!
 @brief Fetch Pois from our server and store them in the @see ADSAbstractRepository#objects property.
 */
- (void)fetchPoi:(void (^)(NSArray * pois))success fail:(void (^)(int errorCode, NSError * error))fail;
- (id)initWithADSHttpClient:(ADSHttpClient *)httpClient;

@end
