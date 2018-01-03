//
//  ADSPlaceRepository.h
//  Adsum
//
//  Created by Aiza Simbra on 19/12/2016.
//  Copyright © 2016 Aiza Simbra. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ADSAbstractRepository.h"

@interface ADSPlaceRepository : ADSAbstractRepository

/*!
    @brief Fetch places from our server and store them in the @see ADSAbstractRepository#objects property.
 */
- (void)fetchPlaces:(void (^)(NSArray * places))success fail:(void (^)(int errorCode, NSError * error))fail;

- (id)initWithADSHttpClient:(ADSHttpClient *)httpClient;

@end

