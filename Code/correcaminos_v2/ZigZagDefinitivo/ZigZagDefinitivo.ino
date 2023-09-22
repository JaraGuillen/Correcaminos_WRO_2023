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
  
 NewPing sonar1(trigger,echo1,300); //sonar(triggerpin, echopin, max_distance)
 NewPing sonar2(trigger,echo2,300); //sonar(triggerpin, echopin, max_distance)
 NewPing sonar3(trigger,echo3,300); //sonar(triggerpin, echopin, max_distance)
  
int dis1;
int dis2;
int dis3;

int sentido = 2; // 0 = horario,    1 = antihorario

int dif, difant, error = 0;

int pinboton = 30;

int started = 0;

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
  
  
  
  
 void seguidorH(){
  dis3 = sonar3.ping_cm();
  dis2 = sonar2.ping_cm();

if(dis3 < 30){
  myservo.write(30);
}
if(dis3 > 30){
  myservo.write(170);
}
if(dis2 < 100){
 myservo.write(170);
 delay(2000);
}

}




 void seguidorAntiH(){
  dis1 = sonar1.ping_cm();

if(dis1 < 30){
  myservo.write(170);
}
if(dis1 > 30){
  myservo.write(30);
}
if(dis2 < 100){
 myservo.write(170);
 delay(2000);
}
}



 
 void loop() { 
  if((digitalRead(pinboton) > 0) or (started > 1)){

 started = 9;

  delay(35); // 29ms es lo mínimo que debe esperar 
  digitalWrite(motor1Pin1, LOW); 
  digitalWrite(motor1Pin2, HIGH);  
  analogWrite(enable1Pin, 100); 

  Serial.print(sonar1.ping_cm());
  Serial.print(sonar2.ping_cm());
  Serial.print(sonar3.ping_cm());
  dis1 = sonar1.ping_cm();
  dis2 = sonar2.ping_cm();
  dis3 = sonar3.ping_cm();

  if(dis2 < 50){
    if(dis1<dis3){sentido = 0;}
    else if(dis1>dis3){sentido = 1;}
  }
  if(sentido == 0){  //horario
    seguidorH();
  }
  if(sentido == 1){//Antiorario
    seguidorAntiH();
    
  }
 }
 }