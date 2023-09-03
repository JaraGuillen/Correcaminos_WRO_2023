//Librairies
#include <AFMotor.h>
//Constants
int motorspeed=200;
int ch1; 
int poten;

AF_DCMotor motorUR(1);
AF_DCMotor motorUL(2);
AF_DCMotor motorDL(3);
AF_DCMotor motorDR(4);

AF_DCMotor allmotors[4] = {motorUR, motorUL, motorDL, motorDR};
int nmotor = 1;

void setup() {

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
  motorUR.run(FORWARD);
  motorUR.run(FORWARD);
  
  ch1 = -((pulseIn(A5, HIGH))/100)+13;
  poten = (255/3)*ch1;

  motorUR.setSpeed(poten);  // speed: 0 to 255
  
/*
motorUR.run(FORWARD);
motorDR.run(FORWARD);
 delay(1000);
motorDR.run(RELEASE);
motorUR.run(RELEASE);
motorUL.run(FORWARD);
motorDL.run(FORWARD);
 delay(1000);
motorUL.run(RELEASE);
motorDL.run(RELEASE);
 delay(1000);
motorUR.run(BACKWARD);
motorDR.run(BACKWARD);
 delay(1000);
motorDR.run(RELEASE);
motorUR.run(RELEASE);
motorUL.run(BACKWARD);
motorDL.run(BACKWARD);
delay(1000);

motorDR.run(RELEASE);
motorDL.run(RELEASE);
motorUL.run(RELEASE);
motorUR.run(RELEASE);
  delay(5000);
*/

}

