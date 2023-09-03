
#include <ESP32_Servo.h>


Servo myservo;


int servoPin = 17;

int motor1Pin1 = 27; 
int motor1Pin2 = 26; 
int enable1Pin = 14; 
const int freq = 30000;
const int servoChannel = 0;
const int motorChannel = 0;
const int resolution = 8;
int dutyCycle = 255;




 
void setup() {
  xTaskCreate(miTarea2, "mi_tarea", 10000, NULL, 1, NULL);

  myservo.attach(servoPin,500,2400);

  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(enable1Pin, OUTPUT);
  
  // configure LED PWM functionalitites
  //ledcSetup(motorChannel, freq, resolution);

  
  // attach the channel to the GPIO to be controlled
  ledcAttachPin(enable1Pin, motorChannel);
 
  Serial.begin(115200);
}








void loop() {
 ledcWrite(motorChannel, dutyCycle);  
 digitalWrite(motor1Pin1, LOW);
 digitalWrite(motor1Pin2, HIGH); 

 delay(2000);

  
 digitalWrite(motor1Pin1, LOW);
 digitalWrite(motor1Pin2, LOW); 

 delay(1500);
}






 void miTarea2 (void *pvParameters){
  for(;;){
myservo.write(80);
 delay(2000);
 myservo.write(135);
 
 delay(1500);
}}