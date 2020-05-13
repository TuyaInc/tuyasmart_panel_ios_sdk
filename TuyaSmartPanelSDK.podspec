Pod::Spec.new do |s|
  s.name = "TuyaSmartPanelSDK"
  s.version = "0.4.0"
  s.summary = "A short description of TuyaSmartPanelSDK."
  s.license = {"type"=>"MIT"}
  s.authors = { 'TuyaInc' => 'https://www.tuya.com' }
  s.homepage = 'https://github.com/TuyaInc'
  s.description = "TODO: Add long description of the pod here."
  s.source = { :http => "https://airtake-public-data-1254153901.cos.ap-shanghai.myqcloud.com/smart/app/package/sdk/ios/#{s.name}-#{s.version}.zip", :type => "zip" }
  s.static_framework = true
  s.ios.deployment_target = '9.0'
  s.ios.vendored_framework = 'ios/*.framework'
  
  s.dependency 'TYPanelModule', '2.1.2'
  s.dependency 'TYTimerModule'
  s.dependency 'TYLanguageBundleRegister'
  s.dependency 'TuyaRNApi/Basic'
  # SDK
  s.dependency 'TuyaSmartDeviceKit'
  s.dependency 'TuyaSmartBLEKit'
  s.dependency 'TuyaSmartBLEMeshKit'
  s.dependency 'TuyaSmartSceneKit'
  
end
