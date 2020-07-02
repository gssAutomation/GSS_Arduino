//Projeto Piano

const int pino_buzzer = 10; // Pino ONDE O BUZZER ESTÁ CONECTADO

const int c = 261; // Dó
const int d = 293; // Ré
const int e = 329; // Mi
const int f = 349; // fá
const int g = 391; // Sol
const int a = 440; // Lá
const int b = 493; // Si

void setup() {
  pinMode(pino_buzzer, OUTPUT); // Configura o pino do Buzzer como saida 

}

void loop() {
  // Notas musicais tocadas por um segundo usando a frequencia do buzzer

  tone(pino_buzzer, c);
  delay(1000);

  tone(pino_buzzer, d);
  delay(1000);

  tone(pino_buzzer, e);
  delay(1000);

  tone(pino_buzzer, f);
  delay(1000);

  tone(pino_buzzer, g);
  delay(1000);

  tone(pino_buzzer, a);
  delay(1000);

  tone(pino_buzzer, b);
  delay(1000);

  noTone(pino_buzzer);
  delay(2000);
}
