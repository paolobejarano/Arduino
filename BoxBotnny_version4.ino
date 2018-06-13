//Sensore Infrarrojo:
int sensorizquierdo = 12;
int sensorderecho = 13;

//Motores de las llantas izquierda y derecha:
int LM1 = 2;
int LM2 = 3;
int RM1 = 5;
int RM2 = 4;

//LED RGB
int pinrojo = 2;
int pinverde = 3;
int pinazul = 4;
int rojoValor, verdeValor, azulValor;

//Motor de la Plataforma:
int plataforma1 = 6;
int plataforma2 = 7;

//Sensor de proximidad:
int trigPin = 8;
int echoPin = 9;
int duracion = 0;
int cm;

//Modulo bluetooth:
//#include <SoftwareSerial.h>
//SoftwareSerial BT(10,11);

int led1 = 16;
int led2 = 17;

void mover_hacia_adelante(){
  digitalWrite(LM1, HIGH);
  digitalWrite(LM2, LOW);
  digitalWrite(RM1, HIGH);
  digitalWrite(RM2, LOW);
}

void mover_hacia_la_izquierda(){
  digitalWrite(LM1, LOW);
  digitalWrite(LM2, LOW);
  digitalWrite(RM1, HIGH);
  digitalWrite(RM2, LOW);
}

void detener(){
  digitalWrite(LM1, LOW);
  digitalWrite(LM2, LOW);
  digitalWrite(RM1, LOW);
  digitalWrite(RM2, LOW);
}

void mover_hacia_la_derecha(){
  digitalWrite(LM1, HIGH);
  digitalWrite(LM2, LOW);
  digitalWrite(RM1, LOW);
  digitalWrite(RM2, LOW);
}

void subir_plataforma(){
  digitalWrite(plataforma1, HIGH);
  digitalWrite(plataforma2, LOW);
}

void bajar_plataforma(){
  digitalWrite(plataforma1, LOW);
  digitalWrite(plataforma2, HIGH);
}

void detener_plataforma(){
  digitalWrite(plataforma1, LOW);
  digitalWrite(plataforma2, LOW);
}

void recojer_mueble(){
  subir_plataforma();
  delay(1000);
  detener_plataforma();
}

void dejar_mueble(){
  bajar_plataforma();
  delay(1000);
  detener_plataforma();
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(sensorizquierdo, INPUT);
  pinMode(sensorderecho, INPUT);
  digitalWrite(pinrojo, HIGH);
  digitalWrite(pinverde, HIGH);
  digitalWrite(pinazul, HIGH);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(LM1, OUTPUT);
  pinMode(LM2, OUTPUT);
  pinMode(RM1, OUTPUT);
  pinMode(RM2, OUTPUT);
  pinMode(plataforma1, OUTPUT);
  pinMode(plataforma2, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  if (Serial.available()>0) 
   {
      char option = Serial.read();
      if (option == '1')
      {
        //Lectura de los sensores infrarrojo:
        int valor_derecha = digitalRead(sensorderecho);
        int valor_izquierda = digitalRead(sensorizquierdo);
        
        //Lectura del sensor de proximidad:
        digitalWrite(trigPin, LOW);
        delayMicroseconds(2);
        digitalWrite(trigPin, HIGH);
        delayMicroseconds(10);
        digitalWrite(trigPin, LOW);
        pinMode(echoPin, INPUT);
        duracion = pulseIn(echoPin, HIGH);

        // Conversión de tiempo a 
        cm = (duracion/2) / 29.3884268;
        Serial.print(cm);
        Serial.print("cm.");
        //Valores de los sensores infrarrojo:
        Serial.print("Sensor Derecho: ");
  Serial.println(valor_derecha);
  Serial.print("Sensor Izquierdo: ");
  Serial.println(valor_izquierda);

  //Movimiento del robot según el valor de los sensores
  if(valor_izquierda == HIGH && valor_derecha == HIGH){
    mover_hacia_adelante();
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
  }
  else if(valor_izquierda == HIGH && valor_derecha == LOW){
    mover_hacia_la_izquierda();
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
  }
  else if(valor_izquierda == LOW && valor_derecha == HIGH){
    mover_hacia_la_derecha();
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
  }
  else{
    detener();
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
  }

  if(cm < 15){
    detener();
    recojer_mueble();
  }
      }
      else if(option == '1'){
        //Lectura de los sensores infrarrojo:
  int valor_derecha = digitalRead(sensorderecho);
  int valor_izquierda = digitalRead(sensorizquierdo);

  //Lectura del sensor de proximidad:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  pinMode(echoPin, INPUT);
  duracion = pulseIn(echoPin, HIGH);

  // Conversión de tiempo a 
  cm = (duracion/2) / 29.3884268;
  Serial.print(cm);
  Serial.print("cm.");

  //Valores de los sensores infrarrojo:
  Serial.print("Sensor Derecho: ");
  Serial.println(valor_derecha);
  Serial.print("Sensor Izquierdo: ");
  Serial.println(valor_izquierda);

  //Movimiento del robot según el valor de los sensores
  if(valor_izquierda == HIGH && valor_derecha == HIGH){
    mover_hacia_adelante();
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
  }
  else if(valor_izquierda == HIGH && valor_derecha == LOW){
    mover_hacia_la_izquierda();
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
  }
  else if(valor_izquierda == LOW && valor_derecha == HIGH){
    mover_hacia_la_derecha();
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
  }
  else{
    detener();
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
  }

  if(cm < 15){
    dejar_mueble();
    detener();
  }
      }
   }
}
