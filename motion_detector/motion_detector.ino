#define trigPin 11
#define echoPin 12
#define detection 8
 
void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
  pinMode(detection, OUTPUT);
}
 
void loop() {
  long time_microsec;
  long distance_cm;
  
  /* Sending out a pulse */
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
 
  time_microsec = pulseIn(echoPin, HIGH);
  distance_cm = time_microsec * 0.034 / 2; /* 34000 cm / s = 34000cm / 100000 microseconds = 0.34cm / microsecond */

  /*Checking for obstacles within the distance sensor path*/
  if(distance_cm < 200){
      digitalWrite(detection, HIGH);
  }
  else{
      digitalWrite(detection, LOW);
  }
  delay(200);
}
