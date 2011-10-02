//
//  BridgeRunnerAppController.h
//  BridgeRunner
//
//  Created by Ole Andre Birkedal on 8/9/11.
//  Copyright Extab 2011. All rights reserved.
//

@class RootViewController;

@interface AppController : NSObject <UIAccelerometerDelegate, UIAlertViewDelegate, UITextFieldDelegate,UIApplicationDelegate> {
    UIWindow *window;
    RootViewController	*viewController;
}

@end

