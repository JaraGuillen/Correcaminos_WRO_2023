

int ch1; // Here's where we'll keep our channel values
int poten;

void setup() {

  pinMode(A5, INPUT); // Set our input pins as such

  Serial.begin(9600); // Pour a bowl of Serial

}

void loop() {

  ch1 = pulseIn(A5, HIGH); // Read the pulse width of 
  poten = -(ch1/100)+13;


  Serial.println(poten);  
  delay(50);
  } // I put this here just to make the terminal 
              // window happier