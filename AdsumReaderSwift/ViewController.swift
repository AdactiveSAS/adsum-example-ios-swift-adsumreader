//
//  ViewController.swift
//  AdsumReaderSwift
//
//  Created by Christopher Yeo on 3/1/18.
//  Copyright © 2018 adactive. All rights reserved.
//

import UIKit
import Adsum

class ViewController: UIViewController, ADSMapDelegate {
    
    var mapView : AdsumCoreView?
    var dataManager: ADSDataManager?
    
    override func viewDidLoad() {
        super.viewDidLoad()
        let options = ADSOptions()
        options.apiKey = "62dffdb3044249d39dbaa3a26b1dce68"
        options.site = 341
        options.device = 1063
        options.apiBaseUrl = "http://asia-api.adsum.io"
        
        dataManager = ADSDataManager(adsOptions: options);
        mapView = AdsumCoreView(frame: CGRect(x: 0, y: 0, width: self.view.frame.width, height: self.view.frame.height), adsDataManager: dataManager);
        
        mapView?.addAMapDelegate(self);
        
        self.view.addSubview(mapView!)
        
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    func mapLoaded(){
        print("Has the Map Loaded?");
        dataManager?.fetch({
            self.displayAllPois()
            self.getAllLevels()
        }, fail: { (_: [Error]?) in
            print("NO INTERNET CONNECTION")
        })
    }
    
    
    func displayAllPois(){
        if dataManager != nil {
            for poi in (dataManager?.poiRepository.objects)! {
                let myPoi:ADSPoi = poi as! ADSPoi
                print(myPoi)
            }
        }
    }
    
    func getAllLevels(){
        
        let buildings = mapView?.getBuildings();
        let levels = mapView?.getFloorsWithBuilding(buildings?.first as! NSNumber)
        
        if levels != nil{
            print("level= \(String(describing: levels))")
            mapView?.setCurrentFloor(levels?.first as! NSNumber);
        }
    }
    
    


}

