# Correcaminos_WRO_2023
Este es el repositorio del equipo de Menorca que competirá el 16 y 17 de septiembre de 2023 en la WRO nacional de España.
## Blank Space >por determinar
Diseño coche autónomo para la competición Future Engineers 2023

Equipo: Correcaminos

Integrantes:

-Jara Guillén Ivaldi

-Nacho Carreras Peréz

-Marc Blanco Llera 

  ### Electronics
  El sistema de traccion esta controlado por una placa esp32 (D1 R32) que asemeja un ArduinoUno.
  la fuente de energia son dos pilas de litio 18-650 en serie.
  El motor esta controlado por un chip L298N.
  El sistema de giro esta controlado por un servo 9g.
  Para detectar las paredes usa 3 sensores ultrasonido localizados en la parte delantera; uno delante, el otro a la derecha y el ultimo     en la izquierda.
  ### Structure
   La estructura principal consiste en una base de metacrilato cortada para satisfacer las especificaciones. Hemos optado por este       
   material porque es rigido y fácil de moldear.
   Las ruedas delanteras van sin traccion para dirigir el coche atraves de un sistema de giro controlado por un servo.
   Las ruedas traseras estan unidas por un eje largo y conectadas a un motor DC de 6V.

  ###Estrategía
  El vehículo utiliza las paredes para guiarse y en cuanto detecta un giro establece la dirección del tablero.
 
