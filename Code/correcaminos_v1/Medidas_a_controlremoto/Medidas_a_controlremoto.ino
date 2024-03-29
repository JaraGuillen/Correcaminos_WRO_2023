// Librerías:

#include <AFMotor.h>
#include <Servo.h> 


// Variables:

const int trigPin = A2;
const int echoPin = A3;

long duration;
int distance;
int direction;
int danger;

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

  motorUR.setSpeed(127);  // speed: 0 to 255
  motorUR.run(RELEASE);

  motorUL.setSpeed(127);  // speed: 0 to 255
  motorUL.run(RELEASE);

  motorDL.setSpeed(127);  // speed: 0 to 255
  motorDL.run(RELEASE);

  motorDR.setSpeed(127);  // speed: 0 to 255
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




// Servo:
int movimiento_de_servo(int i, int distance){
if(i<60){direction=1;} else if(i>60 and i<120){direction=2;} else if(i>120 and i<180){direction=3;}  
myServo.write(i);
if(distance<30){danger=1;} else if(distance<200){danger=2;} else{danger=3;}  
}





// Radiocontrol:
int movimientoRC(){
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
}






// Loop:

void loop() {

for(int i=0;i<=200;i++){

distance = calculateDistance();

movimiento_de_servo(i, distance);

movimientoRC();

  
  Serial.print(i); 
  Serial.print(","); 
  Serial.print(distance);
  Serial.print("  Dir: ");
  Serial.print(direction);
  Serial.print("  Dan: ");
  Serial.print(danger);
  Serial.print(" "); 
  Serial.print(ch1);
  Serial.print(" : ");
  Serial.print(ch2);
  Serial.print(" :    ");
  Serial.print(potenL);
  Serial.print(" W ");
  Serial.println(potenR);
  
  }

}



