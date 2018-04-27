int trigPin = 11;
int echoPin = 12;
int led = 9;
float duration, cm, metres;


void setup() {
  // put your setup code here, to run once:
  Serial.begin (9600);
  //Define inputs and outputs
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(led, OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
 
  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
 
  // convert the time into a distance
  cm = (duration/2) / 29.3884268;
  metres = cm / 100;

  Serial.print(metres);
  Serial.print("m. / ");
  Serial.print(cm);
  Serial.print("cm.");
  Serial.println();
  
//  delay(100);
//  if(cm > 20){
//    digitalWrite(led, HIGH);
//  }
//  else{
//    digitalWrite(led, LOW);
//  }
  if(cm < 13){
    if(cm >10){
      digitalWrite(led, HIGH);
      delay(150);
      digitalWrite(led, LOW);
      delay(750);
    }
    else if(cm > 8){
      digitalWrite(led, HIGH);
      delay(100);
      digitalWrite(led, LOW);
      delay(300);
    }
    else if(cm > 1){
      digitalWrite(led, HIGH);
      delay(100);
      digitalWrite(led, LOW);
      delay(50);
    }
    else{
      digitalWrite(led, LOW);
      delay(100);
    }
  }
  else{
    delay(200);
  }
}
