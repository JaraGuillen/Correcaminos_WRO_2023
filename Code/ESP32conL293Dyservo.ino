




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
/* ledcWrite(motorChannel, dutyCycle);  
 analogWrite(motor1Pin1, 0);
 analogWrite(motor1Pin2, 255); 

servoact(1000);
 delay(2000);
servoact(2000);
  
 analogWrite(motor1Pin1, 0);
 analogWrite(motor1Pin2, 0); 

 delay(1500);
*/
for(int i=40; i< 155; i++){
  servoact(i);
  delay(100);
}
for(int i=155; i> 40; i--){
  servoact(i);
  delay(100);
}
 
}






 void miTarea2 (void *pvParameters){
  for(;;){
 delay(1000);
}}