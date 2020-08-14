#include"controller.h"
#include<Arduino.h>
//#define DEBUG // Srial.printを有効にする時

Btd btd;
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
         code
         */
        #ifdef DEBUG 
        Serial.println("y");
        Serial.println(y);
        delay(1000);
        #endif
    }

    else if(theta(x,y)>=-110&&theta(x,y)<=-70){
        //back;
        
        /*
         code
         */

        #ifdef DEBUG 
        Serial.println("y");
        Serial.println(y);
        delay(1000);
        #endif

    }

    else if(theta(x,y)>=-20&&theta(x,y)<=20){
        //right;
        

        /*
         code
         */
        #ifdef DEBUG 
        Serial.println("x");
        Serial.println(x);
        delay(1000);
        #endif
    }
    
    else if(theta(x,y)>=160&&theta(x,y)<180.1){
        //left
        
        /*
         code
         */

        #ifdef DEBUG 
        Serial.println("x");
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
