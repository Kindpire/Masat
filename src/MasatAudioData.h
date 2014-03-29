//
//  MasatAudioData.h
//  UniverseMasatIB
//
//  Created by Kindpire on 12-11-10.
//  Copyright (c) 2012年 __MyCompanyName__. All rights reserved.
//

#ifndef UniverseMasatIB_MasatAudioData_h
#define UniverseMasatIB_MasatAudioData_h

#include "ofxMaxim.h"
#include <sys/time.h>
#include "maxiMFCC.h"

class MasatAudioData
{
    public:
    
    void AudioDraw(int fftSizeInput, double arraytest[])
    {
        float xinc = 900.0 / fftSizeInput * 2.0;
        //ofSoundGetSpectrum(2);
        
        ofPushMatrix();

        xinc = 1024.0 / 21.0;
        
        ofNoFill();    
        ofSetColor(0, 155);
        ofBeginShape();
        ofVertex(0, ofGetHeight());
        for(int i=1; i < 21; i++) {
            float height = arraytest[i] * 10.0;
            ofVertex(0 + (i*xinc), ofGetHeight() + height);
        }
        ofVertex(1080, ofGetHeight());
        ofEndShape();
        

        
        ofSetColor(197,97,22,100);
        ofFill();
        ofBeginShape();
        ofVertex(0, ofGetHeight());
        for(int i=1; i < 21; i++) {
            float height = arraytest[i] * 10.0;
            ofVertex(0 + (i*xinc), ofGetHeight() + height);
        }
        ofVertex(1080, ofGetHeight());
        ofEndShape();
        
        
        ofNoFill();    
        ofSetColor(0, 155);
        ofBeginShape();
        ofVertex(0, ofGetHeight());
        for(int i=1; i < 21; i++) {
            float height = arraytest[i] * 8.0;
            ofVertex(0 + (i*xinc), ofGetHeight() + height);
        }
        ofVertex(1080, ofGetHeight());
        ofEndShape();
        
        ofSetColor(197,77,87,100);
        ofFill();
        ofBeginShape();
        ofVertex(0, ofGetHeight());
        for(int i=1; i < 21; i++) {
            float height = arraytest[i] * 8.0;
            ofVertex(0 + (i*xinc), ofGetHeight() + height);
        }
        ofVertex(1080, ofGetHeight());
        ofEndShape();
        
        ofNoFill();    
        ofSetColor(0, 155);
        ofBeginShape();
        ofVertex(0, ofGetHeight());
        for(int i=1; i < 21; i++) {
            float height = arraytest[i] * 6.0;
            ofVertex(0 + (i*xinc), ofGetHeight() + height);
        }
        ofVertex(1080, ofGetHeight());
        ofEndShape();
        
        ofSetColor(143,59,74,100);
        ofFill();
        ofBeginShape();
        ofVertex(0, ofGetHeight());
        for(int i=1; i < 21; i++) {
            float height = arraytest[i] * 6.0;
            ofVertex(0 + (i*xinc), ofGetHeight() + height);
        }
        ofVertex(1080, ofGetHeight());
        ofEndShape();
        
        ofNoFill();    
        ofSetColor(0, 155);
        ofBeginShape();
        ofVertex(0, ofGetHeight());
        for(int i=1; i < 21; i++) {
            float height = arraytest[i] * 4.0;
            ofVertex(0 + (i*xinc), ofGetHeight() + height);
        }
        ofVertex(1080, ofGetHeight());
        ofEndShape();
        
        ofSetColor(134,69,103,100);
        ofFill();
        ofBeginShape();
        ofVertex(0, ofGetHeight());
        for(int i=1; i < 21; i++) {
            float height = arraytest[i] * 4.0;
            ofVertex(0 + (i*xinc), ofGetHeight() + height);
        }
        ofVertex(1080, ofGetHeight());
        ofEndShape();
        
        ofNoFill();    
        ofSetColor(0, 155);
        ofBeginShape();
        ofVertex(0, ofGetHeight());
        for(int i=1; i < 21; i++) {
            float height = arraytest[i] * 2.0;
            ofVertex(0 + (i*xinc), ofGetHeight() + height);
        }
        ofVertex(1080, ofGetHeight());
        ofEndShape();
        
        ofSetColor(90,66,88,100);
        ofFill();
        ofBeginShape();
        ofVertex(0, ofGetHeight());
        for(int i=1; i < 21; i++) {
            float height = arraytest[i] * 2.0;
            ofVertex(0 + (i*xinc), ofGetHeight() + height);
        }
        ofVertex(1080, ofGetHeight());
        ofEndShape();
        
        ofPopMatrix();

    }
    
};

#endif
