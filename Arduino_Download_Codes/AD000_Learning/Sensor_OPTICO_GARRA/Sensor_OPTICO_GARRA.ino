// PEOJETO ENSOR DE RÉ

#include<Servo.h>

Servo servo_motor;

const int TRIG = 13, ECHO = 12, buzzer = 7;
unsigned int intervalo, distancia;

void setup() {
  Serial.begin(9600);
  pinMode(TRIG,OUTPUT);
  pinMode(ECHO,INPUT);
  servo_motor.attach(9);  // Informa qual pino será usado para o servo declarado anteriormente.
  servo_motor.write(70); //Informa ao servo que deverá se posicionar a 10 graus
}

void loop() {
  distancia = sensor_morcego(TRIG,ECHO); // Chamada da função de leitura.
  Serial.println(distancia);
  if (distancia <= 3) { // Condicional para leituras inferiores a 10cm.
    servo_motor.write(120);
  }
  else if (distancia > 30) { // Condicional para leituras superiores a 60cm.
      servo_motor.write(70);
  } 
}

int sensor_morcego(int pinotrig,int pinoecho){ // Função para leitura do sensor
  digitalWrite(pinotrig,LOW);
  delayMicroseconds(2);
  digitalWrite(pinotrig,HIGH);
  delayMicroseconds(10);
  digitalWrite(pinotrig,LOW);

  return pulseIn(pinoecho,HIGH)/59;
}
