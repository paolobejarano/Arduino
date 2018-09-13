//Indicar en qué pines está el trig y el echo
int trigPin = 11;
int echoPin = 12;
float duracion, cm, metros;


void setup() {
  Serial.begin (9600);
  //Define inputs and outputs
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);  
}

void loop() {
  // Lectura de sensores
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  pinMode(echoPin, INPUT);
  duracion = pulseIn(echoPin, HIGH);
 
  // conversion de tiempo a distancia
  cm = (duracion/2) / 29.3884268;
  metros = cm / 100;

  // Muestra la distancia en el terminal
  Serial.print(metros);
  Serial.print("m. / ");
  Serial.print(cm);
  Serial.print("cm.");
  Serial.println();
}
