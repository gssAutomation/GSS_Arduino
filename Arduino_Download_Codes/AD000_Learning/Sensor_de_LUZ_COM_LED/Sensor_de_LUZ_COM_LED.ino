// SENSOR DE LUZ COM LED

const int pinoLDR = A0; // Pino LDR
const int pinoLED = 7; // PINO LED 
const int pinoLED2 = 8;// PINO LED 2
int leitura = 0; // Variavel para armazenar o valor lido pelo ADC

void setup() {
  //Configura os pinos LDR e LED
  pinMode(pinoLDR, INPUT);
  pinMode(pinoLED, OUTPUT);
  pinMode(pinoLED2, OUTPUT);
}

void loop() {
  // Le o valor de ADC no pino do LDR
  leitura = analogRead(pinoLDR);

  //Verifica LUMINOSIDADE DO AMBIENTE
  if(leitura < 40){ // Se a leitura for menor que 40 acende o led
    digitalWrite(pinoLED, HIGH); // ACENDE O LED VERMELHO
    digitalWrite(pinoLED2,LOW);
  }
  else{
    digitalWrite(pinoLED, LOW); // Apaga o LED
    digitalWrite(pinoLED2, HIGH);
  }
  delay(100);
  if(leitura < 100){
    digitalWrite(pinoLED2, HIGH);
    digitalWrite(pinoLED, LOW);
  }
  else{
    digitalWrite(pinoLED2, LOW);
    digitalWrite(pinoLED, HIGH);
  }
  delay(100);
}
