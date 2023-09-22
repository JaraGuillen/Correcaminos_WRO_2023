/*                                          //pololu marca de ruedas de ACME
// justi lence huskylense camera dc robots(ACME)
/ sino pixi                                                                       
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
       %****%***%.     *#*              ,%/***(%#/.                    %#                      ./(     @****@****(      
         &*******(&#/*(#*&***(((******@%                                                                &***@&***       
                      .*%#*****##.                                                                       ((%  .&&.        
   
 */ 
  
 #include<Servo.h> 
 #include<NewPing.h> 
  
 Servo myservo; 
  
 int servoPin = 52; 
  
 int motor1Pin1 = 5;  
 int motor1Pin2 = 6;  
 int enable1Pin = 3;  
  
 int trigger = 8; 
 int echo1 = 10; 
 int echo2 = 11; 
 int echo3 = 12; 
  
 int rondas = 0;

 NewPing sonar1(trigger,echo1,300); //sonar(triggerpin, echopin, max_distance)
 NewPing sonar2(trigger,echo2,300); //sonar(triggerpin, echopin, max_distance)
 NewPing sonar3(trigger,echo3,300); //sonar(triggerpin, echopin, max_distance)
  
int dis1;
int dis2;
int dis3;

int pinboton = 30;
int started = 0;

int sentido = 0; // 0 = horario,    1 = antihorario

int dif, difant, error = 0;

 void setup() { 
  
  Serial.begin(115200); 
  
  myservo.attach(servoPin); 
  pinMode (servoPin, OUTPUT); 
     
  pinMode(motor1Pin1, OUTPUT); 
  pinMode(motor1Pin2, OUTPUT); 
  pinMode(enable1Pin, OUTPUT); 
  digitalWrite(motor1Pin1, LOW); 
  digitalWrite(motor1Pin2, LOW);  
  digitalWrite(enable1Pin, HIGH); 
  analogWrite(enable1Pin, 255); 
  
  pinMode(pinboton, INPUT);
 } 
  
  
  
  
 void seguidorPID(){
  dis1 = sonar1.ping_cm();
  dis3 = sonar3.ping_cm();

// Sistema PID, esperemos que funcione

 dif = dis1 - dis3;
 error = dif + (difant - dif);
 difant = dif;
 
int angulo = constrain(100 + error, 50, 150);
 myservo.write(angulo);
 
}



 
void giroR(){
  
   myservo.write(170);
  analogWrite(enable1Pin, 80); 
  digitalWrite(motor1Pin1, LOW); 
  digitalWrite(motor1Pin2, HIGH); 
  delay(2000);
  myservo.write(30); 
  digitalWrite(motor1Pin1, HIGH); 
  digitalWrite(motor1Pin2, LOW); 
  delay(2000);
  myservo.write(100); 
  digitalWrite(motor1Pin1, LOW); 
  digitalWrite(motor1Pin2, HIGH); 
  delay(1500);
  }





void giroL(){
   myservo.write(30);
  analogWrite(enable1Pin, 80); 
  digitalWrite(motor1Pin1, LOW); 
  digitalWrite(motor1Pin2, HIGH); 
  delay(2000);
  myservo.write(170); 
  digitalWrite(motor1Pin1, HIGH); 
  digitalWrite(motor1Pin2, LOW); 
  delay(2000);
  myservo.write(100); 
  digitalWrite(motor1Pin1, LOW); 
  digitalWrite(motor1Pin2, HIGH); 
  delay(1500);
  }





void loop() { 

if((digitalRead(pinboton) > 0) or (started > 1)){

 started = 9;

}
rondas = rondas + 1;
}
}