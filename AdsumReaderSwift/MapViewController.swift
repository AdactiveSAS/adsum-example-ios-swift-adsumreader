//
//  MapViewController.swift
//  AdsumReaderSwift
//
//  Created by Christopher Yeo on 4/1/18.
//  Copyright © 2018 adactive. All rights reserved.
//

import UIKit
import SWXMLHash
import Adsum
import ActionSheetPicker_3_0



class MapViewController: UIViewController, ADSMapDelegate, MapButtonsDelegate{
    
    let CONFIG_KEY = "AdsumConfigXml"
    var mapView : AdsumCoreView?
    var dataManager: ADSDataManager?
    
    var floors:[String] = []

    override func viewDidLoad() {
        super.viewDidLoad()
        
        let adsumConfigClass = XmlConfigClass();
        let defaults = UserDefaults.standard
        if let xmlToParse = defaults.string(forKey: CONFIG_KEY){
            
            //parse xml
            
            let xmlData = SWXMLHash.config{
                config in
                config.shouldProcessLazily = false
                }.parse(xmlToParse)
            
            for elem in xmlData["Adsum"].all{
                
                if let val = elem["siteId"].element?.text {
                    if let num = Int(val){
                        adsumConfigClass.siteId = NSNumber(value:num);
                    }
                }
                if let val = elem["kioskId"].element?.text {
                    if let num = Int(val){
                        adsumConfigClass.kioskId = NSNumber(value:num);
                    }
                }
                
                if let val = elem["WSURL"].element?.text{
                    adsumConfigClass.WSURL = val
                }
                
                if let val = elem["APIKEY"].element?.text{
                    adsumConfigClass.APIKEY = val
                }
                
                if let val = elem["PIWIKKEY"].element?.text{
                    adsumConfigClass.PIWIKKEY = val
                }
                
                if let val = elem["PIWIKURL"].element?.text{
                    adsumConfigClass.WSURL = val
                }
                
                if let val = elem["PIWIKSITEID"].element?.text{
                    adsumConfigClass.PIWIKSITEID = val
                }
            }
            
        } else {
            print("Nothing Saved in XML")
        }
        
        let options = ADSOptions()
        options.apiKey = adsumConfigClass.APIKEY
        options.site = adsumConfigClass.siteId
        options.device = adsumConfigClass.kioskId
        options.apiBaseUrl = "http://asia-api.adsum.io"
//        options.apiBaseUrl = adsumConfigClass.WSURL // this doesnt work.
        
        dataManager = ADSDataManager(adsOptions: options);
        mapView = AdsumCoreView(frame: CGRect(x: 0, y: 0, width: self.view.frame.width, height: self.view.frame.height), adsDataManager: dataManager);
        
        mapView?.addAMapDelegate(self);
        
        self.view.addSubview(mapView!)

    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
    }
    
    func floorChangeButtonClicked(floor: Int, sender: UIBarButtonItem){
        
        print(self.floors)
        
        ActionSheetStringPicker.show(withTitle: "Please Select Floor", rows: self.floors, initialSelection: 0, doneBlock: {
            picker, index, value in

            if let selectedFloorInt = Int(value as! String) {
               self.mapView?.setCurrentFloor(NSNumber(value:selectedFloorInt));
            }
            
            return
        }, cancel: { ActionStringCancelBlock in return }, origin: sender)
        
        //mapView?.setCurrentFloor(levels?.first as! NSNumber);
        
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
        if let levels = mapView?.getFloorsWithBuilding(buildings?.first as! NSNumber){
            mapView?.setCurrentFloor(levels.first as! NSNumber);
            for level in levels{
                self.floors.append(String(describing:level))
            }
        }
    }

    // MARK: - Navigation

    // In a storyboard-based application, you will often want to do a little preparation before navigation
//    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
//
//    }

}
