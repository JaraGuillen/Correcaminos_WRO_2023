#include<Servo.h>

Servo myservo;

int servoPin = 52;

int motor1Pin1 = 5; 
int motor1Pin2 = 6; 
int enable1Pin = 3; 

int trigger = 8;
int echo1 = 10;
int echo2 = 11;
int echo3 = 12;

const float sonido = 34300.0; // Velocidad del sonido en cm/s

 
void setup() {

  Serial.begin(9600);

  myservo.attach(servoPin);

  pinMode (servoPin, OUTPUT);

  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(enable1Pin, OUTPUT);
  
  pinMode(echo1, INPUT);
  pinMode(echo2, INPUT);
  pinMode(echo3, INPUT);
  pinMode(trigger, OUTPUT);
 



 digitalWrite(motor1Pin1, LOW);
 digitalWrite(motor1Pin2, LOW); 
 digitalWrite(enable1Pin, HIGH);

 analogWrite(enable1Pin, 255);
  
  
}




void iniciarTrigger(){

  digitalWrite(trigger, LOW);
  delayMicroseconds(2);

  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigger, LOW);
}





float cd1(){
  // pulseIn obtiene el tiempo que tarda en cambiar entre estados, en este caso a HIGH
  unsigned long tiempo = pulseIn(echo1, HIGH);
 
  // Obtenemos la distancia en cm, hay que convertir el tiempo en segudos ya que está en microsegundos por eso se multiplica por 0.000001
  float distancia = tiempo * 0.000001 * sonido / 2.0;
  Serial.print("  Izquierda:  ");
  Serial.print(distancia);
  delay(30);
 
  return distancia;
}




float cd2(){
  unsigned long tiempo = pulseIn(echo2, HIGH);
 
  float distancia = tiempo * 0.000001 * sonido / 2.0;
  Serial.print("  Centro:  ");
  Serial.print(distancia);
  delay(30);
 
  return distancia;
}




float cd3(){
  unsigned long tiempo = pulseIn(echo3, HIGH);
 
  float distancia = tiempo * 0.000001 * sonido / 2.0;
  Serial.print("  Derecha:  ");
  Serial.print(distancia);
 // Serial.println();
  delay(30);
 
  return distancia;
}




void loop() {
/*
 digitalWrite(motor1Pin1, LOW);
 digitalWrite(motor1Pin2, HIGH); 
 myservo.write(50);
 delay(2000);

myservo.write(150); 
digitalWrite(motor1Pin1, LOW);
digitalWrite(motor1Pin2, LOW); 

 delay(1500);
*/

  iniciarTrigger();
  int dis1 = cd1();
  
  iniciarTrigger();
  int dis2 = cd2();
  
  iniciarTrigger();
  int dis3 = cd3();

  int mig = dis1 - dis3;
  Serial.print("  Mig:  ");
  Serial.println(mig);


  myservo.write(100 - mig);
}
 
