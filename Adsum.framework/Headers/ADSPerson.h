//
//  ADSPerson.h
//  Adsum
//
//  Created by Aiza Simbra on 1/9/17.
//  Copyright © 2017 Adactive. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <ADSPoi.h>

@interface ADSPerson : ADSPoi

/*! Person first name */
@property (nonatomic, copy) NSString *firstName;

/*! Person last name */
@property (nonatomic, copy) NSString *lastName;

/*! Person desk phone number */
@property (nonatomic, copy) NSString *deskPhone;

/*! Person mobile phone number */
@property (nonatomic, copy) NSString *mobilePhone;

- (instancetype)initWithJson:(NSDictionary *)json;

- (NSString *)description;

@end
