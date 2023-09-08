




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
  
  pinMode (servoPin, OUTPUT);


  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(enable1Pin, OUTPUT);
  
  // configure LED PWM functionalitites
  ledcSetup(motorChannel, freq, resolution);

  
  // attach the channel to the GPIO to be controlled
  ledcAttachPin(enable1Pin, motorChannel);
 
  Serial.begin(115200);

 digitalWrite(motor1Pin1, LOW);
 digitalWrite(motor1Pin2, LOW); 
  
}




void servoact(int grado){

int A=0;
int B=180;
int C=700;
int D=2400;

int microseg = ((grado - A)*(D - C))/(B - A) + C; 
Serial.print(grado);
Serial.print(" : ");
Serial.println(microseg);
      
digitalWrite (servoPin,HIGH); 
delayMicroseconds(microseg);               
digitalWrite (servoPin,LOW);
 
 

}







void loop() {
 ledcWrite(motorChannel, dutyCycle);  
 digitalWrite(motor1Pin1, LOW);
 digitalWrite(motor1Pin2, HIGH); 

servoact(40);
 delay(2000);
servoact(160);
  
 digitalWrite(motor1Pin1, LOW);
 digitalWrite(motor1Pin2, LOW); 

 delay(1500);

}
 







 void miTarea2 (void *pvParameters){
  for(;;){
 delay(10000);
}}
