// Missão IMPOSSIVEL - Projeto com LAZER

const int pinoLDR = A0; // PINO LDR
int leitura = 0;

void setup() {
  // Inicie e configura a serial
  Serial.begin(9600);

  //Configura o pino do LDR
  pinMode(pinoLDR, INPUT); // Pino ANALOGICO
}

void loop() {
  // Le o valor de tensao no pino LDR
  leitura = analogRead(pinoLDR);

  //Imprime na tela MONITOR SERIAL
  Serial.print("Leitura: ");
  Serial.print(leitura);
  Serial.print("\t");

  //Imprime se existe ou não obstáculo 
  Serial.print("Obstaculo: ");
  if (leitura <= 512){
    Serial.print("SIM|");
  }
  else{
    Serial.print("Não");
  }

  Serial.println(); 

  delay(500);

}
