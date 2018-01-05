//
//  InitialViewController.swift
//  AdsumReaderSwift
//
//  Created by Christopher Yeo on 3/1/18.
//  Copyright © 2018 adactive. All rights reserved.
//

import UIKit
import AVFoundation
import QRCodeReader

class InitialViewController: UIViewController, QRCodeReaderViewControllerDelegate{
    
    let CONFIG_KEY = "AdsumConfigXml"
    let SEGUE_TO_MAIN_KEY = "segueToMain"
    
    var currentConfigXml = String()
    
    @IBOutlet weak var loadSavedMapButton: UIButton!

    
    override func viewDidLoad() {
        super.viewDidLoad()
        
//      for Testing Purposes - Remove before pr to master
//        if let bundleID = Bundle.main.bundleIdentifier {
//            UserDefaults.standard.removePersistentDomain(forName: bundleID)
//        }

        
        let defaults = UserDefaults.standard
        if let xml = defaults.string(forKey: CONFIG_KEY){
            if (xml.isEmpty){
                print(xml)
                loadSavedMapButton.isEnabled = false
            } else {
                currentConfigXml = xml
            }
        } else {
            print("Nothing Saved in XML")
            loadSavedMapButton.isEnabled = false
        }
    }
    
    // create the reader lazily
    lazy var readerViewControl: QRCodeReaderViewController = {
        let builder = QRCodeReaderViewControllerBuilder {
            $0.reader = QRCodeReader(metadataObjectTypes: [.qr], captureDevicePosition: .back)
        }
        
        return QRCodeReaderViewController(builder: builder)
    }()

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    
    private func checkScanPermissions() -> Bool {
        do {
            return try QRCodeReader.supportsMetadataObjectTypes()
        } catch let error as NSError {
            let alert: UIAlertController
            
            switch error.code {
            case -11852:
                alert = UIAlertController(title: "Error", message: "This app is not authorized to use Back Camera.", preferredStyle: .alert)
                
                alert.addAction(UIAlertAction(title: "Setting", style: .default, handler: { (_) in
                    DispatchQueue.main.async {
                        if let settingsURL = URL(string: UIApplicationOpenSettingsURLString) {
                            UIApplication.shared.open(settingsURL, options:[:], completionHandler:nil)
                        }
                    }
                }))
                
                alert.addAction(UIAlertAction(title: "Cancel", style: .cancel, handler: nil))
            default:
                alert = UIAlertController(title: "Error", message: "QR Code Reading is not available for your device. Please contact Adactive for further help.", preferredStyle: .alert)
                alert.addAction(UIAlertAction(title: "OK", style: .cancel, handler: nil))
            }
            
            present(alert, animated: true, completion: nil)
            
            return false
        }
    }
    
    
    //for the "Load a Previously Saved Map" Button
    @IBAction func loadPreviouslySavedMap(_ sender: UIButton) {
        
        let defaults = UserDefaults.standard
        if let xml = defaults.string(forKey: CONFIG_KEY){
            if (!xml.isEmpty){
                print(xml)
                DispatchQueue.main.async() {
                    [unowned self] in
                    self.performSegue(withIdentifier: self.SEGUE_TO_MAIN_KEY, sender: self)
                    
                }
            }
        } else {
            print("Nothing Saved in XML")
            loadSavedMapButton.isEnabled = false
        }
        
    }
    
    // for the "Scan and Load a New Map" Button
    @IBAction func loadQRCodeScanner(_ sender: UIButton) {
        guard checkScanPermissions() else { return }
        
        // Retrieve the QRCode content by using the delegate pattern provided by the library
        readerViewControl.delegate = self
        
        // Presents the QR's readerViewControl as modal form sheet
        readerViewControl.modalPresentationStyle = .formSheet
        present(readerViewControl, animated: true, completion: nil)
    }
    
    func reader(_ reader: QRCodeReaderViewController, didScanResult result: QRCodeReaderResult) {
        reader.stopScanning()
        dismiss(animated: true) {
            print("QR CODE: \(result)")
            
            if let bundleID = Bundle.main.bundleIdentifier {
                UserDefaults.standard.removePersistentDomain(forName: bundleID)
            }
            
            self.currentConfigXml = result.value
            let defaults = UserDefaults.standard
            defaults.set(self.currentConfigXml, forKey: self.CONFIG_KEY)
            DispatchQueue.main.async() {
                [unowned self] in
                self.performSegue(withIdentifier: self.SEGUE_TO_MAIN_KEY, sender: self)
                
            }
        }
        
    }
    
    func initiateSegue(){
        
    }
    
    //This is an optional delegate method, that allows you to be notified when the user switches the cameraName
    //By pressing on the switch camera button
    func reader(_ reader: QRCodeReaderViewController, didSwitchCamera newCaptureDevice: AVCaptureDeviceInput) {
        let cameraName = newCaptureDevice.device.localizedName
        print("Switching capturing to: \(cameraName)")
        
    }
    
    func readerDidCancel(_ reader: QRCodeReaderViewController) {
        reader.stopScanning()
        
        dismiss(animated: true, completion: nil)
    }

}
