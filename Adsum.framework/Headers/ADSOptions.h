//
//  ADSOptions.h
//  Pods
//
//  Created by Quentin Coursodon on 24/01/2017.
//
//

#ifndef ADSOptions_h
#define ADSOptions_h

#import <Foundation/Foundation.h>

@interface ADSOptions : NSObject

/*!
 @brief The Api Key used to authentication an user.
 */
@property (nonatomic, strong) NSString* apiKey;

/*!
 @brief Identify the device.
 */
@property (nonatomic, strong) NSNumber* device;

/*!
 @brief Identify the site.
 */
@property (nonatomic, strong) NSNumber* site;

/*!
 @brief Default : european server, set to "http://asia-api.adsum.io" to use Asian backoffice.
 */
@property (nonatomic, strong) NSString* apiBaseUrl;

/*!
 @brief Default : "2.1", you should not have to change the value.
 */
@property (nonatomic, strong) NSString* apiVersion;

@end
#endif /* ADSOptions_h */
