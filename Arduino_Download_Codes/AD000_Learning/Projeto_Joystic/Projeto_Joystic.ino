// Projeto joystic

const int VRX = A4;
const int VRY = A5;
const int SW = 2;
const int ledV = 9;
const int ledA = 8;

int leitura_botao =0, leitura_VRX, leitura_VRY;

void setup() {
  Serial.begin(9600);
  pinMode(VRX, INPUT);
  pinMode(VRY, INPUT);
  pinMode(SW, INPUT_PULLUP);
  pinMode(ledV, OUTPUT);
  pinMode(ledA, OUTPUT);
}

void loop() {
  leitura_VRX = analogRead(VRX);
  leitura_VRY = analogRead(VRY);
  leitura_botao = digitalRead(SW);

  if (leitura_VRX >=100){
    digitalWrite(ledV, HIGH);
  }
  else {
    digitalWrite(ledV, LOW);
  }

  if (leitura_VRY >=500){
    digitalWrite(ledA, HIGH);
  }
  else{
    digitalWrite(ledA, LOW);
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
