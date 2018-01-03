//
//  AdsumCoreNativeAPI.h
//  AdsumCoreNativeAPI
//
//  Created by adactive on 17/01/14.
//  Copyright (c) 2014 adactive. All rights reserved.
//

#ifndef adactive_AdsumCoreView_h
#define adactive_AdsumCoreView_h

#import <UIKit/UIKit.h>

@class ADSDataManager;
@class ADSPosition;
@class ADSGpsPosition;
@class ADSPlace;
@protocol ADSMapDelegate;
@class ADSPoi;
@class ADSPicto;
@class ADSLabel;
@class ADSCustomObject;
@class ADSPathOptions;

@interface AdsumCoreView : UIView
{
    
}

- (id)initWithFrame:(CGRect)rect ADSDataManager:(ADSDataManager *)dataManager;

#pragma mark - Camera Control

- (void)setCurrentFloor:(NSNumber*)floorId;

- (void)setSiteView;

- (NSArray*)getFloorsWithBuilding:(NSNumber*)buildingId;

- (NSArray*)getBuildings;

- (void)centerOnPlace:(ADSPlace *)place;

- (void)centerOnPlace:(ADSPlace *)place withZoom:(NSNumber *)zoomLevel;

- (void)centerOnPosition:(ADSPosition*)position;

- (void)centerOnPosition:(ADSPosition *)position withZoom:(NSNumber *)zoomLevel;

- (void)resetCamera;

#pragma mark - ADSCustomObject Manipulation

- (void)addADSCustomObject:(ADSCustomObject *)co atPosition:(ADSPosition *)position onFloor:(NSNumber *)floorId;

- (void)removeADSCustomObject:(ADSCustomObject *)picto;

- (void)setMapBackgroundColor:(UIColor *)backgroundColor;

#pragma mark - Path drawing

- (bool)drawPathFromADSPlace:(ADSPlace *)start toADSPlace:(ADSPlace *)destination forPrm:(BOOL)prm;

- (bool)drawPathFromADSPosition:(ADSPosition*) startPosition andFloor:(NSNumber *)startFloorId toADSPositon:(ADSPosition *) destinationPosition andFloor:(NSNumber *)destinationFloorId forPrm:(BOOL)prm;

- (void)setPathOptions:(ADSPathOptions *)pathOptions;

- (void)removePath;

#pragma mark - Event Handling

- (void)addAMapDelegate:(id<ADSMapDelegate>)delegate;

- (void)removeADSMapDelegate:(id <ADSMapDelegate>)delegate;

#pragma mark - HighLight

- (void)hightlightADSPlace:(ADSPlace *)place
                 withColor:(UIColor *)color
                 andBounce:(NSNumber *)bounce;

- (void)unlightADSPlace:(ADSPlace *)place;

#pragma mark - ADSPosition and ADSGpsPosition conversion

- (ADSPosition*)ADSGpsToADSPosition:(ADSGpsPosition*)gps;

- (ADSGpsPosition *)ADSPositionToADSGpsPosition:(ADSPosition *)position;

@property(atomic) bool CanRender;

@end


#endif
