//
//  MainViewController.swift
//  AdsumReaderSwift
//
//  Created by Christopher Yeo on 4/1/18.
//  Copyright © 2018 adactive. All rights reserved.
//

import UIKit
import Adsum
import SWXMLHash
import LUAutocompleteView

protocol MapButtonsDelegate{
    func floorChangeButtonClicked(floor: Int, sender: UIBarButtonItem)
    func viewSite(sender: UIBarButtonItem)
    func drawPath(toPoiName: String, fromPoiName: String)
}

class MainViewController: UIViewController, PoiDelegate, DrawPathDelegate{
    
    @IBOutlet weak var mapContainerView: UIView!
    @IBOutlet weak var cameraButton: UIBarButtonItem!
    
    
    var mapDelegate : MapButtonsDelegate?
    private var elements = [String]()
    
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view.
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    @IBAction func floorChangeButton(_ sender: UIBarButtonItem) {
        
        if (mapDelegate != nil){
            mapDelegate?.floorChangeButtonClicked(floor: 1, sender: sender);
        }
        
    }
    
    
    @IBAction func homeButtonClicked(_ sender: UIBarButtonItem) {
        if (mapDelegate != nil){
            mapDelegate?.viewSite(sender: sender);
        }
    }
    
    @IBAction func drawPathButtonClicked(_ sender: UIBarButtonItem) {
    }
    
    func updatePoi(pois: [ADSPoi]){
        elements = pois.map({$0.name})
        print("poi updated")
    }
    
    func displayPath(toPoiName: String, fromPoiName: String) {
        self.mapDelegate?.drawPath(toPoiName: toPoiName, fromPoiName: fromPoiName)
    }

//     //MARK: - Navigation
//     //In a storyboard-based application, you will often want to do a little preparation before navigation
    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        if (segue.identifier == "segueToMap"){
            guard let nextVc = segue.destination as? MapViewController
            else {
                return
            }
            self.mapDelegate = nextVc
            nextVc.poiDelegate = self
        } else if (segue.identifier == "displayPathSegue"){
            guard let nextVc = segue.destination as? DrawPathViewController
                else {
                    return
            }
            nextVc.drawPathDelegate = self
            nextVc.elements = self.elements
        }
    }

}


