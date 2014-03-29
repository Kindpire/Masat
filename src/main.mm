#include "ofMain.h"
#include "testApp.h"

int main(){
    
//    ofAppiPhoneWindow * iOSWindow = new ofAppiPhoneWindow();
//	iOSWindow->enableAntiAliasing(4);
//	
//	iOSWindow->enableRetinaSupport();
//	iOSWindow->enableDepthBuffer();
//	ofSetupOpenGL(iOSWindow, 1024, 768, OF_FULLSCREEN);
    ofSetupOpenGL(1024,768, OF_FULLSCREEN);
	ofRunApp(new testApp);
}
