
#include <AFMotor.h>

int motorspeed=500;
int ch1; 
int ch2; 
int potenR;
int potenL;

AF_DCMotor motorUR(1);
AF_DCMotor motorUL(2);
AF_DCMotor motorDL(3);
AF_DCMotor motorDR(4);

AF_DCMotor allmotors[4] = {motorUR, motorUL, motorDL, motorDR};
int nmotor = 1;

void setup() {

  Serial.begin(9600);

  pinMode(A5, INPUT);

  motorUR.setSpeed(127);  // speed: 0 to 255
  motorUR.run(RELEASE);

  motorUL.setSpeed(127);  // speed: 0 to 255
  motorUL.run(RELEASE);

  motorDL.setSpeed(127);  // speed: 0 to 255
  motorDL.run(RELEASE);

  motorDR.setSpeed(127);  // speed: 0 to 255
  motorDR.run(RELEASE);

}

void loop() {

  
  ch1 = -((pulseIn(A5, HIGH))/100)+13;
  potenR = (255/3)*ch1;
  potenL = (255/3)*ch1;

  ch2 = -((pulseIn(A4, HIGH))/100)+16;
    if(ch2==-3 and ch1==0){
      motorUL.run(FORWARD);
      motorDL.run(FORWARD);
    potenL = potenL + 255;
  }
   if(ch2>3 and ch1==0){
     motorUR.run(FORWARD);
     motorDR.run(FORWARD);
    potenR = potenR + 255;
  }
  if(ch1>0){
    motorUR.run(FORWARD);
    motorUL.run(FORWARD);
    motorDR.run(FORWARD);
    motorDL.run(FORWARD);
  }
  else if(ch1<0){
    motorUR.run(BACKWARD);
    motorUL.run(BACKWARD);
    motorDR.run(BACKWARD);
    motorDL.run(BACKWARD);
    potenR = -potenR;
    potenL = -potenL;
  }

  motorUR.setSpeed(potenR);  // speed: 0 to 255
  motorUL.setSpeed(potenL);  // speed: 0 to 255
  motorDR.setSpeed(potenR);  // speed: 0 to 255
  motorDL.setSpeed(potenL);  // speed: 0 to 255


  Serial.print(ch1);
  Serial.print(" : ");
  Serial.print(ch2);
  Serial.print(" :    ");
  Serial.print(potenL);
  Serial.print(" W ");
  Serial.println(potenR);

    potenR =0;
    potenL =0;
}

