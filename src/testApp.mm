#include "testApp.h"
#include <iomanip>
//--------------------------------------------------------------
/*changed ofxUIImage to make it could change transparency
 
 ofFill();
 //ofSetColor(255, 255);
 ofSetColor(color_fill);
 image->draw(rect->getX(), rect->getY(), rect->width, rect->height);
 
 */
////--------------------------------------------------------------
testApp::~testApp() {
	
	//delete samp;
}
//--------------------------------------------------------------
void testApp::setup(){
	// initialize the accelerometer
	ofxAccelerometer.setup();
	
    ofSetCircleResolution(20);
    
    bg.loadImage("background.jpg");
    bg.setAnchorPercent(0.5, 0.5);
    
	//If you want a landscape oreintation
	ofSetOrientation(ofxiOS_ORIENTATION_LANDSCAPE_RIGHT);

	
	ofSetVerticalSync(true);
	ofEnableSmoothing();
    
    red = 255; blue = 255; green = 255;
	
	dim = 100;
    
    masatXML.XMLInit();
    
    time1.tm_year = 2012 - 1900;
    time1.tm_mon = 10;
    time1.tm_mday = 19;
    time1.tm_hour = 10;
    time1.tm_min = 0;
    time1.tm_sec = 0;
    time1.tm_isdst = 0;
    
    small = ofColor(100, 45, 40, 150);
    
    biggerOutside = ofColor(146, 71, 44, 150);
    biggerInside = ofColor(204, 99, 69, 150);
    
    
    drawPadding = false;
    
    gui = new ofxUICanvas(0,0,ofGetWidth(),ofGetHeight());
    
    inforButtonSrc.loadImage("button1lil.png");
    inforButtonSrc.setAnchorPercent(0.5, 0.5);
    inforButton  = new ofxUIImageButton(36, 36, true, "smallIcon.png", "inforButton");
    gui->addWidgetDown(inforButton);
    
    inforButton->getRect()->x = 990 - 15;
    inforButton->getRect()->y = 29 - 15;
    inforButton->setColorFill(ofColor(255, 95));
    
    //设置infoPanel上的各种button
    //1. location
    infoPanel_location_Button_PanelSrc = new ofImage("START_NEW-9GOOD14_CIRCLE5_dark1.png");
    infoPanel_location_Button_PanelSrc->setAnchorPercent(0.5, 0.5);
    infoPanel_location_Button_Panel_blink_Src = new ofImage("START_NEW-9GOOD14_circle5dark2.png");
    infoPanel_location_Button_Panel_blink_Src->setAnchorPercent(0.5, 0.5);
    
    infoPanel_location_Button  = new ofxUIImageButton(85, 85, true, "000000-0.png", "infoPanel_location_Button");
    gui->addWidgetDown(infoPanel_location_Button);
    
    infoPanel_location_Button->getRect()->x = 848 - 85/2;
    infoPanel_location_Button->getRect()->y = 483 - 85/2;
    
    
    //2. Temperature
    infoPanel_temperature_Button_PanelSrc = new ofImage("insidepanel4png.png");
    infoPanel_temperature_Button_PanelSrc->setAnchorPercent(0.5, 0.5);
    infoPanel_temperature_Button_Panel_blink_Src = new ofImage("insidepanel3png.png");
    infoPanel_temperature_Button_Panel_blink_Src->setAnchorPercent(0.5, 0.5);
    
    infoPanel_temperature_Button  = new ofxUIImageButton(85, 85, true, "000000-0.png", "infoPanel_temperature_Button");
    
    gui->addWidgetDown(infoPanel_temperature_Button);
    
    infoPanel_temperature_Button->getRect()->x = 196 - 85/2;
    infoPanel_temperature_Button->getRect()->y = 411 - 85/2;
    
    //3. Voltage
    infoPanel_voltage_Button_PanelSrc = new ofImage("insidepanel4png.png");
    infoPanel_voltage_Button_PanelSrc->setAnchorPercent(0.5, 0.5);
    infoPanel_voltage_Button_Panel_blink_Src = new ofImage("insidepanel3png.png");
    infoPanel_voltage_Button_Panel_blink_Src->setAnchorPercent(0.5, 0.5);
    infoPanel_voltage_Button  = new ofxUIImageButton(146, 146, true, "000000-0.png", "infoPanel_voltage_Button");
    
    gui->addWidgetDown(infoPanel_voltage_Button);
    
    infoPanel_voltage_Button->getRect()->x = 196 - 146/2;
    infoPanel_voltage_Button->getRect()->y = 554 - 146/2;
    
    //4. Timeline
    infoPanel_TimeLine_Button_PanelSrc = new ofImage("START_NEW-9GOOD11_CIRCLE3_Dark.png");
    infoPanel_TimeLine_Button_PanelSrc->setAnchorPercent(0.5, 0.5);
    infoPanel_TimeLine_Button_Panel_blink_Src = new ofImage("START_NEW-9GOOD11_Circle3_light_-1.png");
    infoPanel_TimeLine_Button_Panel_blink_Src->setAnchorPercent(0.5, 0.5);
    infoPanel_TimeLine_Button  = new ofxUIImageButton(116, 116, true, "000000-0.png", "infoPanel_TimeLine_Button");
    
    gui->addWidgetDown(infoPanel_TimeLine_Button);
    
    infoPanel_TimeLine_Button->getRect()->x = 848 - 116/2;
    infoPanel_TimeLine_Button->getRect()->y = 197 - 116/2;
    
    //5. OnBoard Temperature
    infoPanel_onBoardTemperature_Button_PanelSrc = new ofImage("insidepanel2png.png");
    infoPanel_onBoardTemperature_Button_PanelSrc->setAnchorPercent(0.5, 0.5);
    infoPanel_onBoardTemperature_Button_Panel_blink_Src = new ofImage("insidepanel1png.png");
    infoPanel_onBoardTemperature_Button_Panel_blink_Src->setAnchorPercent(0.5, 0.5);
    infoPanel_onBoardTemperature_Button  = new ofxUIImageButton(118, 118, true, "000000-0.png", "infoPanel_onBoardTemperature_Button");
    gui->addWidgetDown(infoPanel_onBoardTemperature_Button);
    infoPanel_onBoardTemperature_Button->getRect()->x = 201 - 118/2;
    infoPanel_onBoardTemperature_Button->getRect()->y = 201 - 118/2;
    
    //6. timetracker
    infoPanel_timetracker_Button_PanelSrc = new ofImage("insidepanel5png.png");//what's the difference with insidepanel5png.png
    infoPanel_timetracker_Button_PanelSrc->setAnchorPercent(0.5, 0.5);
    infoPanel_timetracker_Button_Panel_blink_Src = new ofImage("insidepanel5png.png");
    infoPanel_timetracker_Button_Panel_blink_Src->setAnchorPercent(0.5, 0.5);
    infoPanel_timetracker_Button  = new ofxUIImageButton(167, 89, true, "000000-0.png","infoPanel_timetracker_Button");
    
    gui->addWidgetDown(infoPanel_timetracker_Button);
    
    infoPanel_timetracker_Button->getRect()->x = 848 - 167/2;
    infoPanel_timetracker_Button->getRect()->y = 347 - 89/2;
    infoPanel_timetracker_Button->setColorFill(ofColor(255, 255));
    
    ////////////////////////////////////////////////////////////////////////////////////////////
    infoPanel_location_Button->setVisible(false);
    infoPanel_temperature_Button->setVisible(false);
    infoPanel_voltage_Button->setVisible(false);
    infoPanel_TimeLine_Button->setVisible(false);
    infoPanel_onBoardTemperature_Button->setVisible(false);
    infoPanel_timetracker_Button->setVisible(false);
    
    /////////////////////////////////////////////////////////////////////////////////////////////
    inforPanelSrc.loadImage("START_NEW-9GOOD5.png");
    inforPanelSrc.setAnchorPercent(0.5, 0.5);
    inforPanel = new ofxUIImage(0, 0, inforPanelSrc.width, inforPanelSrc.height, &inforPanelSrc, "");
    inforPanel->getLabel()->setVisible(false);
    inforPanel->setVisible(false);
    
//    inforPanel->setColorFill(ofColor(255,255,255,0));
//    inforPanel->setColorFillHighlight(ofColor(255,255,255,0));
//    inforPanel->setColorBack(ofColor(255,255,255,0));
//    inforPanel->setColorPadded(ofColor(255,255,255,0));

    gui->addWidgetDown(inforPanel);
    inforPanel->getRect()->x = ofGetWidth()/2;
    inforPanel->getRect()->y = ofGetHeight()/2;
    
    inforPanel_blink_Src.loadImage("START_NEW-9GOOD5.png");
    inforPanel_blink_Src.setAnchorPercent(0.5, 0.5);
    inforPanel_blink = new ofxUIImage(0, 0, inforPanel_blink_Src.width, inforPanel_blink_Src.height, &inforPanelSrc, "");
    inforPanel_blink->getLabel()->setVisible(false);
    inforPanel_blink->setVisible(false);
//    inforPanel_blink->setColorFill(ofColor(255,255,255,100));
//    inforPanel_blink->setColorFillHighlight(ofColor(255,255,255,0));
//    inforPanel_blink->setColorBack(ofColor(255,255,255,0));
//    inforPanel_blink->setColorPadded(ofColor(255,255,255,0));
    gui->addWidgetDown(inforPanel_blink);
    inforPanel_blink->getRect()->x = ofGetWidth()/2;
    inforPanel_blink->getRect()->y = ofGetHeight()/2;
    
    PanelDataButton.assign(11, buttonSig());
    
    PanelDataButton[10].init(10, 50, 50, 0, -(5 + 32 * 11), ofGetWidth()/2, ofGetHeight()/2, "GUI/button.png", gui, false);
    PanelDataButton[9].init(9, 0, 0, 0, 0, ofGetWidth()/2, ofGetHeight()/2, "GUI/button.png", gui, false);
    PanelDataButton[8].init(8, 100, 100, 100, -100, ofGetWidth()/2, ofGetHeight()/2, "pw7.png", gui, false);
    PanelDataButton[7].init(7, 100, 100, -100, 100, ofGetWidth()/2, ofGetHeight()/2, "pw5.png", gui, false);
    PanelDataButton[6].init(6, 100, 100, 100, 100, ofGetWidth()/2, ofGetHeight()/2, "pw4.png", gui, false);
    PanelDataButton[5].init(5, 100, 100, -200, 200, ofGetWidth()/2, ofGetHeight()/2, "pir6.png", gui, ofColor(213, 204, 162, 200), ofColor(213, 204, 162, 240));
    PanelDataButton[4].init(4, 100, 100, 200, 200, ofGetWidth()/2, ofGetHeight()/2, "pir5.png", gui, ofColor(213, 204, 162, 200), ofColor(213, 204, 162, 240));
    PanelDataButton[3].init(3, 100, 100, -100, -200, ofGetWidth()/2, ofGetHeight()/2, "pir4.png", gui, ofColor(199, 167, 90, 200), ofColor(199, 167, 90, 240));
    PanelDataButton[2].init(2, 100, 100, 100, -200, ofGetWidth()/2, ofGetHeight()/2, "pir3.png", gui, ofColor(215, 90, 47, 200), ofColor(215, 90, 47, 240));
    PanelDataButton[1].init(1, 100, 100, 100, 200, ofGetWidth()/2, ofGetHeight()/2, "pir2.png", gui, ofColor(208, 168, 34, 200), ofColor(208, 168, 34, 240));
    PanelDataButton[0].init(0, 100, 100, 50, 200, ofGetWidth()/2, ofGetHeight()/2, "pir1.png", gui, ofColor(191, 18, 9, 200), ofColor(191, 18, 9, 240));
    
    //10 控制星期
    PanelDataButton[10].myButton->getRect()->setWidth(50);
    PanelDataButton[10].myButton->getRect()->setHeight(50);
    PanelDataButton[10].myButton->setValue(false);
    PanelDataButton[10].ColorButtonFill = ofColor(213, 204, 162, 40);
    PanelDataButton[10].myButton->setColorFill(ofColor(213, 204, 162, 40));
    PanelDataButton[10].ColorButtonHighLight = ofColor(213, 204, 162, 80);
    PanelDataButton[10].myButton->setColorFillHighlight(ofColor(0, 250, 50, 80));
    PanelDataButton[10].myButton->setDrawFillHighLight(false);
    PanelDataButton[10].myButton->setColorOutline(ofColor(0, 0, 255, 0));
    PanelDataButton[10].myButton->setColorOutlineHighlight(ofColor(0, 0, 255, 0));
    
    //9 为正中间控制所有按钮是否可见的按钮
    PanelDataButton[9].myButton->getRect()->setWidth(50);
    PanelDataButton[9].myButton->getRect()->setHeight(50);
    PanelDataButton[9].myButton->getRect()->x = ofGetWidth()/2 - 25;
    PanelDataButton[9].myButton->getRect()->y = ofGetHeight()/2 - 25;
    PanelDataButton[9].myButton->setValue(false);
    PanelDataButton[9].myButton->setColorFill(ofColor(250, 50, 50, 0));
    PanelDataButton[9].myButton->setDrawFillHighLight(false);
    PanelDataButton[9].myButton->setColorOutline(ofColor(0, 0, 255, 0));
    PanelDataButton[9].myButton->setColorOutlineHighlight(ofColor(0, 0, 255, 0));
    
    ofAddListener(gui->newGUIEvent,this,&testApp::guiEvent);
	
    ofBackground(red, green, blue);
    
    
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    //sampleRate 			= 44100;
	initialBufferSize	= 512;
	lAudioOut			= new float[initialBufferSize];
	rAudioOut			= new float[initialBufferSize];
	lAudioIn			= new float[initialBufferSize];
	rAudioIn			= new float[initialBufferSize];
    
    
    memset(lAudioOut, 0, initialBufferSize * sizeof(float));
	memset(rAudioOut, 0, initialBufferSize * sizeof(float));
	memset(lAudioIn, 0, initialBufferSize * sizeof(float));
	memset(rAudioIn, 0, initialBufferSize * sizeof(float));
	
    samp.load(ofToDataPath("m1200.wav"));
	samp.getLength();
    sampleRate = samp.mySampleRate;
    //int channelNum = samp.myChannels;
    
    
	fftSize = 1024;
	mfft.setup(fftSize, 512, 256);
	ifft.setup(fftSize, 512, 256);
    
	nAverages = 12;
	oct.setup(sampleRate, fftSize/2, nAverages);
	
	mfccs = (double*) malloc(sizeof(double) * 13);
	mfcc.setup(512, 21, 13, 20, 20000, sampleRate);
    
	ofxMaxiSettings::setup(sampleRate, 2, initialBufferSize);
    //ofxMaxiSettings::setup
	ofSoundStreamSetup(2,2, this, sampleRate, initialBufferSize, 4);
    //ofSoundStreamSetup(<#int nOutputChannels#>, <#int nInputChannels#>, <#ofBaseApp *appPtr#>, <#int sampleRate#>, <#int bufferSize#>, <#int nBuffers#>)
    //ofSoundStreamSet
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //因为ArialUnicode总是报错，因此尝试直接用ofTrueTypeFont看会不会有问题。
    //verdana.loadFont("verdana.ttf", 14, true, true);
    verdana.loadFont("Arial Unicode.ttf", 7, true, true);
    verdana.setLineHeight(18.0f);
    verdana.setLetterSpacing(1.037);
    
    NewMediaFett.loadFont("GUI/NewMedia Fett.ttf", 20);
    ArialUnicode.loadFont("Arial Unicode.ttf", 7);
    
    goingChangeRotateAngle = 0;
    weektimer.timer_base = 150;
    weektimer.timer_add = 15;
    weektimer.start();
    daytimer.timer_base = 150;
    daytimer.timer_add = 15;
    daytimer.start();
    
    blinktimer.timer_base = 60;
    blinktimer.timer_add = 1;
    blinktimer.start();
    
    timelinecontrolorisRotated = false;
    infovisible = false;
}

//--------------------------------------------------------------
void testApp::update(){
}

//--------------------------------------------------------------
void testApp::draw(){
      
    time_t rawtime;
    time(&rawtime);
    time2 = localtime(&rawtime);
    time1sec = mktime(&time1);
    time2sec = mktime(time2);
    
    days = (int)((time2sec - time1sec)/(24 * 60 * 60));
    int hours = (int)((time2sec - time1sec)%(24 * 60 * 60)/(60 * 60));
    int miniutes = (int)((time2sec - time1sec)%(24 * 60 * 60)%(60 * 60)/60);
    int seconds = (int)((time2sec - time1sec)%(24 * 60 * 60)%(60 * 60)%60);
    string datashow = converFloat(days).append(" | ").append(converFloat(hours)).append(" : ").append(converFloat(miniutes)).append(" : ").append(converFloat(seconds)).append("");
    ofBackground(red, green, blue, 255);
	ofPushStyle();
    ofDisableAlphaBlending();
	ofPopStyle();
    
    ofSetColor(255);
    bg.draw(ofGetWidth()/2, ofGetHeight()/2);
    
    
    weektimer.run();
    daytimer.run();
    blinktimer.run();
    
    if(blinktimer.timer_count>blinktimer.timer_base/2)
    {
        inforPanel->setColorFill(ofColor(255,255,255,255));
        inforPanel_blink->setColorFill(ofColor(255,255,255,0));
    }
    else
    {
        inforPanel->setColorFill(ofColor(255,255,255,0));
        inforPanel_blink->setColorFill(ofColor(255,255,255,255));
    }

    ofSetColor(255, 255, 255);
    ofFill();

    ofPushMatrix();
    
    
    
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    
    ofSetLineWidth(0.5);
    ofSetColor(0, 0, 0);
    ofLine(0, 0, 0, -33 * 11);
    

    
    ofPopMatrix();
    
    ofPoint Hungary = masatXML.getHungary();
    
        
    if (!flag_infoPanel_onBoardTemperature_Button) {
        masatAudio.AudioDraw(fftSize, mfcc.melBands);
    }
    

    if (goingChange || flag_infoPanel_timetracker_Button || flag_infoPanel_TimeLine_Button || flag_infoPanel_location_Button || flag_infoPanel_onBoardTemperature_Button) {
        if (flag_infoPanel_onBoardTemperature_Button)
        {
            FadeIn2();
        }
        else
        {
            FadeIn();
        }
    }
    else
    {
            FadeOut();
    }

    
    for (int i = 0; i < 6; i++) {
        if (goingChange)
        {
            PanelDataButton[i].update(0, Hungary);
        }
        else if (goingChangeTimeLine)
        {
            
            if (timelinecontrolorisRotated) {
                int diffentbetweenTimeControllorCountandCount = PanelDataButton[10].TimeControlorCount - count;
                
                float differentspeed = 0;
                for (int i = MIN(PanelDataButton[10].TimeControlorCount, count); i < MAX(PanelDataButton[10].TimeControlorCount, count); i++) {
                    differentspeed += masatXML.panelvol[count][i];
                }
                if (diffentbetweenTimeControllorCountandCount < 0) {
                    PanelDataButton[i].update(-differentspeed, Hungary);
                }
                else
                {
                    PanelDataButton[i].update(differentspeed, Hungary);
                }
               
            }
            else PanelDataButton[i].update(0, Hungary);
           
        }
        else PanelDataButton[i].update(masatXML.panelvol[count][i], Hungary);
        
        PanelDataButton[i].draw( 150 + masatXML.paneltemp[count][i] * 3, 50 + masatXML.panelvol[count][i] * 3);
        
        if (abs(PanelDataButton[i].radius - PanelDataButton[i].oldRadius) > 300)
        {
            PanelDataButton[i].debugMode = true;
        }
        
    }

    
    for (int i = 6; i < 9; i++) {
        if (goingChange)
        {
            PanelDataButton[i].update(0, Hungary);
        }
        else if (goingChangeTimeLine)
        {
            
            if (timelinecontrolorisRotated) {
                int diffentbetweenTimeControllorCountandCount = PanelDataButton[10].TimeControlorCount - count;
                
                float differentspeed = 0;
                for (int i = MIN(PanelDataButton[10].TimeControlorCount, count); i < MAX(PanelDataButton[10].TimeControlorCount, count); i++) {
                    differentspeed += masatXML.batterytemp[count]/10.0;
                }
                if (diffentbetweenTimeControllorCountandCount < 0) {
                    PanelDataButton[i].update(-differentspeed, Hungary);
                }
                else
                {
                    PanelDataButton[i].update(differentspeed, Hungary);
                }
            }
            else PanelDataButton[i].update(0, Hungary);
            
        }
        else PanelDataButton[i].update(masatXML.batterytemp[count]/10.0, Hungary);
        
        PanelDataButton[i].draw( 150 + masatXML.OnBoardTempp[count][i - 6] * 3);
        
        if (abs(PanelDataButton[i].radius - PanelDataButton[i].oldRadius) > 300) {
            PanelDataButton[i].debugMode = true;
        }
    }
    
    timelinecontrolorisRotated = false;
    
    if (!goingChange) {
        PanelDataButton[10].timecontrolupdate(360.0/3494.0/7.0);
        PanelDataButton[10].timecontroldraw(weektimer.timer_count);
    }

    if (!flag_infoPanel_onBoardTemperature_Button and !flag_infoPanel_temperature_Button and !flag_infoPanel_TimeLine_Button and !flag_infoPanel_voltage_Button and !flag_infoPanel_timetracker_Button) {
        if (goingChange) {
            masatXML.XMLGeoInfoDrawForPause(goingChangeRotateAngle);
        }
        else masatXML.XMLGeoInfoDraw(masatXML.batterytemp[count]/10);
    }

    
    masatXML.HungaryPosUpdate();
    
    if (count < 3493) {
        if (!goingChange && !goingChangeTimeLine) {
            //这个变量要小心count归零时的运行情况
            previousCount = count;
            count++;
        }
    }
    else
    {
        count = 0;
        if (weekcount < 7) {
            weekcount++;
        }
        else weekcount = 0;
    }
    //inforPanelSrc.setColor(ofColor(255,255,255,weektimer.timer_count));
//    inforPanel->setColorFill(ofColor(255,255,255,weektimer.timer_count));
//    inforPanel_blink->setColorFill(ofColor(255,255,255,255-weektimer.timer_count));
    //inforPanel->setColorFill(ofColor(255,255,255,0));

    ofSetColor(0, 0, 0, 200 - PanelDataButton[10].ColorButtonFill.a);
    ofFill();
    //这个地方总是报错
    ArialUnicode.drawString(datashow, 465, 15);
    //verdana.drawString(datashow, 465, 15);
    //这里添加了infopanel中按钮用来隐藏其他部分的功能。
    //不过在buttonSig中大圆圈里的小圆圈的隐藏还没有搞定，需要在buttonSig的draw里看一下，不过有些奇怪，按理说可以根据按下中间的按钮后隐藏全部分功能来推倒出当初这部分的实现方法。
    if (flag_infoPanel_onBoardTemperature_Button) {
        //inforPanel->setVisible(false);
        inforPanel->setImage(infoPanel_onBoardTemperature_Button_PanelSrc);
        inforPanel_blink->setImage(infoPanel_onBoardTemperature_Button_Panel_blink_Src);
        infoPanel_location_Button->setVisible(false);
        infoPanel_temperature_Button->setVisible(false);
        infoPanel_TimeLine_Button->setVisible(false);
        infoPanel_voltage_Button->setVisible(false);
        infoPanel_timetracker_Button->setVisible(false);
        for (int i = 0; i < 6; i++) {
            //line
            PanelDataButton[i].myButton->getColorFill().a = 0;
            //related to insdie somehow
            PanelDataButton[i].ColorButtonFill = ofColor(200, 0);
        }
        for (int i = 6; i < 9; i++) {
            //line
            PanelDataButton[i].myButton->getColorFill().a = 200;
            PanelDataButton[i].ColorButtonFill = ofColor(200, 200);
        }
    }
    if (flag_infoPanel_temperature_Button) {
        inforPanel->setImage(infoPanel_temperature_Button_PanelSrc);
        inforPanel_blink->setImage(infoPanel_temperature_Button_Panel_blink_Src);
        infoPanel_location_Button->setVisible(false);
        infoPanel_onBoardTemperature_Button->setVisible(false);
        infoPanel_TimeLine_Button->setVisible(false);
        infoPanel_voltage_Button->setVisible(false);
        infoPanel_timetracker_Button->setVisible(false);
        for (int i = 0; i < 9; i++) {
            PanelDataButton[i].myButton->getColorFill().a = 0;
            PanelDataButton[i].ColorButtonFill = ofColor(200, 20);
        }
    }
    if (flag_infoPanel_voltage_Button) {
        inforPanel->setImage(infoPanel_voltage_Button_PanelSrc);
        inforPanel_blink->setImage(infoPanel_voltage_Button_Panel_blink_Src);
        infoPanel_location_Button->setVisible(false);
        infoPanel_temperature_Button->setVisible(false);
        infoPanel_TimeLine_Button->setVisible(false);
        infoPanel_onBoardTemperature_Button->setVisible(false);
        infoPanel_timetracker_Button->setVisible(false);
        for (int i = 6; i < 9; i++) {
            PanelDataButton[i].myButton->getColorFill().a = 20;
            PanelDataButton[i].myButton->getColorFill().a = 0;
            PanelDataButton[i].ColorButtonFill = ofColor(200, 0);
        }
    }
    if (flag_infoPanel_location_Button) {
        inforPanel->setImage(infoPanel_location_Button_PanelSrc);
        inforPanel_blink->setImage(infoPanel_location_Button_Panel_blink_Src);
        infoPanel_voltage_Button->setVisible(false);
        infoPanel_temperature_Button->setVisible(false);
        infoPanel_TimeLine_Button->setVisible(false);
        infoPanel_onBoardTemperature_Button->setVisible(false);
        infoPanel_timetracker_Button->setVisible(false);
        for (int i = 0; i < 9; i++) {
            PanelDataButton[i].myButton->getColorFill().a = 0;
            PanelDataButton[i].ColorButtonFill = ofColor(200, 0);
        }
    }
    if (flag_infoPanel_TimeLine_Button) {
        inforPanel->setImage(infoPanel_TimeLine_Button_PanelSrc);
        inforPanel_blink->setImage(infoPanel_TimeLine_Button_Panel_blink_Src);
        infoPanel_voltage_Button->setVisible(false);
        infoPanel_temperature_Button->setVisible(false);
        infoPanel_location_Button->setVisible(false);
        infoPanel_onBoardTemperature_Button->setVisible(false);
        infoPanel_timetracker_Button->setVisible(false);
        for (int i = 0; i < 9; i++) {
            PanelDataButton[i].myButton->getColorFill().a = 0;
            PanelDataButton[i].ColorButtonFill = ofColor(200, 0);
            
        }
    }
    if (flag_infoPanel_timetracker_Button) {
        inforPanel->setImage(infoPanel_timetracker_Button_PanelSrc);
        inforPanel_blink->setImage(infoPanel_timetracker_Button_Panel_blink_Src);
        infoPanel_voltage_Button->setVisible(false);
        infoPanel_temperature_Button->setVisible(false);
        infoPanel_location_Button->setVisible(false);
        infoPanel_onBoardTemperature_Button->setVisible(false);
        infoPanel_TimeLine_Button->setVisible(false);
        for (int i = 0; i < 9; i++) {
            PanelDataButton[i].myButton->getColorFill().a = 0;
            PanelDataButton[i].ColorButtonFill = ofColor(200, 0);
        }
    }
}

//--------------------------------------------------------------
void testApp::exit(){
    delete gui;
}

void testApp::guiEvent(ofxUIEventArgs &e)
{
    string name = e.widget->getName();
    
	int kind = e.widget->getKind();
    
    if(kind == OFX_UI_WIDGET_IMAGEBUTTON)
    {
        ofxUIImageButton *button = (ofxUIImageButton *) e.widget;
        int buttonID = 0;
        
        stringstream(button->getName()) >> buttonID;
        
        if (button->getValue()) {
            PanelDataButton[buttonID].bDragged = PanelDataButton[buttonID].tempID;
            PanelDataButton[buttonID].touchMouseX = PanelDataButton[buttonID].tempMouseX - PanelDataButton[buttonID].center.x - PanelDataButton[buttonID].pos.x;
            PanelDataButton[buttonID].touchMouseY = PanelDataButton[buttonID].tempMouseY - PanelDataButton[buttonID].center.y - PanelDataButton[buttonID].pos.y;
            PanelDataButton[buttonID].distcenter = ofDist(PanelDataButton[buttonID].touchMouseX, PanelDataButton[buttonID].touchMouseY, 0, 0);

            
            for (int i = 0; i < PanelDataButton.size(); i++) {
                for (int j = 0; j < i; j++) {
                    if (PanelDataButton[i].bDragged == PanelDataButton[j].bDragged) {
                        PanelDataButton[j].myButton->setValue(false);
                        PanelDataButton[j].myButton->touchId = -1;
                        PanelDataButton[j].bDragged = -1;
                        PanelDataButton[j].distcenter = 2000;
                    }
                }
            }
            if (button->getName() == "inforButton") {
                if (infovisible) {
                    infovisible = false;
                }
                else
                {
                    infovisible = true;
                }
                
            }
            if (infovisible) {
                inforPanel->setImage(&inforPanelSrc);
                inforPanel->setVisible(true);
                inforPanel_blink->setImage(&inforPanelSrc);
                inforPanel_blink->setVisible(true);
                
                infoPanel_location_Button->setVisible(true);
                infoPanel_temperature_Button->setVisible(true);
                infoPanel_voltage_Button->setVisible(true);
                infoPanel_TimeLine_Button->setVisible(true);
                infoPanel_onBoardTemperature_Button->setVisible(true);
                infoPanel_timetracker_Button->setVisible(true);
            }
            else
            {
                inforPanel->setVisible(false);
                inforPanel_blink->setVisible(false);
                infoPanel_location_Button->setVisible(false);
                infoPanel_temperature_Button->setVisible(false);
                infoPanel_voltage_Button->setVisible(false);
                infoPanel_TimeLine_Button->setVisible(false);
                infoPanel_onBoardTemperature_Button->setVisible(false);
                infoPanel_timetracker_Button->setVisible(false);
            }
            if (button->getName() == "infoPanel_location_Button") {
                cout<<"infoPanel_location_Button Yes"<<endl;
                flag_infoPanel_location_Button = !flag_infoPanel_location_Button;
            }
            if (button->getName() == "infoPanel_temperature_Button") {
                cout<<"infoPanel_temperature_Button Yes"<<endl;
                flag_infoPanel_temperature_Button = !flag_infoPanel_temperature_Button;
            }
            if (button->getName() == "infoPanel_voltage_Button") {
                cout<<"infoPanel_voltage_Button Yes"<<endl;
                flag_infoPanel_voltage_Button = !flag_infoPanel_voltage_Button;
            }
            if (button->getName() == "infoPanel_TimeLine_Button") {
                cout<<"infoPanel_TimeLine_Button Yes"<<endl;
                flag_infoPanel_TimeLine_Button = !flag_infoPanel_TimeLine_Button;
            }
            if (button->getName() == "infoPanel_onBoardTemperature_Button") {
                cout<<"infoPanel_onBoardTemperature_Button      Yes"<<endl;
                flag_infoPanel_onBoardTemperature_Button = !flag_infoPanel_onBoardTemperature_Button;
            }
            if (button->getName() == "infoPanel_timetracker_Button") {
                cout<<"infoPanel_timetracker_Button      Yes"<<endl;
                flag_infoPanel_timetracker_Button = !flag_infoPanel_timetracker_Button;
            }
        }
        else
        {
            if (buttonID != 9 && buttonID != 10) {
                PanelDataButton[buttonID].myButton->touchId = -1;
                PanelDataButton[buttonID].bDragged = -1;
                PanelDataButton[buttonID].distcenter = 2000;
            }
        }
        
        for (int i = 0; i < PanelDataButton.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (PanelDataButton[i].bDragged == PanelDataButton[j].bDragged) {
                    PanelDataButton[j].myButton->setValue(false);
                    PanelDataButton[j].myButton->touchId = -1;
                    PanelDataButton[j].bDragged = -1;
                    PanelDataButton[j].distcenter = 2000;
                }
            }
        }
        

        
        
        
        if (PanelDataButton[buttonID].myButton->getName() == "9") {
            if (PanelDataButton[buttonID].myButton->getValue())
            {
                goingChange = true;
                goingChangeRotateAngle = 0;
            }
        }
        //-------new insert-------
        else if (PanelDataButton[buttonID].myButton ->getName() == "10")
        {
            if (PanelDataButton[buttonID].myButton->getValue())
            {
                goingChangeTimeLine = true;
                
            }
        }
        //-------new insert-------
        else
        {
            //use "-2" to make sure ButtonHightLight and Fill only works for the 9 moving buttons
            for (int i = 0; i < PanelDataButton.size() - 2; i++) {
                if (PanelDataButton[i].myButton->getValue()) {
                    PanelDataButton[i].myButton->setColorFill(PanelDataButton[i].ColorButtonHighLight);
                }
                else
                {
                    PanelDataButton[i].myButton->setColorFill(PanelDataButton[i].ColorButtonFill);
                }
            }
        }
        

        
    }
}



//--------------------------------------------------------------
void testApp::touchDown(ofTouchEventArgs & touch){
    for (int i = 0; i < PanelDataButton.size(); i++) {
        PanelDataButton[i].tempID = touch.id;
        PanelDataButton[i].tempMouseX = touch.x;
        PanelDataButton[i].tempMouseY = touch.y;
    }
    
}

//--------------------------------------------------------------
void testApp::touchMoved(ofTouchEventArgs & touch){
    float sum6Move = 0;
    float sum3Move = 0;
    for (int i = 0; i < PanelDataButton.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (PanelDataButton[i].bDragged == PanelDataButton[j].bDragged) {
                PanelDataButton[j].bDragged = -1;
            }
        }
    }
    
    for (int i = 0; i < PanelDataButton.size(); i++) {
        if (PanelDataButton[i].bDragged == touch.id) {
            if (i != 10) {
                PanelDataButton[i].moveTo(touch.x - PanelDataButton[i].touchMouseX, touch.y - PanelDataButton[i].touchMouseY, ofDist(PanelDataButton[i].touchMouseX, PanelDataButton[i].touchMouseY, 0, 0));
            }
            else
            {
                PanelDataButton[i].timecontrolmoveTo(touch.x - PanelDataButton[i].touchMouseX, touch.y - PanelDataButton[i].touchMouseY);
                
            }
            
            
            if (i < 6) {
                sum6Move += PanelDataButton[i].radius - PanelDataButton[i].oldRadius;
            }
            if (i < 9 && i > 5) {
                sum3Move += (PanelDataButton[i].radius - PanelDataButton[i].oldRadius)/PanelDataButton[i].oldRadius;
            }
            if (i == 10) {
                
            }
        }
    }
    for (int i = 0; i < PanelDataButton.size(); i++) {
        if (PanelDataButton[i].bDragged == -1)
        {
            if (i < 6) {
                
                if (PanelDataButton[i].radius > 500) {
                    PanelDataButton[i].direction = -1;
                }
                if (PanelDataButton[i].radius < -500) {
                    PanelDataButton[i].direction = 1;
                }
                
                PanelDataButton[i].radius += PanelDataButton[i].direction * abs(sum6Move);
            }
            if (i < 9 && i > 5) {
                PanelDataButton[i].radius += PanelDataButton[i].direction * sum3Move * PanelDataButton[i].radius;
            }
            
        }
    }
    
    if (PanelDataButton[9].bDragged == touch.id) {
        goingChangeRotateAngle = PanelDataButton[9].tempMouseX - touch.x;
    }
    if (PanelDataButton[10].bDragged == touch.id) {
        //goingChangeRotateAngle = PanelDataButton[10].tempMouseX - touch.x;
        timelinecontrolorisRotated = true;

    }
    
}

//--------------------------------------------------------------
void testApp::touchUp(ofTouchEventArgs & touch){
    if ( PanelDataButton[9].bDragged == touch.id) {

        PanelDataButton[9].myButton->setValue(false);
        PanelDataButton[9].myButton->touchId = -1;
        PanelDataButton[9].bDragged = -1;
        PanelDataButton[9].distcenter = 2000;
        goingChange = false; 
        
        masatXML.spinAngle += goingChangeRotateAngle;
        
    }
    if ( PanelDataButton[10].bDragged == touch.id) {

        PanelDataButton[10].myButton->setValue(false);
        PanelDataButton[10].myButton->touchId = -1;
        PanelDataButton[10].bDragged = -1;
        PanelDataButton[10].distcenter = 2000;
        goingChangeTimeLine = false;
        count = PanelDataButton[10].TimeControlorCount;
    }
}

//--------------------------------------------------------------
void testApp::touchDoubleTap(ofTouchEventArgs & touch){
}

//--------------------------------------------------------------
void testApp::touchCancelled(ofTouchEventArgs & touch){
}

//--------------------------------------------------------------
void testApp::lostFocus(){
    
}

//--------------------------------------------------------------
void testApp::gotFocus(){
    
}

//--------------------------------------------------------------
void testApp::gotMemoryWarning(){
    
}

//--------------------------------------------------------------
void testApp::deviceOrientationChanged(int newOrientation){
    
}
void testApp::audioRequested(float * output, int bufferSize, int nChannels){
	
    //	static double tm;
	for (int i = 0; i < bufferSize; i++){
		//wave = samp.play(1.);
        wave = samp.play();
		//get fft
		if (mfft.process(wave)) {
			mfft.magsToDB();
			oct.calculate(mfft.magnitudesDB);
			mfcc.mfcc(mfft.magnitudes, mfccs);
		}
		//inverse fft
		gettimeofday(&callTS,NULL);
		gettimeofday(&callEndTS,NULL);
		callTime = (float)(callEndTS.tv_usec - callTS.tv_usec) / 1000000.0;
		callTime += (float)(callEndTS.tv_sec - callTS.tv_sec);
		//play result
		mymix.stereo(wave, outputs, 0.5);
		lAudioOut[i] = output[i*nChannels    ] = outputs[0]; /* You may end up with lots of outputs. add them here */
		rAudioOut[i] = output[i*nChannels + 1] = outputs[1];
	}
	
}

//--------------------------------------------------------------
void testApp::audioReceived(float * input, int bufferSize, int nChannels){
    
}

