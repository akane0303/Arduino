#ifndef INVERSE_H
#define INVERSE_H
#include<Arduino.h>
namespace Inv{
    class Mo {
        private:
            int pin2;
            int pin1;
        public:
            Mo() {}
            Mo(int pin1_, int pin2_):pin2(pin2_),pin1(pin1_){
		        pinMode(pin1,OUTPUT);
		        pinMode(pin2,OUTPUT);
            }
            void run(int speed);
};
    class Omni4{
        private:
            Mo m0,m1,m2,m3;
        public:
            int m[4];
            int r,limit;
            Omni4(int R,int lim,Mo m0_,Mo m1_, Mo m2_, Mo m3_):r(R),limit(lim),m0(m0_),m1(m1_),m2(m2_),m3(m3_){}
            void speed(int x,int y,int z,int th);  
    };

    class Omni3{

        private:
            Mo m0,m1,m2;
        public:
            int m[3];
            int r,limit;
            Omni3(int R,int lim ,Mo m0_,Mo m1_, Mo m2_):r(R),limit(lim),m0(m0_),m1(m1_),m2(m2_){}
             void speed(int x,int y,int z,int th);  
    };

    class dif{
        private:
            Mo m0,m1;
        public:
            int m[2];
            int r,limit;
            dif(int R,int lim,Mo m0_,Mo m1_):r(R),limit(lim),m0(m0_),m1(m1_){}
            void speed(int x,int y,int z,int th);  
    };

    class Mecanum{
        private:
            Mo m0,m1,m2,m3;
        public:
            int m[4];
            int r,limit;
            Mecanum(int R,int lim,Mo m0_,Mo m1_, Mo m2_, Mo m3_):r(R),limit(lim),m0(m0_),m1(m1_),m2(m2_),m3(m3_){}
            void speed(int x,int y,int z,int th);  
    };
}

#endif
