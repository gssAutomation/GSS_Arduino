// LAZER COM OBSTACULO E BUZZER DE ACIONAMENTO

// COMPONENTES
const int pinoLDR = A0;
const int pinoBuzzer = 9;
const int pinoBOT = 8; 

// Variaveis Gerais
int leituraLDR = 0;
int leituraBOT;

void setup() {
  // Configura os pinos
  pinMode(pinoLDR, INPUT);
  pinMode(pinoBuzzer, OUTPUT);
  pinMode(pinoBOT, INPUT_PULLUP);
}

void loop() {
  // Le o valor de tensao no pino do LDR
  leituraLDR = analogRead(pinoLDR);
  // LE o estado do botao
  leituraBOT - digitalRead(pinoBOT);

  //Se exixtir um obstaculo
  if (leituraLDR <= 512){
    tone(pinoBuzzer, 1000); // Aciona o Buzzer
  }
  else if (leituraBOT == LOW){ // Senão e o botão estiver pressionado
    noTone(pinoBuzzer); // Desliga o Buzzer
  }

  delay(100);
}
