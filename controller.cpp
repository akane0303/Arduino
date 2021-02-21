#include"controller.h"
#include"motor.h"
#include<Arduino.h>
#include<Servo.h>
//#define DEBUG // Srial.printを有効にする時コメント化解除

Btd btd;
Motor mo0(PB6,PC7);
Motor mo1(PA5,PA8);
Motor mo2(PB10,PB4);
Motor mo3(PB5,PB3);
Omni omni(170,mo0,mo1,mo2,mo3);
double theta(double x_,double y_){
    //double x=(x_-64)*4;
    //double y=-1*(y_-64)*4;
    float rad=atan2(y_,x_);
    float deg=rad/PI*180;
    return deg;
}
void setup(){
    
    
    mySerial.begin(2400);
    Serial.begin(9600);
    
}
void loop(){
    btd.Task();
    
    int v;
    int x=(btd.Left_x-64)*4;
    int y=-1*(btd.Left_y-64)*4;
    /*
    Serial.print("x:");
    Serial.println(x);
    Serial.print("y:");
    Serial.println(y);
    */
    //double deg=theta(x,y);
    //Serial.println(deg);
   // delay(500);
    
    //Serial.println(theta(x,y));
    
    if(theta(x,y)>=60&&theta(x,y)<=120){
       v = sqrt(x*x+y*y);        //front;
       // Serial.println("f");
      //  Serial.println(y);
       
       omni.move(0,v,0);
        
        //omni.move(0,y,0);
       //Serial.print("front");  
         
        #ifdef DEBUG 
        Serial.print("front");  
        Serial.print("y :");
        Serial.println(y);
        delay(1000);
        #endif
        
    }
    else if(theta(x,y)>=-120&&theta(x,y)<=-60){
       v = -sqrt(x*x+y*y);
        //back;
       omni.move(0,v,0);
        
        #ifdef DEBUG 
        Serial.print("y :");
        Serial.println(y);
        delay(1000);
        Serial.print("back");
        #endif
    }
    else if((theta(x,y)>=-30&&theta(x,y)<0)||(theta(x,y)>0&&theta(x,y)<=30)){
       v = sqrt(x*x+y*y);
        //right;
      omni.move(v,0,0);
        /*
         omni.move(x,0,0)
         */
        #ifdef DEBUG 
        Serial.print("x :");
        Serial.println(x);
        delay(1000);
        Serial.print("right");
        #endif
    }
    
    else if((theta(x,y)<=180&&theta(x,y)>=150)||(theta(x,y)>=-180&&theta(x,y)<=-150)){
        //left;
         v = -sqrt(x*x+y*y);
         omni.move(v,0,0);
         
        //Serial.print("left");
    
        #ifdef DEBUG 
         Serial.print("left");
        Serial.print("x :");
        Serial.println(x);
        delay(1000);
        #endif
    }
    else{
        if(btd.getButtonPress("CIRCLE")){
            Serial.println("cir");
        //button;
            digitalWrite(PB6,HIGH);
        //digitalWrite(PC7,LOW);
        }
        else if(btd.getButtonPress("SQUARE")){
    
        //button
        }
        else if(btd.getButtonPress("CROSS")){
        //button
        }
        else if(btd.getButtonPress("TRIANGLE")){
        //button
        }
    
        else if(btd.getButtonPress("UP")){
        //button
        }
    
        else if(btd.getButtonPress("DOWN")){
        //button
        }
    
        else if(btd.getButtonPress("LEFT")){
        //button
        }

        else if(btd.getButtonPress("RIGHT")){
        //button
        }

        else if(btd.getButtonPress("L1")){
        //button
        }

        else if(btd.getButtonPress("L2")){
        //button
        }

        else if(btd.getButtonPress("R2")){
        //button
        }

        else if(btd.getButtonPress("R1")){
        //button
        }
        else {
            omni.move(0,0,0);
       // 
        }
    
    }
