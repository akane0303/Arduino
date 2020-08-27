#include<controller.h>
#include<motor.h>
#include<Arduino.h>
#include<Servo.h>
//#define DEBUG // Srial.printを有効にする時

Btd btd;
Motor mo0(3,4);
Motor mo1(5,6);
Motor mo2(7,8);
Motor mo3(9,10);

Omni omni(170,mo0,mo1,mo2,mo3);

double theta(double x_,double y_){

    double x=(x_-64)*4;
    double y=-1*(y_-64)*4;
    float rad=atan2(y,x);
    float deg=rad/PI*180;

    return deg;
}


void setup(){
    mySerial.begin(2400);
    Serial.begin(19200);
}

void loop(){
    btd.Task();
    
    int x=(btd.Left_x-64)*4;
    int y=-1*(btd.Left_y-64)*4;
    if(theta(x,y)>=70&&theta(x,y)<=110){
        //front
        /*
        omni.move(0,y,0);
         */
        #ifdef DEBUG 
        Serial.print("y :");
        Serial.println(y);
        delay(1000);
        #endif
    }

    else if(theta(x,y)>=-110&&theta(x,y)<=-70){
        //back;
        
        
         omni.move(0,y,0);
         

        #ifdef DEBUG 
        Serial.print("y :");
        Serial.println(y);
        delay(1000);
        #endif

    }

    else if(theta(x,y)>=-20&&theta(x,y)<=20){
        //right;
        

        /*
         omni.move(x,0,0)
         */
        #ifdef DEBUG 
        Serial.print("x :");
        Serial.println(x);
        delay(1000);
        #endif
    }
    
    else if(theta(x,y)>=160&&theta(x,y)<180.1){
        //left
        
        /*
         omni.move(x,0,0);
         */

        #ifdef DEBUG 
        Serial.print("x :");
        Serial.println(x);
        delay(1000);
        #endif

    }
    else if(theta(x,y)==0){
        //Serial.println(0);
    }
    else if(btd.getButtonPress("CIRCLE")){
        //button;

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
    else {

       // 
    }
    
}
