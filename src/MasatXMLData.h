//
//  MasatXMLData.h
//  UniverseMasatIB
//
//  Created by Kindpire on 12-11-10.
//  Copyright (c) 2012年 __MyCompanyName__. All rights reserved.
//

#ifndef UniverseMasatIB_MasatXMLData_h
#define UniverseMasatIB_MasatXMLData_h

#include "ofxXmlSettings.h"
#include "ofxFTGLESFont.h"
//#include "ofTrueTypeFontWS.h"

class MasatXMLData
{

public:
    ofxXmlSettings XML;
    string xmlStructure;
    string message;
    int numCells;
    int arcdata[322][5];
    float amateurs[322][3];
    string address[322][2];
    float paneltemp[3493][6];
    float panelvol[3493][6];
    float batterytemp[3493];
    float OnBoardTempp[3493][3];
    float spinAngle = 0.0;
    float Gradius = 220;
    ofPoint Hungary;
    
    ofBuffer buffer;
    string addresstest = buffer.getFirstLine();
    int filelength;
    ofTrueTypeFont addressFont;
    //ofTrueTypeFontWS test;
    
    ofxFTGLESFont font;
	wstring str;
	
	vector<ofVec2f> points;
    
    int counttest;
    
    void XMLInit()
    {
        
        message = "loading MASAT.xml";
        if (XML.loadFile(ofxiPhoneGetDocumentsDirectory()+"MASAT.xml")) {
            message = "data loaded from documents folder!";
        }
        else if(XML.loadFile("MASAT.xml"))
        {
            message = "data loaded from data folder!";
        }
        else
        {
            message = "unable to load file check data/ folder";
        }
        
        numCells = 0;
        
        counttest = 0;
        
        buffer = ofBufferFromFile("addresstest.txt");
        addresstest = buffer.getFirstLine();
        filelength = buffer.size();

        addressFont.loadFont("song.ttf", 14, true, true);

        addressFont.setLineHeight(18.0f);
        addressFont.setLetterSpacing(1.037);
        
        str = wstring(L"简体 繁體 Kikötő");

        font.loadFont("Arial Unicode.ttf", 6, true);
        
        XML.pushTag("Workbook",0);
        
        //worksheet 0
        
        XML.pushTag("Worksheet",0);
        XML.pushTag("Table",0);
        for (int i = 0; i < 3493; i++) {
            XML.pushTag("Row",i);     
            for (int j = 0; j < 6; j++) {
                XML.pushTag("Cell", j);
                paneltemp[i][j] = XML.getValue("Data", 0.0);
                XML.popTag();
            }
            XML.popTag();
        }
        XML.popTag();
        XML.popTag();
        
        //worksheet 1
        
        XML.pushTag("Worksheet",1);
        XML.pushTag("Table",0);
        for (int i = 0; i < 3493; i++) {
            XML.pushTag("Row",i);     
            for (int j = 0; j < 6; j++) {
                XML.pushTag("Cell", j);
                panelvol[i][j] = XML.getValue("Data", 0.0);
                XML.popTag();
            }
            XML.popTag();
        }
        XML.popTag();
        XML.popTag();
        
        //worksheet 2
        
        XML.pushTag("Worksheet",2);
        XML.pushTag("Table",0);
        for (int i = 0; i < 3493; i++) {
            XML.pushTag("Row",i);     
            
            XML.pushTag("Cell", 0);
            batterytemp[i] = XML.getValue("Data", 0.0);
            XML.popTag();
            
            XML.popTag();
        }
        XML.popTag();
        XML.popTag();
        
        //worksheet 3
        
        XML.pushTag("Worksheet",3);
        XML.pushTag("Table",0);
        for (int i = 0; i < 3493; i++) {
            XML.pushTag("Row",i);     
            for (int j = 0; j < 3; j++) {
                XML.pushTag("Cell", j);
                OnBoardTempp[i][j] = XML.getValue("Data", 0.0);
                XML.popTag();
            }
            XML.popTag();
        }
        XML.popTag();
        XML.popTag();
        
        //worksheet 4
        XML.pushTag("Worksheet",4);
        XML.pushTag("Table",0);
        for (int i = 0; i < 322; i++) {
            
            
            XML.pushTag("Row",i);
            
            //amateurs[2][2] = 3;
            
            XML.pushTag("Cell", 1);
            amateurs[i][0] = XML.getValue("Data", 0.0);
            XML.popTag();
            XML.pushTag("Cell", 2);
            amateurs[i][1] = XML.getValue("Data", 0.0);
            XML.popTag();
            XML.pushTag("Cell", 4);
            int packagenums = XML.getValue("Data", 0.0);
            amateurs[i][2] = packagenums;
            
            int thousands = packagenums/1000;
            int handreds = packagenums%1000/100;
            int tens = packagenums%1000%100/10;
            int singles = packagenums%1000%100%10;
            
            arcdata[i][0] = thousands;
            arcdata[i][1] = handreds;
            arcdata[i][2] = tens;
            arcdata[i][3] = singles;
            int totaldegrees;
            
            if (thousands != 0) {
                totaldegrees = 30 + 20 + 10 + 2 * singles;
            }
            else if(handreds != 0)
            {
                totaldegrees = 20 + 10 + 2 * singles;
            }
            else if(tens != 0)
            {
                totaldegrees = 10 + 2 * singles;
            }
            else
            {
                totaldegrees = 2 * singles;
            }
            arcdata[i][4] = totaldegrees;
            XML.popTag();
            
            XML.pushTag("Cell", 5);
            address[i][0] = XML.getValue("Data", "Unknown");
            XML.popTag();
            
            XML.pushTag("Cell", 6);
            address[i][1] = XML.getValue("Data", "Unknown");
            XML.popTag();
            
            XML.popTag();
        }
        XML.popTag();
        XML.popTag();
        
        XML.popTag();
        
        
    }
    
    
    void XMLGeoInfoDraw(float batteryTemperature)
    {
        ofPushMatrix();
        ofTranslate(ofGetWidth()/2, ofGetHeight()/2, 0);
        ofRotateY(spinAngle);

        glEnable(GL_DEPTH_TEST);
        
        
        for (int i = 0; i < 322; i++)
        {
            ofEnableAlphaBlending();
            if (amateurs[i][2] > 0) {
                ofPushMatrix();
                ofRotateY(amateurs[i][1]);
                ofRotateX(amateurs[i][0]);
                
                ofSetColor(255);
                
                
                
                ofSetLineWidth(1);
                
                float tempRadius = 50 + (Gradius + 70)  * (i/322.0);
                
                ofSetColor(213, 174, 133, 180);
                ofCircle(0, 0, tempRadius - 2, 10);
                ofSetColor(205, 115, 86, 180);
                ofCircle(0, 0, tempRadius - 1, 15);
                
                if (amateurs[i][2] > 5000) 
                {
                    ofSetColor(155, 89, 105, 180);
                    ofCircle(0, 0, tempRadius - 0.9, 20);
                    ofSetColor(234, 103, 59, 180);
                    ofCircle(0, 0, tempRadius - 0.8, 23);
                    ofCircle(0, 0, tempRadius + 0.8, 23);
                    ofSetColor(0, 180);
                    ofNoFill();
                    ofCircle(0, 0, tempRadius + 0.8, 23);
                    ofFill();
                    ofSetColor(183, 121, 54, 180);
                    ofCircle(0, 0, tempRadius - 0.6, 26);
                    ofCircle(0, 0, tempRadius + 0.6, 26);
                    ofSetColor(0, 180);
                    ofNoFill();
                    ofCircle(0, 0, tempRadius + 0.6, 26);
                    ofFill();
                }
                
                ofSetColor(155, 89, 105, 180);
                ofCircle(0, 0, tempRadius, 20);
                ofNoFill();
                ofSetColor(0, 180);
                ofCircle(0, 0, tempRadius, 20);
                ofFill();
                ofSetColor(205, 115, 86, 180);
                ofCircle(0, 0, tempRadius + 1, 15);
                ofNoFill();
                ofSetColor(0, 180);
                ofCircle(0, 0, tempRadius + 1, 15);
                ofFill();
                ofSetColor(213, 174, 133, 180);
                ofCircle(0, 0, tempRadius + 2, 10);
                ofNoFill();
                ofSetColor(0, 180);
                ofCircle(0, 0, tempRadius + 2, 10);
                ofFill();
                ofSetLineWidth(1);
                ofPushMatrix();
                ofTranslate(0, 0, tempRadius + 5);
                
//                vector<string> addressStringArray = ofSplitString(address[i][1], ",");
//                string sumaddress = "";
//                for (int j = 0; j < addressStringArray.size(); j++) {
//                    sumaddress += addressStringArray[j] + "\n";
//                    ofSetColor(0,255);
//                    font.drawString(addressStringArray[j] , 30, 10 * j - 10 * addressStringArray.size() / 2.0);
//                }
//                addressFont.hasFullCharacterSet();

                ofDisableAlphaBlending();
                counttest ++;
                ofPopMatrix();
                ofPopMatrix();
                
                
            }
            else
            {
                ofSetColor(0, 0, 255, 10);
            }
            
        }
        counttest = 0;
        
        
        ofPopMatrix();
        
        glDisable(GL_DEPTH_TEST);
        
        
        spinAngle += batteryTemperature;
        if (spinAngle > 360) {
            spinAngle -= 360;
        }
        
        if (numCells < 3493) {
            numCells++;
        }
        else
        {
            numCells = 0;
        }
        
    }
    
    void XMLGeoInfoDrawForPause(int _goingChangeRotateAngle)
    {
        ofPushMatrix();
        ofTranslate(ofGetWidth()/2, ofGetHeight()/2, 0);
        ofRotateY(spinAngle + _goingChangeRotateAngle);
        
        glEnable(GL_DEPTH_TEST);
        
        
        for (int i = 0; i < 322; i++)
        {
            ofEnableAlphaBlending();
            if (amateurs[i][2] > 0) {
                ofPushMatrix();
                ofRotateY(amateurs[i][1]);
                ofRotateX(amateurs[i][0]);
                
                ofSetColor(255);
                
                
                
                ofSetLineWidth(1);
                
                float tempRadius = 50 + (Gradius + 70)  * (i/322.0);
                
                ofSetColor(213, 174, 133, 180);
                ofCircle(0, 0, tempRadius - 2, 10);
                ofSetColor(205, 115, 86, 180);
                ofCircle(0, 0, tempRadius - 1, 15);
                
                if (amateurs[i][2] > 5000)
                {
                    ofSetColor(155, 89, 105, 180);
                    ofCircle(0, 0, tempRadius - 0.9, 20);
                    ofSetColor(234, 103, 59, 180);
                    ofCircle(0, 0, tempRadius - 0.8, 23);
                    ofCircle(0, 0, tempRadius + 0.8, 23);
                    ofSetColor(0, 180);
                    ofNoFill();
                    ofCircle(0, 0, tempRadius + 0.8, 23);
                    ofFill();
                    ofSetColor(183, 121, 54, 180);
                    ofCircle(0, 0, tempRadius - 0.6, 26);
                    ofCircle(0, 0, tempRadius + 0.6, 26);
                    ofSetColor(0, 180);
                    ofNoFill();
                    ofCircle(0, 0, tempRadius + 0.6, 26);
                    ofFill();
                }
                
                ofSetColor(155, 89, 105, 180);
                ofCircle(0, 0, tempRadius, 20);
                ofNoFill();
                ofSetColor(0, 180);
                ofCircle(0, 0, tempRadius, 20);
                ofFill();
                ofSetColor(205, 115, 86, 180);
                ofCircle(0, 0, tempRadius + 1, 15);
                ofNoFill();
                ofSetColor(0, 180);
                ofCircle(0, 0, tempRadius + 1, 15);
                ofFill();
                ofSetColor(213, 174, 133, 180);
                ofCircle(0, 0, tempRadius + 2, 10);
                ofNoFill();
                ofSetColor(0, 180);
                ofCircle(0, 0, tempRadius + 2, 10);
                ofFill();
                ofSetLineWidth(1);
                ofPushMatrix();
                ofTranslate(0, 0, tempRadius + 5);
                
                vector<string> addressStringArray = ofSplitString(address[i][1], ",");
                string sumaddress = "";
                for (int j = 0; j < addressStringArray.size(); j++) {
                    sumaddress += addressStringArray[j] + "\n";
                    ofSetColor(0,255);
                    font.drawString(addressStringArray[j] , 30, 9 * j - 10 * addressStringArray.size() / 2.0);
                }
                addressFont.hasFullCharacterSet();
                
                ofDisableAlphaBlending();
                counttest ++;
                
                ofPopMatrix();
                
                ofPopMatrix();
                
                
            }
            else
            {
                ofSetColor(0, 0, 255, 10);
            }
            
        }
        counttest = 0;
        
        
        ofPopMatrix();
        
        glDisable(GL_DEPTH_TEST);
        
        
        //spinAngle += batteryTemperature;
        if (spinAngle > 360) {
            spinAngle -= 360;
        }
        
        if (numCells < 3493) {
            numCells++;
        }
        else
        {
            numCells = 0;
        }
        
    }
    
    void HungaryPosUpdate()
    {
        float HungaryY = -(50 + (Gradius + 70) * (22/322.0)) * sin(amateurs[319][0] * PI / 180);
        float HungaryZ = (50 + (Gradius + 70) * (22/322.0)) * cos(amateurs[319][0] * PI / 180) * cos((amateurs[319][1]+spinAngle) * PI / 180);
        float HungaryX = (50 + (Gradius + 70) * (22/322.0)) * cos(amateurs[319][0] * PI / 180) * sin((amateurs[319][1]+spinAngle) * PI / 180);
        Hungary.set(HungaryX, HungaryY, HungaryZ);

    }
    
    ofPoint getHungary()
    {
        return Hungary;
    }
    
};
#endif