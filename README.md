### Correcaminos_WRO_2023
Este es el repositorio del equipo de Menorca que competirá los días 16 y 17 de septiembre de 2023 en la WRO nacional de España.


Diseño de coche autónomo para la competición Future Engineers 2023.

Equipo: Correcaminos

Integrantes:

Jara Guillén Ivaldi,
Nacho Carreras Peréz,
Marc Blanco Llera.
### Electrónica
El sistema de tracción está controlado por una placa ESP32 (D1 R32), que se asemeja a un Arduino Uno.
La fuente de energía consta de dos baterías de litio 18650 conectadas en serie.
El motor está controlado por un chip L298N.
El sistema de dirección está controlado por un servo 9g.
Para detectar paredes, utiliza 3 sensores ultrasónicos ubicados en la parte delantera: uno en el frente, otro a la derecha y el último en la izquierda.

### Estructura
La estructura principal consiste en una base de acrílico cortada diseñada para cumplir con las especificaciones. Hemos elegido este material porque es rígido y fácil de modelar.
Las ruedas delanteras carecen de tracción y se utilizan para dirigir el coche a través de un sistema de giro controlado por un servo.
Las ruedas traseras están conectadas por un eje largo y están unidas a un motor DC de 6V.

### Estrategia
El vehículo utiliza las paredes para navegar y, tan pronto como detecta un giro, establece la dirección del tablero.



English version:

### Correcaminos_WRO_2023
This is the repository of the Menorca team that will compete on September 16 and 17, 2023, in the national WRO (World Robot Olympiad) of Spain.


Autonomous Car Design for the Future Engineers 2023 competition.

Team: Correcaminos

Members:

Jara Guillén Ivaldi,
Nacho Carreras Peréz,
Marc Blanco Llera.
### Electronics
The traction system is controlled by an ESP32 board (D1 R32), which resembles an Arduino Uno.
The power source consists of two series-connected lithium 18650 batteries.
The motor is controlled by an L298N chip.
The steering system is controlled by a 9g servo.
To detect walls, it uses 3 ultrasonic sensors located at the front: one in the front, another on the right, and the last one on the left.

### Structure
The main structure consists of a cut acrylic base designed to meet the specifications. We have chosen this material because it is rigid and easy to shape.
The front wheels lack traction and are used to steer the car through a servo-controlled turning system.
The rear wheels are connected by a long axle and attached to a 6V DC motor.

### Strategy
The vehicle uses walls to navigate, and as soon as it detects a turn, it establishes the direction of the board.



