// Librerías:

#include <AFMotor.h>
#include <Servo.h> 


// Variables:

const int trigPin = A2;
const int echoPin = A3;

long duration;
int distance;

int motorspeed=200;
int ch1; 
int ch2; 
int potenR;
int potenL;


// Motores:

AF_DCMotor motorUR(1);
AF_DCMotor motorUL(2);
AF_DCMotor motorDL(3);
AF_DCMotor motorDR(4);

Servo myServo; 





void setup() {

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT); 
  Serial.begin(9600);
  myServo.attach(10);

  Serial.begin(9600);

  pinMode(A5, INPUT);

  motorUR.setSpeed(255);  // speed: 0 to 255
  motorUR.run(RELEASE);

  motorUL.setSpeed(255);  // speed: 0 to 255
  motorUL.run(RELEASE);

  motorDL.setSpeed(255);  // speed: 0 to 255
  motorDL.run(RELEASE);

  motorDR.setSpeed(255);  // speed: 0 to 255
  motorDR.run(RELEASE);

}






// error:



int calculateDistance(){ 
  
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH); 
  distance= duration*0.034/2;
  return distance;
}












// Loop:

void loop() {

for(int i=0;i<=100;i++){

potenL= 127;
potenR= 127;
distance = calculateDistance();

myServo.write(25);

if(distance >= 30){
potenR = ((30/distance) * 255) ;
}
if(distance <= 30){
potenL = ((distance/30) * 255) ;
}

motorDR.run(FORWARD);
motorDL.run(FORWARD);
motorUR.run(FORWARD);
motorUL.run(FORWARD);
motorUR.setSpeed(potenR);  // speed: 0 to 255
motorUL.setSpeed(potenL);  // speed: 0 to 255
motorDR.setSpeed(potenR);  // speed: 0 to 255
motorDL.setSpeed(potenL);  // speed: 0 to 255
  
 
  Serial.print(i);
  Serial.print("     ");
  Serial.print(distance);
  Serial.print("     ");
  Serial.print(potenL);
  Serial.print(" W ");
  Serial.println(potenR);
  
  }

potenL= 0;
potenR= 0;

myServo.write(90);
distance = calculateDistance();
delay(2000);
if (distance <= 80){
  for(int j=0; j <30; j++){
  potenR= 255;
  }
}
}





