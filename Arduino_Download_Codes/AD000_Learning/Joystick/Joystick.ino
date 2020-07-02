#include<Servo.h>

Servo servo_motor;

const int VRX = A1;
const int VRY = A2;
const int SW = 2;

int leitura_botao = 0, leitura_VRX, leitura_VRY;
void setup() {
  Serial.begin(9600);
  pinMode(VRX, INPUT);
  pinMode(VRY, INPUT);
  pinMode(SW, INPUT_PULLUP);
  servo_motor.attach(9);
}

void loop() {
  leitura_VRX = analogRead(VRX);
  leitura_VRY = analogRead(VRY);
  leitura_botao = digitalRead(SW);

  if (leitura_VRX == 500){
    servo_motor.write(70);
  }
  else {
    servo_motor.write(120);
  }


  Serial.print("Leitura em VRX: ");
  Serial.print("\t");
  Serial.print(leitura_VRX);
  Serial.print("\t");
  Serial.print("Leitura em VRY: ");
  Serial.print("\t");
  Serial.print(leitura_VRY);
  Serial.print("\t");
  Serial.print("Leitura do botao: ");
  Serial.println(leitura_botao);

  delay(10);

  
}
