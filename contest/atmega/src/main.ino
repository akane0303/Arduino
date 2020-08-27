#include<Arduino.h>
#include<PS3BT.h>
#include<PS3USB.h>
#include<usbhub.h>
#include<motor.h>

USB Usb;
BTD Btd(&Usb);
PS3BT PS3(&Btd);

Motor mo0(3,4);
Motor mo1(5,6);
Motor mo2(7,8);
Motor mo3(9,10);

Omni omni(170,mo0,mo1,mo2,mo3);
int direction(int x, int y) {
  double deg , rad;
  int pattern = 0;
  x -= 128;
  y = abs(y - 256) - 128;
  rad = atan2((double)y, (double)x);
  deg = rad * 180.0 / (atan(1.0) * 4.0);
  if (abs(x) > 16 || abs(y) > 16) {
    deg += 180.0;
    for (int i = 0; i < 8; i++) {
      if (deg >= 0.0 + (i * 45.0) && deg < 45.0 + (i * 45.0)) {//分割数を指定
        pattern = i + 1;
      }
    }
  }
  return pattern;
}

void setup(){
    Serial.begin(115200);
    if(Usb.Init()==-1){
        Serial.print(F("\r\nOSC did not start"));
        while(1);
    }
    Serial.print("started");
}

void loop(){
    Usb.Task();

    if(PS3.PS3Connected||PS3.PS3NavigationConnected){

        double r=0.6;
        
		double lx = PS3.getAnalogHat(LeftHatX);
		double ly = PS3.getAnalogHat(LeftHatY);
        double rx = PS3.getAnalogHat(RightHatX);
        double ry = PS3.getAnalogHat(RightHatY);
		double cwx=(lx-140)*r;//(50+(lx-128))*0.6;
		double cwy=-(ly-140)*r;//-(127-(abs(ly-256)));
		double ccwx=(lx-115)*r;//abs(-50+(lx-128))*0.6;
		double ccwy=abs(ly-115)*r;//abs(-127-(abs(ly-235)))*0.5;
        double fr=sqrt(pow(cwx,2)+pow(cwy,2))*0.8;
        double fl=sqrt(pow(ccwx,2)+pow(cwy,2))*0.8;
        double bl=sqrt(pow(ccwx,2)+pow(ccwy,2))*0.8;
        double br=sqrt(pow(cwx,2)+pow(ccwy,2))*0.8;

    

		if (PS3.getAnalogHat(LeftHatX) > 137||PS3.getAnalogHat(LeftHatX) < 117|| PS3.getAnalogHat(LeftHatY) > 137|| PS3.getAnalogHat(LeftHatY) < 117){  
				switch (direction(PS3.getAnalogHat(LeftHatX), PS3.getAnalogHat(LeftHatY))){
					case 0:
                        omni.move(0,0,0);
						break;
					case 1:
					case 8:
                        omni.move(ccwx,0,0);
						break;
					case 2:
					case 3:
                        omni.move(0,ccwy,0);
						break;
					case 4:
					case 5:
                        omni.move(cwx,0,0);
						break;

					case 6:
					case 7:
                        omni.move(0,cwy,0);
						break;
                    default:
                        break;
				}
			}
	  else{

			if(PS3.getButtonPress(CIRCLE)){
			}
			else if(PS3.getButtonPress(CROSS)){
			}
            else if(PS3.getButtonPress(TRIANGLE)){
            }

            else if(PS3.getButtonPress(SQUARE)){
            }
            else if(PS3.getButtonPress(UP)){
            }
               
            else if(PS3.getButtonPress(DOWN)){
            }

            else if(PS3.getButtonPress(RIGHT)){
            }

            else if(PS3.getButtonPress(LEFT)){
            }
                    
            else{

                omni.move(0,0,0);
            }

		}
       
	}
}
