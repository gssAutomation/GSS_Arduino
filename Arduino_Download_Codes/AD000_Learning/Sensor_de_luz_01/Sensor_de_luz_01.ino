// SENSOR DE LUZ - teste

const int pinoLDR = A0;
int leitura = 0;
float tensao = 0.0;

void setup() {
  // Inicia e configura o serial
  Serial.begin(9600);

  //Configura o pino com LDR como entrada
  pinMode(pinoLDR, INPUT); // PINO A0
}

void loop() {
  // Le o valor da tensao no pino do LDR
  leitura = analogRead(pinoLDR);

  //Imprime valor lido pelo arduino (0 a 1023)
  Serial.print("leitura: ");
  Serial.print(leitura);
  Serial.print("\t");

  // Converte e imprime o valor em tensão elétrica
  tensao = leitura * 5.0 / 1023.0;
  Serial.print("tensão: ");
  Serial.print(tensao);
  Serial.println(); // Nova Linha
  Serial.print("V");

  delay(1000);
  

}
