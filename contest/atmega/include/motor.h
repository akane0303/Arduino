#ifndef MOTOR_H
#define MOTOR_H
class Motor{
    private:
        int pin1;
        int pin2;
    public:
        Motor(){;}
        Motor(int _pin1,int _pin2):pin1(_pin1),pin2(_pin2){
            
            pinMode(pin1,OUTPUT);
            pinMode(pin2,OUTPUT);
        }
        void run(int speed){
                
            if(speed>=0){
                analogWrite(pin1,speed);
                analogWrite(pin2,0);
            }
            if(speed<=0){
                analogWrite(pin1,0);
                analogWrite(pin2,-speed);
            }
        }

};
class Omni{
    private:
        Motor m0,m1,m2,m3;
    public:
        int m[4];
        int limit;
        Omni(int limit_,Motor m0_,Motor m1_,Motor m2_,Motor m3_):limit(limit_),m0(m0_),m1(m1_),m2(m2_),m3(m3_){ }
        void move(int x,int y,int z){
        
            m[0]=(x*-(sqrt(2)/2)+y*(sqrt(2)/2)+z);
            m[1]=(x*(sqrt(2)/2)+y*(sqrt(2)/2)+z);
            m[2]=(x*-(sqrt(2)/2)+y*(sqrt(2)/2)-z);
            m[3]=(x*(sqrt(2)/2)+y*(sqrt(2)/2)-z);

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
        }
};
#endif
