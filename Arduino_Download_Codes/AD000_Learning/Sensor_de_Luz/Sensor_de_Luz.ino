// Projeto SENSOR DE LUZ

const int pinoLDR = A0; // Pino onde o LDR está conectado
const int pinoLED = 7;
int leitura = 0;
float tensao = 0.0;

void setup() {
  // Inicia a configuração serial
  Serial.begin(9600); // 9600bps

  // Configura o pino com LDR como entrada
  pinMode(pinoLDR, INPUT); // PINO A0 Pino analógico
  
}

void loop() {
  // le o valor da tensao do pino LDR
  leitura = analogRead(pinoLDR);

  //Impirime o valor lido pelo arduino (0 a 1023);
  Serial.print("Leitura: ");
  Serial.print(leitura);
  Serial.print("\t"); // Tabulacao

  //Converte e imprime o valor em tesão elétrica
  tensao = leitura * 5.0 / 1023.0;
  Serial.print("Tensão: ");
  Serial.print(tensao);
  Serial.print("V");

  Serial.println();// Nova linha 

  delay(1000);

}
