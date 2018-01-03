//
// Created by Quentin Coursodon on 28/02/2017.
// Copyright (c) 2017 Adactive. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <osgGA/EventHandler>

class Adsum;
class Shape;
@protocol ADSMapDelegate;

class ADSMapEventHandler : public osgGA::EventHandler
{
public:
    ADSMapEventHandler(Adsum * core);

    void subscribe();

    void addDelegate(id<ADSMapDelegate> delegate);
    void removeDelegate(id<ADSMapDelegate> delegate);
    NSMutableArray<id<ADSMapDelegate>>* delegates;
    
private:
    void pathFinished(osg::Referenced* ev);
    void mapUpdate(osg::Referenced* ev);
    void mapLoaded(osg::Referenced* ev);
    void errors(osg::Referenced* ev);
    void objectClicked(osg::Referenced* ev);
    void endAnimation(osg::Referenced* ev);
    void floorChanged(osg::Referenced* ev);

    std::vector<Shape*> _highlightedShapes;

    Adsum * _core;

};
