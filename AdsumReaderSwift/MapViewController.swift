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

protocol PoiDelegate{
    func updatePoi(pois: [ADSPoi])
}



class MapViewController: UIViewController, ADSMapDelegate, MapButtonsDelegate{
    
    let CONFIG_KEY = "AdsumConfigXml"
    var mapView : AdsumCoreView?
    var dataManager: ADSDataManager?
    
    var floors:[String] = []
    var poiDelegate : PoiDelegate?
    var poisArray:[ADSPoi] = []
    var placesArray:[ADSPlace] = []
    
   

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
                    adsumConfigClass.PIWIKURL = val
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
        //issue here
        print(adsumConfigClass.WSURL)
//        options.apiBaseUrl = adsumConfigClass.WSURL // this doesnt work.
        
        dataManager = ADSDataManager(adsOptions: options);
        mapView = AdsumCoreView(frame: CGRect(x: 0, y: 0, width: self.view.frame.width, height: self.view.frame.height), adsDataManager: dataManager);
        
        mapView?.addAMapDelegate(self);
        
        self.view.addSubview(mapView!)

    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        
        
    }
    
    override func viewWillDisappear(_ animated: Bool) {
        super.viewWillDisappear(animated)
        //need to still clean up
        mapView?.remove(self)
        mapView = nil
    }
    
    func floorChangeButtonClicked(floor: Int, sender: UIBarButtonItem){
        
        ActionSheetStringPicker.show(withTitle: "Please Select Floor", rows: self.floors, initialSelection: 0, doneBlock: {
            picker, index, value in

            if let selectedFloorInt = Int((value as? String)!) {
               self.mapView?.setCurrentFloor(NSNumber(value:selectedFloorInt));
            }
            
            return
        }, cancel: { ActionStringCancelBlock in return }, origin: sender)
        
    }
    
    func findADSPlaceFromPoiName(poiName:String) -> ADSPlace?{
        
        var placeId = NSNumber()
        
        for poi in poisArray {
            if (poi.name == poiName){
                placeId = poi.places.firstObject as! NSNumber
            }
        }
        
        for place in placesArray{
            if (place.uid == placeId){
                return place
            }
        }
        
        return nil
    }
    
    func viewSite(sender: UIBarButtonItem){
        self.mapView?.setSiteView()
    }
    
    
    func mapLoaded(){
        dataManager?.fetch({
            self.displayAllPois()
            self.getAllLevels()
            self.displayAllPlaces()
        }, fail: { (_: [Error]?) in
            print("NO INTERNET CONNECTION")
        })
    }
    
    func displayAllPois(){
        //obtain all pois
        if dataManager != nil {
            
            self.poisArray = [ADSPoi]()
            
            for poi in (dataManager?.poiRepository.objects)! {
                let myPoi:ADSPoi = poi as! ADSPoi
                self.poisArray.append(myPoi)
            }
            
            poiDelegate?.updatePoi(pois: self.poisArray)
        }
    }
    
    func displayAllPlaces(){
        //obtain all places.
        if dataManager != nil {
            self.placesArray = [ADSPlace]()
            
            for place in (dataManager?.placeRepository.objects)!{
                let myPlace:ADSPlace = place as! ADSPlace
                self.placesArray.append(myPlace)
            }
            
        }
    }
    
    func getAllLevels(){
        
        //obtain levels.
        //Note: currently floors display as floor id
        
        
        let buildings = mapView?.getBuildings();
        if let levels = mapView?.getFloorsWithBuilding(buildings?.first as! NSNumber){
            mapView?.setCurrentFloor(levels.first as! NSNumber);
            for level in levels{
                self.floors.append(String(describing:level))
            }
        }
    }
    
    func drawPath(toPoiName: String, fromPoiName: String){
        let poiTo = findADSPlaceFromPoiName(poiName: toPoiName)
        let poiFrom = findADSPlaceFromPoiName(poiName: fromPoiName)
        
        //unable to check for whether path is already drawn.
        //removePath causes a runtime error if path is not drawn.
        
        if (poiTo != nil && poiFrom != nil){
            mapView?.setCurrentFloor(poiTo?.floorId)
            mapView?.hightlightADSPlace(poiTo, with: UIColor.green, andBounce: 1)
            mapView?.drawPath(from: poiFrom!, to: poiTo!, forPrm: false)
        }
    }
}
