//Programmer: Lauren Dunning
//Date: 3.16.2023
//Program: Blind Spot Monitor
//Resource: https://bit.ly/3JKZOli

/*
 * This program will determine distances approaching
 * vehicle that are in your blind spot and turn on a warning light
 */
 
int trigPin = 7;
int echoPin = 6;
int LEDlampRed = 9;
int LEDlampYellow = 10;
int LEDlampGreen = 11;
int soundbuzzer = 3;
int sound  = 500;


void setup() {
  Serial.begin (9600);
  pinMode(trigPin,  OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(LEDlampRed, OUTPUT);
  pinMode(LEDlampYellow,  OUTPUT);
  pinMode(LEDlampGreen, OUTPUT);
  pinMode(soundbuzzer, OUTPUT);
}
void  loop() {
  long durationindigit, distanceinft;
  digitalWrite(trigPin, LOW);  
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  durationindigit = pulseIn(echoPin, HIGH);
  distanceinft = (durationindigit/5) / 29.1;
 
  if (distanceinft > 10){
    Serial.println("No detected car in your blind spot - change lanes when needed.");
  }

  if (distanceinft <= 10 && distanceinft >=7) {
    digitalWrite(LEDlampGreen, HIGH);
    Serial.println("There is another car within");
    Serial.print(distanceinft);
    Serial.println(" feet from your blind spot \nGetting Close - change lanes with caution\n");
    
  }
  else {
    digitalWrite(LEDlampGreen, LOW);
  }

  delay(1000);
}
