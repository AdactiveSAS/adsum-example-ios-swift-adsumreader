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

protocol MapButtonsDelegate{
    func floorChangeButtonClicked(floor: Int, sender: UIBarButtonItem)
}

class MainViewController: UIViewController {
    
    
    @IBOutlet weak var mapContainerView: UIView!
    var mapDelegate : MapButtonsDelegate?
    
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
    
    

//     //MARK: - Navigation
//
//     //In a storyboard-based application, you will often want to do a little preparation before navigation
    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        if (segue.identifier == "segueToMap"){
            guard let nextVc = segue.destination as? MapViewController
            else {
                return
            }
            print("did we set?")
            self.mapDelegate = nextVc
        }
    }

}
