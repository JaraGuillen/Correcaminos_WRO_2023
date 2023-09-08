#### Correcaminos_WRO_2023
Este es el repositorio del equipo de Menorca que competirá los días 16 y 17 de septiembre de 2023 en la WRO (World Robot Olympiad) nacional de España, bajo el nombre de "Correcaminos." Este evento representa una emocionante oportunidad para poner a prueba nuestras habilidades y conocimientos en robótica y competir con otros equipos de todo el país. En este repositorio, se encuentra la documentación y la información relevante sobre el proyecto en el que han estado trabajando con entusiasmo y dedicación.

### Diseño de Coche Autónomo para la Competición Future Engineers 2023
El corazón de este proyecto es el diseño de un coche autónomo que competirá en la categoría Future Engineers 2023. Este desafío implica la creación de un vehículo capaz de navegar de manera autónoma y tomar decisiones basadas en sensores. El equipo de "Correcaminos" ha estado trabajando arduamente para lograr este objetivo.
https://raw.githubusercontent.com/JaraGuillen/Correcaminos_WRO_2023/master/Multimedia/Fotos/NachoJara.jpg
Equipo: Correcaminos
Para tener éxito en una competición de esta envergadura, se necesita un equipo sólido y comprometido. El equipo "Correcaminos" está formado por tres amigos:

·Jara Guillén Ivaldi

·Nacho Carreras Peréz

·Marc Blanco Llera


<span>![</span><span>Aquí la descripción de la imagen por si no carga</span><span>]</span><span>(</span><span>https://raw.githubusercontent.com/JaraGuillen/Correcaminos_WRO_2023/master/Multimedia/Fotos/NachoJara.jpg</span><span>)</span>

### Electrónica
Uno de los aspectos cruciales de cualquier proyecto de robótica es la electrónica que impulsa al robot. En el caso del coche autónomo de "Correcaminos," el sistema electrónico es esencial para el control y la toma de decisiones. Aquí hay una descripción detallada de los componentes electrónicos clave:

Sistema de control: El control del vehículo usa una placa ESP32 (D1 R32), que se asemeja a un Arduino Uno. Esta placa proporciona la capacidad de procesamiento necesaria para tomar decisiones en tiempo real y controlar la velocidad y la dirección del coche.

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
La estrategia de navegación es fundamental para el éxito del coche autónomo en la competición. Aquí se describe la estrategia que hemos desarrollado:

El vehículo utiliza las paredes del entorno para guiarse. Cuando se acerca a una pared, los sensores ultrasónicos detectan su presencia y calculan la distancia. Si el robot detecta una pared a su derecha, gira hacia la izquierda, y viceversa. Esta estrategia le permite al coche seguir una ruta relativamente recta mientras evita los límites.

El sistema de giro controlado por el servo se utiliza para ajustar la dirección del vehículo cuando sea necesario. Esto le permite al coche navegar por el entorno de manera efectiva e inteligente.



En resumen, hemos creado un emocionante proyecto de coche autónomo que competirá en la WRO nacional de España en 2023. Este proyecto combina habilidades en electrónica, programación, diseño mecánico y estrategia de navegación para lograr un robot capaz de moverse de manera autónoma y sortear obstáculos. Con su base de metacrilato, sus ruedas controladas por servo y su motor DC.

..................................................................English version:..................................................................

#### Correcaminos_WRO_2023
This is the repository of the Menorca team that will compete on September 16 and 17, 2023, in the national WRO (World Robot Olympiad) of Spain, under the name "Correcaminos." This event represents an exciting opportunity to test our skills and knowledge in robotics and compete with other teams from across the country. In this repository, you will find documentation and relevant information about the project we have been working on with enthusiasm and dedication.

### Autonomous Car Design for the Future Engineers 2023 Competition
The core of this project is the design of an autonomous car that will compete in the Future Engineers 2023 category. This challenge involves creating a vehicle capable of autonomously navigating and making decisions based on sensors. The "Correcaminos" team has been working diligently to achieve this goal.

Team: Correcaminos

To succeed in a competition of this magnitude, a solid and committed team is required. The "Correcaminos" team consists of three friends:

·Jara Guillén Ivaldi

·Nacho Carreras Peréz

·Marc Blanco Llera

### Electronics
One of the crucial aspects of any robotics project is the electronics that drive the robot. In the case of the "Correcaminos" autonomous car, the electronic system is essential for control and decision-making. Here is a detailed description of the key electronic components:

Control System: The vehicle's control system uses an ESP32 board (D1 R32), which is similar to an Arduino Uno. This board provides the necessary processing power to make real-time decisions and control the speed and direction of the car.

Power Source: To power the system, two series-connected lithium 18650 batteries are used. These batteries provide a reliable and long-lasting power source for the robot.

Motor: The motor that drives the car is controlled by an L298N chip. This chip allows precise control of motor speed and direction, which is essential for autonomous movement.

Steering System: Effective steering is crucial for autonomous navigation. In this case, the steering system is controlled by a 9g servo, allowing precise adjustment of the vehicle's direction.

Ultrasonic Sensors: To detect obstacles and walls, the car uses three ultrasonic sensors located at the front: one in the front, another on the right, and the last one on the left. These sensors emit ultrasonic waves and measure the time it takes for them to return, allowing the robot to calculate the distance to surrounding objects.

### Structure
The structure of the autonomous car is a critical component for its performance. It must be robust, lightweight, and designed to meet competition specifications. Here are the details of the structure and its main features:

Acrylic Base: The main structure of the car is built using an acrylic base that has been cut and molded to meet specifications. The team chose this material for its rigidity and ease of molding. The robustness of this base ensures the stability of the vehicle during the competition.

Front Wheels: The front wheels of the car lack traction. Instead, they are used to steer the vehicle through a servo-controlled turning system. This configuration allows for precise and agile turns.

Rear Wheels: The rear wheels are connected by a long axle and are attached to a 6V DC motor. These wheels provide the necessary traction to propel the car forward and backward.

### Strategy
Navigation strategy is crucial for the success of the autonomous car in the competition. Here is the strategy we have developed:

The vehicle uses the walls of the environment to guide itself. When it approaches a wall, the ultrasonic sensors detect its presence and calculate the distance. If the robot detects a wall to its right, it turns to the left, and vice versa. This strategy allows the car to follow a relatively straight path while avoiding boundaries.

The servo-controlled turning system is used to adjust the vehicle's direction when necessary. This allows the car to navigate the environment effectively and intelligently.

In summary, we have created an exciting project of an autonomous car that will compete in the national WRO of Spain in 2023. This project combines skills in electronics, programming, mechanical design, and navigation strategy to achieve a robot capable of autonomous movement and obstacle avoidance. With its acrylic base, servo-controlled wheels, and 6V DC motor, the "Correcaminos" autonomous car is ready to take on the competition.



