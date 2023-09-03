// Includes the Servo library
#include<AFMotor.h>.
#include <Servo.h>. 

// Defines Tirg and Echo pins of the Ultrasonic Sensor
const int trigPin = A2;
const int echoPin = A3;
// Variables for the duration and the distance
long duration;
int distance;
int direction; // 1=Left 2=Forwar 3=Right
int danger; // 1=menos de 30cm, 2=menos de 200cm, 3=más de 300cm.

Servo myServo; // Creates a servo object for controlling the servo motor

void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600);
  myServo.attach(10); // Defines on which pin is the servo motor attached
}
void loop() {
  // rotates the servo motor from 15 to 165 degrees
for(int i=0;i<=180;i++){

  if(i<60){direction=1;} else if(i>60 and i<120){direction=2;} else if(i>120 and i<180){direction=3;}  

  myServo.write(i);
  delay(30);
  distance = calculateDistance();// Calls a function for calculating the distance measured by the Ultrasonic sensor for each degree

 if(distance<30){danger=1;} else if(distance<200){danger=2;} else{danger=3;}  

  if(distance<300){
    Serial.print(i); // Sends the current degree into the Serial Port
    Serial.print(","); // Sends addition character right next to the previous value needed later in the Processing IDE for indexing
    Serial.print(distance); // Sends the distance value into the Serial Port
    Serial.print("  Dir: ");
    Serial.print(direction);
    Serial.print("  Dan: ");
    Serial.print(danger);
    Serial.println(" "); // Sends addition character right next to the previous value needed later in the Processing IDE for indexing
  }

  }
  // Repeats the previous lines from 165 to 15 degrees
for(int i=180;i>0;i--){  

  if(i<60){direction=1;} else if(i>60 and i<120){direction=2;} else if(i>120 and i<180){direction=3;}  

  myServo.write(i);
  delay(30);
  distance = calculateDistance();

  if(distance<30){danger=1;} else if(distance<200){danger=2;} else{danger=3;}  

  if(distance<300){
  Serial.print(i);
  Serial.print(",");
  Serial.print(distance);
  Serial.print("  Dir: ");
  Serial.print(direction);
  Serial.print("  Dan: ");
  Serial.print(danger);
  Serial.println(" ");
  }
  


  }
}
// Function for calculating the distance measured by the Ultrasonic sensor
int calculateDistance(){ 
  
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH); // Reads the echoPin, returns the sound wave travel time in microseconds
  distance= duration*0.034/2;
  return distance;
}