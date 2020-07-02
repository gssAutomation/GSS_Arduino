//para usar digitando o ângulo


#include <Servo.h>

#define pinServo 9

Servo servo1;
int grau = 0;

void setup() {
  servo1.attach(pinServo);
  Serial.begin(9600);
}

void loop() {

if (Serial.available() > 0) {
   
  grau = Serial.parseInt();
     
  }

 servo1.write(grau);
 Serial.print("angulo:");
 Serial.println(grau);
 delay(1000); 
}
