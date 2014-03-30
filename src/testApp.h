#pragma once

//#include "ofMain.h"
//#include "ofxiPhone.h"
//#include "ofxiPhoneExtras.h"
#include "ofMain.h"
#include "ofxiOS.h"
#include "ofxiOSExtras.h"

#include "ofxXmlSettings.h"
#include "ofxMaxim.h"
#include <sys/time.h>
#include "ofxUI.h"
#include "buttonSig.h"
#include "MasatXMLData.h"

#include "ofxFTGLESFont.h"

#include "maxiMFCC.h"
#include "MasatAudioData.h"
#include <time.h>
#include "timer.h"

#include <iostream>
#include <string>

//class testApp : public ofxiPhoneApp{
class testApp : public ofxiOSApp{
public:
    ~testApp();
    void setup();
    void update();
    void draw();
    void exit();
	
    void touchDown(ofTouchEventArgs & touch);
    void touchMoved(ofTouchEventArgs & touch);
    void touchUp(ofTouchEventArgs & touch);
    void touchDoubleTap(ofTouchEventArgs & touch);
    void touchCancelled(ofTouchEventArgs & touch);
    
    void lostFocus();
    void gotFocus();
    void gotMemoryWarning();
    void deviceOrientationChanged(int newOrientation);
    ofxUICanvas *gui;
    
    buttonSig testButtonClass1;
    buttonSig testButtonClass2;
    
    void guiEvent(ofxUIEventArgs &e);
    bool drawPadding;
	float red, green, blue;
	float dim;
    
    const float Gradius = 220.0;
    
    ofImage bg;
    
    MasatXMLData masatXML;
    MasatAudioData masatAudio;
    
    int previousCount;
    int count;
    
    ofTrueTypeFont verdana;
    ofxFTGLESFont NewMediaFett;
    ofxFTGLESFont ArialUnicode;
    
    ofColor small;
    ofColor biggerOutside;
    ofColor biggerInside;
    
    vector<buttonSig> PanelDataButton;
    vector<buttonSig> BoardDataButton;

    
    time_t time1sec;
    time_t time2sec;
    int days;
    struct tm time1, * time2;
    
    bool goingChange;
    bool goingChangeTimeLine;
    int goingChangeRotateAngle;
    bool timelinecontrolorisRotated;
    
    bool infovisible;
    
    ofColor tempColorforDrawFill;
    
    ofxUILabel *LabelTest;
    vector<ofxUILabel*> TestLabel;
    
    ofImage inforPanelSrc;
    ofImage inforPanel_blink_Src;
    ofxUIImage * inforPanel;
    ofxUIImage * inforPanel_blink;
    
    ofImage inforButtonSrc;
    ofxUIImageButton * inforButton;
    
    ofImage *infoPanel_location_Button_PanelSrc;
    ofImage *infoPanel_location_Button_Panel_blink_Src;
    ofxUIImageButton * infoPanel_location_Button;
    bool flag_infoPanel_location_Button;
    
    ofImage *infoPanel_temperature_Button_PanelSrc;
    ofImage *infoPanel_temperature_Button_Panel_blink_Src;
    ofxUIImageButton * infoPanel_temperature_Button;
    bool flag_infoPanel_temperature_Button;
    
    ofImage *infoPanel_voltage_Button_PanelSrc;
    ofImage *infoPanel_voltage_Button_Panel_blink_Src;
    ofxUIImageButton * infoPanel_voltage_Button;
    bool flag_infoPanel_voltage_Button;
    
    ofImage *infoPanel_TimeLine_Button_PanelSrc;
    ofImage *infoPanel_TimeLine_Button_Panel_blink_Src;
    ofxUIImageButton * infoPanel_TimeLine_Button;
    bool flag_infoPanel_TimeLine_Button;
    
    ofImage *infoPanel_onBoardTemperature_Button_PanelSrc;
    ofImage *infoPanel_onBoardTemperature_Button_Panel_blink_Src;
    ofxUIImageButton * infoPanel_onBoardTemperature_Button;
    bool flag_infoPanel_onBoardTemperature_Button;
    
    ofImage *infoPanel_timetracker_Button_PanelSrc;
    ofImage *infoPanel_timetracker_Button_Panel_blink_Src;
    ofxUIImageButton * infoPanel_timetracker_Button;
    bool flag_infoPanel_timetracker_Button;
    
    void audioRequested 	(float * input, int bufferSize, int nChannels); /* output method */
	void audioReceived 	(float * input, int bufferSize, int nChannels); /* input method */
	
	float 	* lAudioOut; /* outputs */
	float   * rAudioOut;
    
	float * lAudioIn; /* inputs */
	float * rAudioIn;
	
	int		initialBufferSize; /* buffer size */
	int		sampleRate;
	
    int weekcount;
    int weeknumber;
    
    //ofxgif
    
	float infotransparentcy;
    
    timer weektimer;
    timer daytimer;
    timer blinktimer;
    
	/* stick you maximilian stuff below */
	
	double wave,sample,outputs[2], ifftVal;
	maxiMix mymix;
	maxiOsc osc;
	
	ofxMaxiFFTOctaveAnalyzer oct;
	int nAverages;
	float *ifftOutput;
	int ifftSize;
	
	ofxMaxiIFFT ifft;
	ofxMaxiFFT mfft;
	int fftSize;
	int bins, dataSize;
	
	float callTime;
	timeval callTS, callEndTS;
	
	maxiMFCC mfcc;
	double *mfccs;
    

    
	maxiSample samp;
    string converFloat(float number)
    {
        stringstream ss (stringstream::in | stringstream::out);
        ss << number;
        string str = ss.str();
        return str;
        
    }
    void AudioDraw()
    {
        float xinc = 900.0 / fftSize * 2.0;
        
        
        ofPushMatrix();
        ofTranslate(ofGetWidth(), -20);
        xinc = 1024.0 / 21.0;
        
        ofNoFill();
        ofSetColor(0, 155);
        ofBeginShape();
        ofVertex(0, 0);
        for(int i=1; i < 21; i++) {
            float height = mfcc.melBands[i] * 10.0;
            ofVertex(height, 0 + (i*xinc));
        }
        ofVertex(0, 1080);
        ofEndShape();
        
        
        ofSetColor(197,97,22,100);
        ofFill();
        ofBeginShape();
        ofVertex(0, 0);
        for(int i=1; i < 21; i++) {
            float height = mfcc.melBands[i] * 10.0;
            ofVertex(height, 0 + (i*xinc));
        }
        ofVertex(0, 1080);
        ofEndShape();
        
        ofNoFill();
        ofSetColor(0, 155);
        ofBeginShape();
        ofVertex(0, 0);
        for(int i=1; i < 21; i++) {
            float height = mfcc.melBands[i] * 8.0;
            ofVertex(height, 0 + (i*xinc));
        }
        ofVertex(0, 1080);
        ofEndShape();
        
        ofSetColor(197,77,87,100);
        ofFill();
        ofBeginShape();
        ofVertex(0, 0);
        for(int i=1; i < 21; i++) {
            float height = mfcc.melBands[i] * 8.0;
            ofVertex(height, 0 + (i*xinc));
        }
        ofVertex(0, 1080);
        ofEndShape();
        
        ofNoFill();
        ofSetColor(0, 155);
        ofBeginShape();
        ofVertex(0, 0);
        for(int i=1; i < 21; i++) {
            float height = mfcc.melBands[i] * 6.0;
            ofVertex(height, 0 + (i*xinc));
        }
        ofVertex(0, 1080);
        ofEndShape();
        
        ofSetColor(143,59,74,100);
        ofFill();
        ofBeginShape();
        ofVertex(0, 0);
        for(int i=1; i < 21; i++) {
            float height = mfcc.melBands[i] * 6.0;
            ofVertex(height, 0 + (i*xinc));
        }
        ofVertex(0, 1080);
        ofEndShape();
        
        ofNoFill();
        ofSetColor(0, 155);
        ofBeginShape();
        ofVertex(0, 0);
        for(int i=1; i < 21; i++) {
            float height = mfcc.melBands[i] * 4.0;
            ofVertex(height, 0 + (i*xinc));
        }
        ofVertex(0, 1080);
        ofEndShape();
        
        ofSetColor(134,69,103,100);
        ofFill();
        ofBeginShape();
        ofVertex(0, 0);
        for(int i=1; i < 21; i++) {
            float height = mfcc.melBands[i] * 4.0;
            ofVertex(height, 0 + (i*xinc));
        }
        ofVertex(0, 1080);
        ofEndShape();
        
        ofNoFill();
        ofSetColor(0, 155);
        ofBeginShape();
        ofVertex(0, 0);
        for(int i=1; i < 21; i++) {
            float height = mfcc.melBands[i] * 2.0;
            ofVertex(height, 0 + (i*xinc));
        }
        ofVertex(0, 1080);
        ofEndShape();
        
        ofSetColor(90,66,88,100);
        ofFill();
        ofBeginShape();
        ofVertex(0, 0);
        for(int i=1; i < 21; i++) {
            float height = mfcc.melBands[i] * 2.0;
            ofVertex(height, 0 + (i*xinc));
        }
        ofVertex(0, 1080);
        ofEndShape();
        
        ofPopMatrix();
        
    }
    
    void FadeIn()
    {
        for (int i = 0; i < 9; i++)
        {
            if (PanelDataButton[i].myButton->isVisible())
            {
                if (PanelDataButton[i].myButton->getColorFill().a <= 20 )
                {
                    PanelDataButton[i].myButton->setValue(false);
                    PanelDataButton[i].bDragged = -1;
                    PanelDataButton[i].myButton->setVisible(false);
                }
                else
                {
                    PanelDataButton[i].ColorButtonFill = ofColor(PanelDataButton[i].ColorButtonFill, PanelDataButton[i].ColorButtonFill.a - 60);
                    PanelDataButton[i].myButton->setColorFill(PanelDataButton[i].ColorButtonFill);
                    PanelDataButton[i].ColorButtonHighLight = ofColor(PanelDataButton[i].ColorButtonHighLight, PanelDataButton[i].ColorButtonHighLight.a - 60);
                }
            }
        }
        // for button 10, time controller
        if (PanelDataButton[10].myButton->isVisible())
        {
            if (PanelDataButton[10].myButton->getColorFill().a <= 0 ) {
                PanelDataButton[10].myButton->setValue(false);
                PanelDataButton[10].bDragged = -1;
                PanelDataButton[10].myButton->setVisible(false);
            }
            else
            {
                PanelDataButton[10].ColorButtonFill = ofColor(PanelDataButton[10].ColorButtonFill, PanelDataButton[10].ColorButtonFill.a - 40);
                PanelDataButton[10].myButton->setColorFill(PanelDataButton[10].ColorButtonFill);
                PanelDataButton[10].ColorButtonHighLight = ofColor(PanelDataButton[10].ColorButtonHighLight, PanelDataButton[10].ColorButtonHighLight.a - 40);
            }
        }

    }
    
    void FadeOut()
    {
        for (int i = 0; i < 9; i++)
        {
            if (!PanelDataButton[i].myButton->isVisible())
            {
                PanelDataButton[i].myButton->setVisible(true);
            }
            
            if (PanelDataButton[i].myButton->getColorFill().a >= 200 ) {
            }
            else
            {
                PanelDataButton[i].ColorButtonFill = ofColor(PanelDataButton[i].ColorButtonFill, PanelDataButton[i].ColorButtonFill.a + 60);
                PanelDataButton[i].myButton->setColorFill(PanelDataButton[i].ColorButtonFill);
                PanelDataButton[i].ColorButtonHighLight = ofColor(PanelDataButton[i].ColorButtonHighLight, PanelDataButton[i].ColorButtonHighLight.a + 60);
            }
        }
        if (!PanelDataButton[10].myButton->isVisible())
        {
            PanelDataButton[10].myButton->setVisible(true);
        }
        
        if (PanelDataButton[10].myButton->getColorFill().a >= 40 ) {
        }
        else
        {
            PanelDataButton[10].ColorButtonFill = ofColor(PanelDataButton[10].ColorButtonFill, PanelDataButton[10].ColorButtonFill.a + 40);
            PanelDataButton[10].myButton->setColorFill(PanelDataButton[10].ColorButtonFill);
            PanelDataButton[10].ColorButtonHighLight = ofColor(PanelDataButton[10].ColorButtonHighLight, PanelDataButton[10].ColorButtonHighLight.a + 40);
        }
    }
    
    void FadeIn2()
    {
        for (int i = 0; i < 6; i++)
        {
            if (PanelDataButton[i].myButton->isVisible())
            {
                if (PanelDataButton[i].myButton->getColorFill().a <= 20 )
                {
                    PanelDataButton[i].myButton->setValue(false);
                    PanelDataButton[i].bDragged = -1;
                    PanelDataButton[i].myButton->setVisible(false);
                }
                else
                {
                    PanelDataButton[i].ColorButtonFill = ofColor(PanelDataButton[i].ColorButtonFill, PanelDataButton[i].ColorButtonFill.a - 60);
                    PanelDataButton[i].myButton->setColorFill(PanelDataButton[i].ColorButtonFill);
                    PanelDataButton[i].ColorButtonHighLight = ofColor(PanelDataButton[i].ColorButtonHighLight, PanelDataButton[i].ColorButtonHighLight.a - 60);
                }
            }
        }
        // for button 10, time controller
        if (PanelDataButton[10].myButton->isVisible())
        {
            if (PanelDataButton[10].myButton->getColorFill().a <= 0 ) {
                PanelDataButton[10].myButton->setValue(false);
                PanelDataButton[10].bDragged = -1;
                PanelDataButton[10].myButton->setVisible(false);
            }
            else
            {
                PanelDataButton[10].ColorButtonFill = ofColor(PanelDataButton[10].ColorButtonFill, PanelDataButton[10].ColorButtonFill.a - 40);
                PanelDataButton[10].myButton->setColorFill(PanelDataButton[10].ColorButtonFill);
                PanelDataButton[10].ColorButtonHighLight = ofColor(PanelDataButton[10].ColorButtonHighLight, PanelDataButton[10].ColorButtonHighLight.a - 40);
            }
        }
        
    }
    
    void FadeOut2()
    {
        for (int i = 0; i < 6; i++)
        {
            if (!PanelDataButton[i].myButton->isVisible())
            {
                PanelDataButton[i].myButton->setVisible(true);
            }
            
            if (PanelDataButton[i].myButton->getColorFill().a >= 200 ) {
            }
            else
            {
                PanelDataButton[i].ColorButtonFill = ofColor(PanelDataButton[i].ColorButtonFill, PanelDataButton[i].ColorButtonFill.a + 60);
                PanelDataButton[i].myButton->setColorFill(PanelDataButton[i].ColorButtonFill);
                PanelDataButton[i].ColorButtonHighLight = ofColor(PanelDataButton[i].ColorButtonHighLight, PanelDataButton[i].ColorButtonHighLight.a + 60);
            }
        }
        if (!PanelDataButton[10].myButton->isVisible())
        {
            PanelDataButton[10].myButton->setVisible(true);
        }
        
        if (PanelDataButton[10].myButton->getColorFill().a >= 40 ) {
        }
        else
        {
            PanelDataButton[10].ColorButtonFill = ofColor(PanelDataButton[10].ColorButtonFill, PanelDataButton[10].ColorButtonFill.a + 40);
            PanelDataButton[10].myButton->setColorFill(PanelDataButton[10].ColorButtonFill);
            PanelDataButton[10].ColorButtonHighLight = ofColor(PanelDataButton[10].ColorButtonHighLight, PanelDataButton[10].ColorButtonHighLight.a + 40);
        }
    }
};


