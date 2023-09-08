#### Correcaminos_WRO_2023
Este es el repositorio del equipo de Menorca que competirá los días 16 y 17 de septiembre de 2023 en la WRO (World Robot Olympiad) nacional de España, bajo el nombre de "Correcaminos." Este evento representa una emocionante oportunidad para poner a prueba sus habilidades y conocimientos en robótica y competir con otros equipos de todo el país. En este repositorio, se encuentra la documentación y la información relevante sobre el proyecto en el que han estado trabajando con entusiasmo y dedicación.

### Diseño de Coche Autónomo para la Competición Future Engineers 2023
El corazón de este proyecto es el diseño de un coche autónomo que competirá en la categoría Future Engineers 2023. Este desafío implica la creación de un vehículo capaz de navegar de manera autónoma, tomar decisiones basadas en sensores y cumplir con las tareas asignadas en un entorno controlado. El equipo de "Correcaminos" ha estado trabajando arduamente para lograr este objetivo.

Equipo: Correcaminos
Para tener éxito en una competición de esta envergadura, se necesita un equipo sólido y comprometido. El equipo "Correcaminos" está formado por tres talentosos integrantes:

Jara Guillén Ivaldi: Jara es una de las mentes creativas detrás del proyecto. Su pasión por la tecnología y la robótica la ha convertido en una pieza fundamental del equipo.

Nacho Carreras Peréz: Nacho aporta su experiencia en programación y electrónica al proyecto. Su destreza técnica es invaluable para lograr un diseño eficiente y funcional.

Marc Blanco Llera: Marc es el tercer miembro del equipo y aporta su experiencia en diseño mecánico y estructural. Su capacidad para crear una base sólida para el robot es esencial para el éxito del proyecto.

### Electrónica
Uno de los aspectos cruciales de cualquier proyecto de robótica es la electrónica que impulsa al robot. En el caso del coche autónomo de "Correcaminos," el sistema electrónico es esencial para el control y la toma de decisiones. Aquí hay una descripción detallada de los componentes electrónicos clave:

Sistema de Tracción: La tracción del vehículo está controlada por una placa ESP32 (D1 R32), que se asemeja a un Arduino Uno. Esta placa proporciona la capacidad de procesamiento necesaria para tomar decisiones en tiempo real y controlar la velocidad y la dirección del coche.

Fuente de Energía: Para alimentar el sistema, se utilizan dos pilas de litio 18650 conectadas en serie. Estas baterías proporcionan una fuente de energía confiable y duradera para el robot.

Motor: El motor que impulsa el coche está controlado por un chip L298N. Este chip permite controlar la velocidad y la dirección del motor de manera precisa, lo que es esencial para el movimiento autónomo.

Sistema de Giro: La capacidad de girar de manera efectiva es fundamental para la navegación autónoma. En este caso, el sistema de giro está controlado por un servo de 9g, que permite ajustar la dirección del vehículo con precisión.

Sensores Ultrasónicos: Para detectar obstáculos y paredes, el coche utiliza tres sensores ultrasónicos ubicados en la parte delantera: uno en el frente, otro a la derecha y el último a la izquierda. Estos sensores emiten ondas ultrasónicas y miden el tiempo que tardan en regresar, lo que permite al robot calcular la distancia a los objetos circundantes.

### Estructura
La estructura del coche autónomo es un componente crítico para su rendimiento. Debe ser robusta, ligera y diseñada para cumplir con las especificaciones de la competición. Aquí se detalla la estructura y las características principales:

Base de Metacrilato: La estructura principal del coche se construye utilizando una base de metacrilato que se ha cortado y moldeado para satisfacer las especificaciones. El equipo eligió este material por su rigidez y facilidad de moldeo. La robustez de esta base garantiza la estabilidad del vehículo durante la competición.

Ruedas Delanteras: Las ruedas delanteras del coche no tienen tracción. En lugar de ello, se utilizan para dirigir el vehículo a través de un sistema de giro controlado por el servo. Esta configuración permite giros precisos y ágiles.

Ruedas Traseras: Las ruedas traseras están unidas por un eje largo y están conectadas a un motor DC de 6V. Estas ruedas proporcionan la tracción necesaria para impulsar el coche hacia adelante y atrás.

### Estrategia
La estrategia de navegación es fundamental para el éxito del coche autónomo en la competición. Aquí se describe la estrategia que el equipo "Correcaminos" ha desarrollado:

El vehículo utiliza las paredes del entorno para guiarse. Cuando se acerca a una pared, los sensores ultrasónicos detectan su presencia y calculan la distancia. Si el robot detecta una pared a su derecha, gira hacia la izquierda, y viceversa. Esta estrategia le permite al coche seguir una ruta relativamente recta mientras evita obstáculos.

El sistema de giro controlado por el servo se utiliza para ajustar la dirección del vehículo cuando sea necesario. Esto le permite al coche navegar por el entorno de manera efectiva y sortear obstáculos de manera inteligente.



En resumen, el equipo "Correcaminos" ha creado un emocionante proyecto de coche autónomo que competirá en la WRO nacional de España en 2023. Este proyecto combina habilidades en electrónica, programación, diseño mecánico y estrategia de navegación para lograr un robot capaz de moverse de manera autónoma y sortear obstáculos. Con su base de metacrilato, sus ruedas controladas por servo y su motor.

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



