//
//  DrawPathViewController.swift
//  AdsumReaderSwift
//
//  Created by Christopher Yeo on 5/1/18.
//  Copyright © 2018 adactive. All rights reserved.
//

import UIKit
import LUAutocompleteView

protocol DrawPathDelegate{
    func displayPath(toPoiName: String, fromPoiName: String)
}

class DrawPathViewController: UIViewController {

    @IBOutlet weak var fromPathTextField: UITextField!
    @IBOutlet weak var toPathTextField: UITextField!
    private let autocompleteViewTo = LUAutocompleteView()
    private let autocompleteViewFrom = LUAutocompleteView()

    var elements : [String] = []
    
    var drawPathDelegate : DrawPathDelegate?
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        view.addSubview(autocompleteViewTo)
        autocompleteViewTo.textField = toPathTextField
        autocompleteViewTo.dataSource = self
        autocompleteViewTo.delegate = self
        
        view.addSubview(autocompleteViewFrom)
        autocompleteViewFrom.textField = fromPathTextField
        autocompleteViewFrom.dataSource = self
        autocompleteViewFrom.delegate = self


        // Do any additional setup after loading the view.
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    
    @IBAction func searchPath(_ sender: UIButton) {
        
        if let  toPathPoi = toPathTextField.text {
            if let fromPathPoi = fromPathTextField.text {
                self.drawPathDelegate?.displayPath(toPoiName: toPathPoi, fromPoiName: fromPathPoi)
                self.navigationController?.popViewController(animated: true);
            }
        } else {
            let alert = UIAlertController(title: "Alert", message: "Missing Fields", preferredStyle: UIAlertControllerStyle.alert)
            alert.addAction(UIAlertAction(title: "Ok", style: UIAlertActionStyle.default, handler: nil))
            self.present(alert, animated: true, completion: nil)
            
        }
        
        guard let toPathPoi = toPathTextField.text else {
//            show("No To Path POI", sender: )
            return
        }
        
        guard let fromPathPoi = fromPathTextField.text else {
            //show("No From Path POI", sender: <#Any?#>)
            return
        }
        
        self.drawPathDelegate?.displayPath(toPoiName: toPathPoi, fromPoiName: fromPathPoi)
        self.navigationController?.popViewController(animated: true);
        
    }
    
    //cancel and go back to previous screen
    @IBAction func cancel(_ sender: UIButton) {
        self.navigationController?.popViewController(animated: true);
    }
    

}

extension DrawPathViewController: LUAutocompleteViewDataSource {
    func autocompleteView(_ autocompleteView: LUAutocompleteView, elementsFor text: String, completion: @escaping ([String]) -> Void) {
        let elementsThatMatchInput = elements.filter { $0.lowercased().contains(text.lowercased()) }
        completion(elementsThatMatchInput)
    }
}

// MARK: - LUAutocompleteViewDelegate
extension DrawPathViewController: LUAutocompleteViewDelegate {
    func autocompleteView(_ autocompleteView: LUAutocompleteView, didSelect text: String) {
        print(text + " was selected from autocomplete view")
    }
}
