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
int puedesercentro = 0;

int distanceM1;
int distanceM2;
int distanceM3;

bool finaltry = false;
bool revisar = true;

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
puedesercentro = 0;
finaltry = false;

for(int i=0;i<=69;i++){
puedesercentro = 0;

finaltry = false;


potenL= 127;
potenR= 127;
distance = calculateDistance();

if((distance >= 30) and (i == 1)){
revisar == false;
}

if (revisar == true){

  myServo.write(20);

  delay(10);


  if (distance > 150){
    puedesercentro = puedesercentro + 1;
    if (puedesercentro >= 10){
       potenL= 255;
       motorDL.run(FORWARD);
       motorUL.run(FORWARD);
       motorUL.setSpeed(potenR);  // speed: 0 to 255
       motorDL.setSpeed(potenR);  // speed: 0 to 255
       delay(400);
       potenL= 0 ;
       potenR= 0 ;

       motorDR.run(FORWARD);
       motorDL.run(FORWARD);
       motorUR.run(FORWARD);
       motorUL.run(FORWARD);
       motorUR.setSpeed(potenR);  // speed: 0 to 255
       motorUL.setSpeed(potenL);  // speed: 0 to 255
       motorDR.setSpeed(potenR);  // speed: 0 to 255
       motorDL.setSpeed(potenL);  // speed: 0 to 255
       delay(500);
       potenL= 255 ;
       potenR= 255 ;

       motorDR.run(FORWARD);
       motorDL.run(FORWARD);
       motorUR.run(FORWARD);
       motorUL.run(FORWARD);
       motorUR.setSpeed(potenR);  // speed: 0 to 255
       motorUL.setSpeed(potenL);  // speed: 0 to 255
       motorDR.setSpeed(potenR);  // speed: 0 to 255
       motorDL.setSpeed(potenL);  // speed: 0 to 255
       delay(500);
       puedesercentro = 0;
    }
  }

  if(distance >= 50){
  potenR = ((50/distance) * 127) ;
  }
  if(distance <= 50){
  potenL = ((distance/50) * 127) ;
  }

  potenL= potenL ;
  potenR= potenR ;

  motorDR.run(FORWARD);
  motorDL.run(FORWARD);
  motorUR.run(FORWARD);
  motorUL.run(FORWARD);
  motorUR.setSpeed(potenR);  // speed: 0 to 255
  motorUL.setSpeed(potenL);  // speed: 0 to 255
  motorDR.setSpeed(potenR);  // speed: 0 to 255
  motorDL.setSpeed(potenL);  // speed: 0 to 255
    
  /*
    Serial.print(i);
    Serial.print("     ");
    Serial.print(distance);
    Serial.print("     ");
    Serial.print(potenL);
    Serial.print(" W ");
    Serial.println(potenR);
    */

}

  }

potenL= 0;
potenR= 0;

motorDR.run(RELEASE);
motorDL.run(RELEASE);
motorUR.run(RELEASE);
motorUL.run(RELEASE);

myServo.write(110);


/*
while (distanceM1 != distanceM2){

distanceM1 = calculateDistance();
delay(200);
distanceM2 = calculateDistance();
delay(200);

distance = distanceM1;

}
*/
delay(500);
distance = calculateDistance();
delay(100);
Serial.println(distance);


if (distance < 70){
  revisar = false;

}

if (distance < 30){
  
  potenR= 255;
  motorDR.run(FORWARD);
  motorUR.run(FORWARD);
  motorUR.setSpeed(potenR);  // speed: 0 to 255
  motorDR.setSpeed(potenR);  // speed: 0 to 255
  delay(400);
  revisar = true;
}
else{
  
  potenL= 127;
  potenR= 127;

  motorDR.run(FORWARD);
  motorDL.run(FORWARD);
  motorUR.run(FORWARD);
  motorUL.run(FORWARD);
  motorUR.setSpeed(potenR);  // speed: 0 to 255
  motorUL.setSpeed(potenL);  // speed: 0 to 255
  motorDR.setSpeed(potenR);  // speed: 0 to 255
  motorDL.setSpeed(potenL);  // speed: 0 to 255
}
}





