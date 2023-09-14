/*                                                                                                                 
                                                 .@%(((((#&@@((&                                                        
                                                /@&((((((((((((((@                                                      
                                            %#((((((((((((((((((((&(((,                                                 
                                           %((((#%@@@%##(((((((((((@((#                                                 
                                                     ,(@&#((((((((((((%                                                 
                                                         /%(((((((((((                                                  
                                                            %(((((((#                                                   
                #,,,,#@(                                     @((((                                                      
                 ,(%&@&/,,,,&(  %#.                      ##(/&(#.                                                       
           ,#,,,,,,,,,,,,,,,,,,,@@,,@                  * #&  (##                                                        
         º/,,,,,,,,,,,,,,,,,,,,,,,,,,,&          &,@(@ .    #((                                                         
        /,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,@         *@,,.. @#((((&                                                         
        #,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,@          ,,,,,,@./*,./                                                        
       @,,,,,,,,,,,,,/,,,,,,,,,,,,,,,,,,#          ./@(,,,,,,,,*                                                        
       #,,,,,&,,#/      %@,,,,,,,,,,,,,,*         *(/%,%,,,&                                                            
       ,,,,,/,@          %,,,,,,,,,,,,,,#                 %,,@                                                          
      #,,,,(/              ./,,,,,,,,,,,@                   %,,#                                                        
      &,,,(                  /,,,,,,,,,,@                      /,#                                                      
      #,,@                     /,,,,,,,,@                        #*(                                                    
       (@                    @,%,,,,,,,,@                          //                                                   
                             @,,@,,,,,,,@                           @,&                                                 
                              (,,@,,,,,,/                            @,,.                                               
                               &,,(,,,,,,*                           /,,,%                                              
                                @,,,,,,,,#                            ,,,/                                              
                                  @,,,,,,,/                    *@/,,,,,,,,,                   ,&*****,                  
                                  %,&,,,,,,,@             .@(((@,,,,,,,,,,/                @****(******@                
                                    ##,,,,,,,,,###((&#(((&(((((@,,,,,,,,,*@           ,%**%/@#**(    &**#*%             
                                          *&@%/(,,,,%((@(((((((@,,,,,,,,@@       /@**@    &****&       *******(/        
                                         *%#(,    &%*@//&(((((@,,,,,,/&/%  (#***#,         &****%       /****@**º/      
     .,..@(#@   @&*********,                  ,(***@,,,,,,,,%(    .@&,,@***º/,               (***&      @****(****(     
      %*****%***%.     *#**              ,%/***(%#/.                    %#                      ./(     @****@****(     
        &********(&#/*(#*&***(((******@%                                                                &***@&****      
                     .*%#*****##.                                                                       ((%  .&&.       
 
*/

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

/*
⣿⣿⣿⣿⣿⣿⣿⣿⠟⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀⠉⠻⣿⣿⣿⣿⣿⣿⡇
⣿⣿⣿⣿⣿⣿⣿⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢺⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠆⠜⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⠿⠿⠛⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠻⣿⣿
⣿⣿⡏⠁⠀⠀⠀⠀⠀⣀⣠⣤⣤⣶⣶⣶⣶⣶⣦⣤⡄⠀⠀⠀⠀⢀⣴⣿
⣿⣿⣷⣄⠀⠀⠀⢠⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢿⡧⠇⢀⣤⣶⣿⣿
⣿⣿⣿⣿⣿⣿⣾⣮⣭⣿⡻⣽⣒⠀⣤⣜⣭⠐⢐⣒⠢⢰⢸⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣏⣿⣿⣿⣿⣿⣿⡟⣾⣿⠂⢈⢿⣷⣞⣸⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣽⣿⣿⣷⣶⣾⡿⠿⣿⠗⠈⢻⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠻⠋⠉⠑⠀⠀⢘⢻⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⡿⠟⢹⣿⣿⡇⢀⣶⣶⠴⠶⠀⠀⢽⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⡿⠀⠀⢸⣿⣿⠀⠀⠣⠀⠀⠀⠀⠀⡟⢿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⡿⠟⠋⠀⠀⠀⠀⠹⣿⣧⣀⠀⠀⠀⠀⡀⣴⠁⢘⡙⢿⣿⣿⣿⣿
⠉⠉⠁⠀⠀⠀⠀⠀⠀⠀⠀⠈⠙⢿⠗⠂⠄⠀⣴⡟⠀⠀⡃⠀⠉⠉⠟⡿⡇
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢷⠾⠛⠂⢹⠀⠀⠀⢡⠀⠀⠀⠀⠀⠙⡇
 */

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
  if(distancia>300){distancia = 299;}
  Serial.print(distancia);
  delay(100);
 
  return distancia;
}




float cd2(){
  unsigned long tiempo = pulseIn(echo2, HIGH);
 
  float distancia = tiempo * 0.000001 * sonido / 2.0;
  Serial.print("  Centro:  ");
  if(distancia>300){distancia = 299;}
  Serial.print(distancia);
  delay(100);
 
  return distancia;
}




float cd3(){
  unsigned long tiempo = pulseIn(echo3, HIGH);
 
  float distancia = tiempo * 0.000001 * sonido / 2.0;
  Serial.print("  Derecha:  ");
  if(distancia>300){distancia = 299;}
  Serial.print(distancia);
  delay(100);
 
  return distancia;
}




void loop() {
  
  iniciarTrigger();
  float dis1 = cd1();
  
  iniciarTrigger();
  float dis2 = cd2();
  
  iniciarTrigger();
  float dis3 = cd3();

  float mig = dis1 - dis3;

  Serial.print("  Mig:  ");
  Serial.print(mig);

  if(mig>60){mig=55;}
  if(mig<-60){mig=155;}
  myservo.write(100 - mig);

  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, HIGH); 

  int A=0;
  int B=100;
  int C=10;
  int D=120;

  int motorspeed = ((dis2 - A)*(D - C))/(B - A) + C;

  if(motorspeed>254){motorspeed=255;}

  Serial.print("  MSpeed:  ");
  Serial.println(motorspeed);

  analogWrite(enable1Pin, motorspeed);
}
 
