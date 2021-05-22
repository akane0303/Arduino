#include"controller.h"
#include<Arduino.h>
#include<Servo.h>
//#define DEBUG // Srial.printを有効にする時

Btd btd;
double theta(double x_, double y_) {
  float rad = atan2(y_, x_);
  float deg = rad / PI * 180;
  return deg;
}

void setup() {
  mySerial.begin(2400);
  Serial.begin(9600);
}
void loop() {
  btd.Task();
  int v;
  int x = (btd.Left_x - 64) * 4;
  int y = -1 * (btd.Left_y - 64) * 4;
  
  if (theta(x, y) >= 67.5 && theta(x, y) < 112.5) {
    v = sqrt(x * x + y * y);  //front;
    #ifdef DEBUG
        Serial.print("front");
        Serial.print("y :");
        Serial.println(y);
        delay(1000);
    #endif
  }
  else if (theta(x, y) >= -112.5 && theta(x, y) <= -67.5) {
    v = -sqrt(x * x + y * y);
    //back;
    #ifdef DEBUG
        Serial.print("y :");
        Serial.println(y);
        delay(1000);
        Serial.print("back");
    #endif
  }
  else if ((theta(x, y) > -22.5 && theta(x, y) < 0) || (theta(x, y) > 0 && theta(x, y) < 22.5)) {
    v = sqrt(x * x + y * y);
    //right;
    #ifdef DEBUG
        Serial.print("x :");
        Serial.println(x);
        delay(5000);
        Serial.print("right");
    #endif
  }
  else if ((theta(x, y) <= 180 && theta(x, y) > 157.5) || (theta(x, y) >= -180 && theta(x, y) < -157.5)) {
    //left;
    v = -sqrt(x * x + y * y);
    #ifdef DEBUG
        Serial.print("left");
        Serial.print("x :");
        Serial.println(x);
        delay(1000);
    #endif
  }
  else if (theta(x, y) <= 67.5 && theta(x, y) >= 22.5) {
    //frontRight;
    v = sqrt(x * x + y * y);
  }
  else if (theta(x, y) <= 157.5 && theta(x, y) >= 112.5) {
    //frontLeft;
    v = sqrt(x * x + y * y);
  }
  else if (theta(x, y) <= -22.5 && theta(x, y) >= -67.5) {
    //backRight;
    v = sqrt(x * x + y * y);
  }
  else if (theta(x, y) <= -112.5 && theta(x, y) >= -157.5) {
    //backLeft;
    v = sqrt(x * x + y * y);
  }
  else {
    if (btd.getButtonPress("CIRCLE")) {
    }
    else if (btd.getButtonPress("SQUARE")) {
      
      //button
    }
    else if (btd.getButtonPress("CROSS")) {
      //button
    }
    else if (btd.getButtonPress("TRIANGLE")) {
      //button
    }
    else if (btd.getButtonPress("START")) {
    }
    else if (btd.getButtonPress("UP")) {
    }
    else if (btd.getButtonPress("DOWN")) {
      //button
    }
    else if (btd.getButtonPress("SELECT")) {
      //button
    }
    else if (btd.getButtonPress("LEFT")) {
      //button
    }
    else if (btd.getButtonPress("RIGHT")) {
    }
    else if (btd.getButtonPress("L1")) {
      //button
    }
    else if (btd.getButtonPress("L2")) {
      //button
    }
    else if (btd.getButtonPress("R2")) {
      //button
    }
    else if (btd.getButtonPress("R1")) {
        
    }
    else {
        //stop
    }
  }
}
