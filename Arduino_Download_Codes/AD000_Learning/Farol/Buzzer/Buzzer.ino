//PROJETO PIANO

int frequencia = 2000;

void setup() {
  pinMode(10,OUTPUT);
}

void loop() {
  tone(10, frequencia); // Gera frequencia de 2000hz no buzzer
  delay(1000);
  noTone(10); // Para a frequencia no buzzer
  delay(1000);

  noTone(10);

}
