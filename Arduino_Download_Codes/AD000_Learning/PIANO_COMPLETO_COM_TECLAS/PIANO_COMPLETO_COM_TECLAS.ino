// Projeto PIANO - TOCANDO TECLAS DO PIANO

//Configurações das variaveis de armazenamento de cada componente
const int pino_botao1 = 7;
const int pino_botao2 = 8;
const int pino_botao3 = 9;
const int pino_buzzer = 10; // Pino ONDE O BUZZER ESTÁ CONECTADO
const int pino_led1 = 11; 
const int pino_led2 = 12;
const int pino_led3 = 13;

// FREQUENCIA DE CADA NOTA
const int c = 261; // Dó
const int d = 293; // Ré
const int e = 329; // Mi
const int f = 349; // fá
const int g = 391; // Sol
const int a = 440; // Lá
const int b = 493; // Si

void setup() {
  pinMode(pino_botao1, INPUT_PULLUP); //CONFIGURAÇÃO DO BOTÃO 01
  pinMode(pino_botao2, INPUT_PULLUP); //CONFIGURAÇÃO DO BOTÃO 02
  pinMode(pino_botao3, INPUT_PULLUP); //CONFIGURAÇÃO DO BOTÃO 03
  pinMode(pino_buzzer, OUTPUT); //CONFIGURAÇÃO DO BUZZER 
  pinMode(pino_led1, OUTPUT);
  pinMode(pino_led2, OUTPUT);
  pinMode(pino_led3, OUTPUT);
}

void loop() {
  // SALVA O ESTADO DE CADA BOTAO
  bool estado_botao1 = digitalRead(pino_botao1);
  bool estado_botao2 = digitalRead(pino_botao2);
  bool estado_botao3 = digitalRead(pino_botao3);

  if (estado_botao1 == LOW) {
    tone(pino_buzzer, c); // Dó
    digitalWrite(pino_led1, HIGH);
    digitalWrite(pino_led2, LOW);
    digitalWrite(pino_led3, LOW);
  }
  else if (estado_botao2 == LOW) {
    tone(pino_buzzer, d); // Ré
    digitalWrite(pino_led1, LOW);
    digitalWrite(pino_led2, HIGH);
    digitalWrite(pino_led3, LOW);
  }
  else if (estado_botao3 == LOW) {
    tone(pino_buzzer, e); // MI
    digitalWrite(pino_led1, LOW);
    digitalWrite(pino_led2, LOW);
    digitalWrite(pino_led3, HIGH);
  }
  else {
    noTone(pino_buzzer); // Desliga Buzzer
    digitalWrite(pino_led1, LOW);
    digitalWrite(pino_led2, LOW);
    digitalWrite(pino_led3, LOW);
  }

}
