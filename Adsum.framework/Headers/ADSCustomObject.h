//
//  ADSCustomObject.h
//  Adsum
//
//  Created by Aiza Simbra on 10/01/2017.
//  Copyright © 2017 Adactive. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <ADSPosition.h>

typedef enum {
    BILLBOARD,
    STATIC,
    FLIP
}OrientationMode;

@interface ADSCustomObject : NSObject <NSCoding>

/*! CustomObject ID */
@property (nonatomic, copy) NSNumber *uid;

/*! CustomObject If autoscale */
@property (nonatomic) BOOL autoscale;

/*! CustomObject rotation value */
@property (nonatomic, copy) NSNumber *rotationSpeed;

/*! CustomObject place */
@property (nonatomic, copy) NSNumber *placeId;

/*! CustomObject POI */
@property (nonatomic, copy) NSNumber *poiId;

/*! CustomObject position offset */
@property (nonatomic, strong) ADSPosition *offset;

/*! CustomObject priority value */
@property (nonatomic, copy) NSNumber *priority;

/*! CustomObject orientation */
@property (nonatomic) OrientationMode orientation;

/*! CustomObject If permanent display */
@property (nonatomic) BOOL permanentDisplay;

@property (nonatomic, copy) NSNumber *rotation;

- (void)setPosition:(ADSPosition *)position;
- (ADSPosition *)getPosition;

- (void)setRotationRelativeToNorth:(NSNumber *)rotation;

- (id)initWithJson:(NSDictionary *)json;
- (id)init;

- (NSString *)description;

@end
