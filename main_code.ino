//2 eye servos attached to pin 4
//head servo attached to pin 5
//mouth servo attached to pin 6
//ear servo attached to pin 7
//tail servo attached to pin 8

//bluetooth connected to serial 1 not serial0
//
#include <Servo.h>

//servo objects
Servo eye_servo;
Servo head_servo;
Servo mouth_servo;
Servo ear_servo;
Servo tail_servo;

//variables
char code;
int pos;
int i = 0;

void setup() {
//  setup bluetooth baud 9600
  Serial1.begin(9600);
//  attach servos
  eye_servo.attach(4);
  head_servo.attach(5);
  mouth_servo.attach(6);
  ear_servo.attach(7);
  tail_servo.attach(8);
//set servos to neutral position and wait for 5 seconds
  eye_servo.write(90);  
  head_servo.write(90);
  mouth_servo.write(10);
  ear_servo.write(90);
  tail_servo.write(90);
  delay(5000);
}

void loop(){
  if(Serial1.available()>0){  
    code = Serial1.read();
  }
  switch(code){
    case '1':
    //roar
    //opens mouth and waits 5 seconds for roar then closes 
      for(pos=10;pos<=170;pos+=1){
          mouth_servo.write(pos);
          delay(30);
      }
      delay(5000);
      for(pos=170;pos>=10;pos-=1){
          mouth_servo.write(pos);
          delay(30);
      }
      break;
    case('2'):
    //head roll
    //rolls head left to right three times
      i = 0; 
      while(i < 3){
        for(pos=90;pos<=140;pos+=1){
            head_servo.write(pos);
            delay(20);
        }
        for(pos=140;pos>=50;pos-=1){
            head_servo.write(pos);
            delay(20);
        }
        for(pos=50;pos<=90;pos+=1){
            head_servo.write(pos);
            delay(20);
        }
        i+=1;
      }   
      break;
    case('3'):
    //wiggle ears 5 times
      i = 0;
      while(i<5){
        for(pos=90;pos<=170;pos+=1){
            ear_servo.write(pos);
            delay(20);
        }
        for(pos=170;pos>=10;pos-=1){
            ear_servo.write(pos);
            delay(20);
        }
        for(pos=10;pos<=90;pos+=1){
            ear_servo.write(pos);
            delay(20);
        }
        i+=1;
      } 
      break;
    case('4'):
    //chuff
    //delays 5 seconds for chuffing noise
      for(pos=10;pos<=170;pos+=1){
          mouth_servo.write(pos);
          delay(30);
      }
      delay(5000);
      for(pos=170;pos>=10;pos-=1){
          mouth_servo.write(pos);
          delay(30);
      }
      break;
    case('5'):
    //wag tail for 10 times
      i = 0;
      while(i<10){
        for(pos=90;pos<=170;pos+=1){
            tail_servo.write(pos);
            delay(20);
        }
        for(pos=170;pos>=10;pos-=1){
            tail_servo.write(pos);
            delay(20);
        }
        for(pos=10;pos<=90;pos+=1){
            tail_servo.write(pos);
            delay(20);
        }
        i+=1;
      }
      break;
    case('6'):
      //look left and right 10 times
      i = 0;
      while(i<10){
        for(pos=90;pos<=120;pos+=1){
            eye_servo.write(pos);
            delay(20);
        }
        for(pos=120;pos>=60;pos-=1){
            eye_servo.write(pos);
            delay(20);
        }
        for(pos=60;pos<=90;pos+=1){
            eye_servo.write(pos);
            delay(20);
        }
        i+=1;
      }
      break;
    default:
    //incase you program more buttons moves eyes and tail and ears    
      i = 0;
      while(i<2){
        for(pos=90;pos<=150;pos+=1){
            eye_servo.write(pos);
            tail_servo.write(pos);
            ear_servo.write(pos);
            delay(20);
        }
        for(pos=150;pos>=30;pos-=1){
            eye_servo.write(pos);
            tail_servo.write(pos);
            ear_servo.write(pos);
            delay(20);
        }
        for(pos=30;pos<=90;pos+=1){
            eye_servo.write(pos);
            tail_servo.write(pos);
            ear_servo.write(pos);
            delay(20);
        }
        i+=1;
      }
      break;
  }
}


