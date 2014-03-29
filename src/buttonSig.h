//
//  buttonSig.h
//  ImageButtonTest
//
//  Created by Kindpire on 12-11-5.
//  Copyright (c) 2012年 __MyCompanyName__. All rights reserved.
//

#ifndef ImageButtonTest_buttonSig_h
#define ImageButtonTest_buttonSig_h
#include "ofxUI.h"

class buttonSig{
    
public:
    ofPoint pos;
    ofPoint center;
    ofxUIImageButton *myButton;
    ofxUILabel *myLabel;
    bool debugMode;
    int bDragged;
    int tempID;
	string buttonName;
    float spin;
    float angel;
    float radius;
    float oldRadius;
    int direction;
    ofImage centerOne;
    bool change;
    bool hasCenter;
    
    int tempMouseX;
    int tempMouseY;
    int touchMouseX;
    int touchMouseY;
    
    float fingerangle;
    
    int TimeControlorCount;
    
    ofColor ColorButtonFill;
    ofColor ColorButtonHighLight;
    
    ofColor ColorCenterButtonFill;
    ofColor ColorCenterButtonHighLight;
    
    float distcenter;
    
    ofTrueTypeFont verdana;
    
    //ofTrueTypeFont fonttest;
    
    ofxFTGLESFont verdana2;
    
    ofPoint Hungary;
    
    int panelNum;
    
    void init(int id, int picWidth, int picHeight, int posX, int posY, int centerX, int centerY, string picURL, ofxUICanvas *canvas, bool _hasCenter) {
        
        pos.set(posX, posY, 0);
        angel = atan2(posY, posX);
        radius = ofDist(0, 0, posX, posY);
        oldRadius = radius;
        change = true;
        hasCenter = _hasCenter;
        
        debugMode = false;
        
        distcenter = 2000;
        
        ColorButtonFill = ofColor(255, 255, 255, 200);
        ColorButtonHighLight = ofColor(255, 255, 255, 240);
        
        ColorCenterButtonFill = ofColor(200, 50, 50, 200);
        ColorCenterButtonHighLight = ofColor(200, 50, 50, 240);
        
        verdana.loadFont("Arial Unicode.ttf", 10, true, true);
        
        verdana.setLineHeight(18.0f);
        verdana.setLetterSpacing(1.037);

        verdana2.loadFont("Arial Unicode.ttf", 3, true, true);
        
        if (id < 6)
        {
            direction = -1;
            buttonName = convertInt(id + 1);
        }
        if (id >5 && id < 9)
        {
            direction = 1;
            buttonName = convertInt(id - 5);
        }
        
        bDragged = -1;
        tempID = -1;
        myButton  = new ofxUIImageButton(picWidth, picHeight, true, picURL, convertInt(id));
        myLabel = new ofxUILabel(posX + picWidth, posY, "Dang! Dang! Dang!", 10);
        myLabel->setFont(&verdana);
        
        myLabel->setVisible(false);
        myButton->setValue(false);
        
        canvas->addWidgetDown(myLabel);
		canvas->addWidgetDown(myButton);
        center.set(centerX, centerY, 0);
        if (hasCenter) {
            centerOne.loadImage("GUI/button.png");
            centerOne.setAnchorPercent(0.5, 0.5);
            draw(100, 100);
        }
        else draw(100);
        
        myButton->setDrawPadding(false);
        myButton->setDrawPaddingOutline(false);
        myButton->setDrawBack(false);
        myButton->setColorFill(ofColor(255, 200));
        myButton->setColorFillHighlight(ofColor(255, 240));
                                  
    }
    
    void init(int id, int picWidth, int picHeight, int posX, int posY, int centerX, int centerY, string picURL, ofxUICanvas *canvas, ofColor centerfill, ofColor centerHighLight)
    {
        init(id, picWidth, picHeight, posX, posY, centerX, centerY, picURL, canvas, true);
        ColorCenterButtonFill = centerfill;
        ColorCenterButtonHighLight = centerHighLight;
    }
    
    //----------------------------------------------------------------
    void moveTo(int x, int y, float dist) {
        pos.set(x - center.x, y - center.y, 0);
        oldRadius = radius;
        
        //distcenter = dist;
        
        if (radius >= 0) {
            radius = ofDist(pos.x, pos.y, 0, 0);
            
        }
        else
        {
            radius = -ofDist(pos.x, pos.y, 0, 0);
        }
        
    }
    
    void timecontrolmoveTo(int x, int y) {
        oldRadius = radius;
        fingerangle = atan2(x - center.x, y - center.y);
        if (fingerangle > 0.1 - PI && fingerangle < PI - 0.1) {
            float newX = radius * cos(PI/2 - fingerangle);
            float newY = radius * sin(PI/2 - fingerangle);
            pos.set(newX, newY, 0);
        }
        else
        {
            ofPoint thispos;
            int thisY;
                            
            
            if (y - center.y >  - 5 - 5 - 32 * 11) {
                thisY = (y - center.y + 5)/11;
                pos.set(-(- 5 + 11 * thisY) * cos(PI/2 - fingerangle),  - 5 + 11 * thisY);
            }
            
        }
        
    }
    
    void draw(float sizeRing_PanelTemperature, float sizeCircle_PanelVoltage) {
        myButton->getRect()->setWidth(sizeRing_PanelTemperature);
        myButton->getRect()->setHeight(sizeRing_PanelTemperature);
        myButton->getRect()->x = pos.x + center.x - myButton->getRect()->width/2;
        myButton->getRect()->y = pos.y + center.y - myButton->getRect()->height/2;

        
        myLabel->getRect()->x = pos.x + center.x + myButton->getRect()->width/2;
        myLabel->getRect()->y = pos.y + center.y - myLabel->getRect()->height;
        

        myLabel->getColorFill() = ofColor(255,255);
        string content = "SIDE PANEL ";
        content.append(buttonName);
        

        if (distcenter < sizeCircle_PanelVoltage/2)
        {
            //中心小圆的颜色是在这里定义的。
            ofSetColor(ColorCenterButtonHighLight, ColorButtonHighLight.a);
            content.append("\nSOLAR ARRAY VOLTAGE\n").append(converFloat(sizeCircle_PanelVoltage));
            
        }
        else
        {
            //中心小圆的颜色是在这里定义的。
            ofSetColor(ColorCenterButtonFill, ColorButtonFill.a);
            content.append("\nTEMPERATURE\n").append(converFloat(sizeRing_PanelTemperature));
        }

        
        centerOne.draw(pos + center, sizeCircle_PanelVoltage, sizeCircle_PanelVoltage);
        ofSetColor(0, 0, 0, myButton->getColorFill().a);
        ofLine(pos + center, Hungary + center);
        
        if (myButton->getValue()) {
            myLabel->setLabel(content);
            myLabel->setVisible(true);

        }
        else myLabel->setVisible(false);
    }
    void draw(float sizeRing_OnBoardTemperature) {
        myButton->getRect()->setWidth(sizeRing_OnBoardTemperature);
        myButton->getRect()->setHeight(sizeRing_OnBoardTemperature);
        myButton->getRect()->x = pos.x + center.x - myButton->getRect()->width/2;
        myButton->getRect()->y = pos.y + center.y - myButton->getRect()->height/2;
        
        myLabel->getRect()->x = pos.x + center.x + myButton->getRect()->width/2;
        myLabel->getRect()->y = pos.y + center.y - myLabel->getRect()->height;
        

        ofSetColor(0, 0, 0, myButton->getColorFill().a);
        ofLine(pos + center, Hungary + center);

        myLabel->getColorFill() = ofColor(255,255);
        if (myButton->getValue()) {
            string content = "ON BOARD SYSTEM ";
            content.append(buttonName);
            content.append("\nTEMPERATURE\n");
            //content.append(buttonName).append("\n");
            
            myLabel->setLabel( content.append(converFloat(sizeRing_OnBoardTemperature)));
            
            myLabel->setVisible(true);

        }
        else myLabel->setVisible(false);
    }

    void timecontroldraw(int timer_count)
    {
        ofColor biggerOutside = ofColor(146, 71, 44, 150);
        ofColor biggerInside = ofColor(204, 99, 69, 150);
        ofColor small = ofColor(100, 45, 40, 150);

//        ofColor biggerOutside = ofColor(0);
//        ofColor biggerInside = ofColor(0);
//        ofColor small = ofColor(0);

        
        myButton->getRect()->x = pos.x + center.x - myButton->getRect()->width/2;
        myButton->getRect()->y = pos.y + center.y - myButton->getRect()->height/2;
        //ofSetColor(225, 20, 30, myButton->getColorFill().a);
        ofSetColor(biggerOutside.r, biggerOutside.g, biggerOutside.b, timer_count);
        ofFill();
        ofCircle( pos.x + center.x, pos.y + center.y, 35);
        ofSetColor(biggerOutside);
        ofFill();
        ofCircle( pos.x + center.x, pos.y + center.y, 15);
        ofSetColor(0, 0, 0, 255);
        ofNoFill();
        ofCircle( pos.x + center.x, pos.y + center.y, 15);
        ofSetColor(biggerInside);
        ofFill();
        ofCircle( pos.x + center.x, pos.y + center.y, 5);
        ofSetColor(0);
        ofNoFill();
        ofCircle( pos.x + center.x, pos.y + center.y, 5);
        
        
        
        ofSetColor(small.r, small.g, small.b, 200);
        ofFill();
        
    
        
        float newangle = atan2f(pos.y, pos.x);
        int tester2 = newangle / ((2 * PI)/7);
        float newangle2 = (newangle - ((2 * PI)/7) * tester2) * 7;
        int tempR = -5 - 32 * 11;
        
        ofCircle( tempR * cos(newangle2) + center.x, tempR * sin(newangle2) + center.y, 25);
        ofSetColor(small);
        ofFill();
        ofCircle( tempR * cos(newangle2) + center.x, tempR * sin(newangle2) + center.y, 5);
        ofSetColor(0);
        ofNoFill();
        ofCircle( tempR * cos(newangle2) + center.x, tempR * sin(newangle2) + center.y, 5);
        ofFill();
        
        //int counttest = 0 + ceil(3494 * (newangle2 - PI/2)/(2 * PI));
        float counttest = 0 + 3494 * (newangle2 - PI/2)/(2 * PI);
        if (counttest < 0) {
            counttest = counttest + 3494;
        }
        if (counttest < 0) {
            counttest = counttest + 3494;
        }

        //浮点数的四舍五入
        counttest = (int) (counttest + 0.5);
        if (counttest == 3494) {
            counttest = 0;
        }
        if (counttest == 0) {
            pos.y = -(5 + 32 * 11);
            pos.x = 0;
        }
        TimeControlorCount = counttest;
        //这里大概每过3轮可能会产生一个1的差异，所以以后需要再进行修改使得每轮进行一次匹配
        
    }
	
    //----------------------------------------------------------------	
    void update(float radSpeed_PanelVoltage, ofPoint _Hungary) {
   // this one is subtracted cos world Y is opposite to opengl Y
        //
        
        Hungary = _Hungary;
        
        if (bDragged == -1) {
            pos.x = radius * cos(angel + spin * PI/180);
            pos.y = radius * sin(angel + spin * PI/180);
            spin += radSpeed_PanelVoltage;
            if (spin > 360) {
                spin -= 360;
            }
            oldRadius = radius;
        }
        else
        {
            spin = 0;
            angel = atan2(pos.y, pos.x);
            radius = ofDist(pos.x, pos.y, 0, 0);


        }
        
    }
	
    void timecontrolupdate(float radSpeed_PanelVoltage) {
        
        if (bDragged == -1) {
            pos.x = radius * cos(angel + spin * PI/180);
            pos.y = radius * sin(angel + spin * PI/180);
            spin += radSpeed_PanelVoltage;
            if (spin > 360) {
                spin -= 360;
            }
            oldRadius = radius;
        }
        else
        {
            spin = 0;
            angel = atan2(pos.y, pos.x);
            radius = ofDist(pos.x, pos.y, 0, 0);         
        }
        
    }

    
    //----------------------------------------------------------------

	
    //----------------------------------------------------------------	

    string convertInt(int number)
    {
        if (number == 0)
            return "0";
        string temp="";
        string returnvalue="";
        while (number>0)
        {
            temp+=number%10+48;
            number/=10;
        }
        for (int i=0;i<temp.length();i++)
            returnvalue+=temp[temp.length()-i-1];
        return returnvalue;
    }
    string converFloat(float number)
    {
        char* str = new char[30];   
        sprintf(str, "%.4g", number );
        return str;
    }
};



#endif
