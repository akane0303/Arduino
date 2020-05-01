#include"inverse_kinematics.h"
#include<Arduino.h>
namespace Inv{
    void Mo::run(int speed){
        if (speed >= 0) {
            analogWrite(pin1, speed);
            analogWrite(pin2, 0);
        }
        if (speed <= 0) {
            analogWrite(pin1, 0);
            analogWrite(pin2, -speed);
        }
    }
    
    void Omni4::speed(int x,int y,int z,int th){
        m[0]=-x*sin(th+PI/4)+y*cos(th+PI/4)+r*z;
        m[1]=-x*sin(th-PI/4)+y*cos(th-PI/4)+r*z;
        m[2]=x*sin(th+PI/4)-y*cos(th+PI/4)+r*z;
        m[3]=x*sin(th-PI/4)-y*cos(th-PI/4)+r*z;


        if(m[0]>=0)m[0]=min(m[0],limit);
        else m[0]=max(m[0],-limit);
        if(m[1]>=0)m[1]=min(m[1],limit);
        else m[1]=max(m[1],-limit);
        if(m[2]>=0)m[2]=min(m[2],limit);
        else m[2]=max(m[2],-limit);
        if(m[3]>=0)m[3]=min(m[3],limit);
        else m[3]=max(m[3],-limit);
   
        m0.run(m[0]);
        m1.run(m[1]);
        m2.run(m[2]);
        m3.run(m[3]);
        //Mtgo mg;
        //for(int i=0;i<4;i++)mg.mtgo(i,m[i]);
    }

    void Omni3::speed(int x,int y,int z,int th){
        m[0]=-x*cos(th)-y*sin(th)+r*z;
        m[1]=-x*cos(th+PI*2/3)+y*sin(th+PI*2/3)+r*z;
        m[2]=x*cos(th+PI*2/3)+y*(th+PI*2/3)+r*z;

        if(m[0]>=0)m[0]=min(m[0],limit);
        else m[0]=max(m[0],-limit);
        if(m[1]>=0)m[1]=min(m[1],limit);
        else m[1]=max(m[1],-limit);
        if(m[2]>=0)m[2]=min(m[2],limit);
        else m[2]=max(m[2],-limit);
        
        m0.run(m[0]);
        m1.run(m[1]);
        m2.run(m[2]);
    
        //Mtgo mg;
        //for(int i=0;i<3;i++)mg.mtgo(i,m[i]);
    }
    void dif::speed(int x,int y,int z,int th){
        m[0]=r*x+r*y-r*z;
        m[2]=r*x+r*y+r*z;

        m0.run(m[0]);
        m1.run(m[1]);
        //Mtgo mg;
        //for(int i=0;i<2;i++)mg.mtgo(i,m[i]);
    }

    void Mecanum::speed(int x,int y,int z,int th){
        m[0]=-x+y+(th+r);
        m[1]=x+y-(th+r);
        m[2]=-x+y-(th+r);
        m[3]=x+y+(th+r);


        if(m[0]>=0)m[0]=min(m[0],limit);
        else m[0]=max(m[0],-limit);
        if(m[1]>=0)m[1]=min(m[1],limit);
        else m[1]=max(m[1],-limit);
        if(m[2]>=0)m[2]=min(m[2],limit);
        else m[2]=max(m[2],-limit);
        if(m[3]>=0)m[3]=min(m[3],limit);
        else m[3]=max(m[3],-limit);
   
        m0.run(m[0]);
        m1.run(m[1]);
        m2.run(m[2]);
        m3.run(m[3]);
        //Mtgo mg;
        //for(int i=0;i<4;i++)mg.mtgo(i,m[i]);
    }
}

