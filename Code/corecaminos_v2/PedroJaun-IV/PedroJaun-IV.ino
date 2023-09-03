
#include <AFMotor.h>
#include <Servo.h>

int motorspeed=500;


Servo servoMotor;

AF_DCMotor motor(1);
int nmotor = 1;

void setup() {

  Serial.begin(9600);
  servoMotor.attach(10);

  pinMode(A5, INPUT);

  motor.setSpeed(255);  // speed: 0 to 255
  motor.run(RELEASE);

  

}

void loop() {

  motor.setSpeed(255);  // speed: 0 to 255
  motor.run(FORWARD);
    for (int i = 80; i <= 160; i++)
  {
    // Desplazamos al ángulo correspondiente
    servoMotor.write(i);
    Serial.print(i);
    Serial.println();
    // Hacemos una pausa de 25ms
    delay(25);
  }
 
  // Para el sentido negativo
  for (int i = 159; i > 80; i--)
  {
    // Desplazamos al ángulo correspondiente
    servoMotor.write(i);
    Serial.print(i);
    Serial.println();
    // Hacemos una pausa de 25ms
    delay(25);
  }
}

