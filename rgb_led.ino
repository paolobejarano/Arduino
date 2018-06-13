// Define Pins
int pinrojo = 2;
int pinverde = 3;
int pinazul = 4;
int rojoValor, verdeValor, azulValor;

#define delayTime 50 // fading time between colors


void setup()
{
  pinMode(pinrojo, OUTPUT);
  pinMode(pinverde, OUTPUT);
  pinMode(pinazul, OUTPUT);
  digitalWrite(pinrojo, HIGH);
  digitalWrite(pinverde, HIGH);
  digitalWrite(pinazul, HIGH);
}

// main loop
void loop(){
  analogWrite(pinazul, 0);
}
