//
//  ADSFileEntity.h
//  Adsum
//
//  Created by Aiza Simbra on 10/01/2017.
//  Copyright © 2017 Adactive. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ADSFileEntity : NSObject

/*! File Entity ID */
@property (nonatomic, copy) NSNumber *uid;

/*! File Entity reference */
@property (nonatomic, copy) NSString *reference;

/*! File Entity content hash */
@property (nonatomic, copy) NSString *contentHash;

/*! File Entity URI */
@property (nonatomic, copy) NSString *uri;

/*! File Entity context */
@property (nonatomic, copy) NSString *context;

/*! File Entity file type */
@property (nonatomic, copy) NSString *fileType;

/*! File location on the disk */
@property (nonatomic, copy) NSString *path;

- (instancetype)initWithJson:(NSDictionary *)json;

- (NSString *)description;

- (id)initWithPath:(NSString *)path;

@end
