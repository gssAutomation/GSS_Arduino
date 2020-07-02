// Aula de Gráfico 

const int pinoPotenciometro = A0; // Pino ONDE O POTENCIOMETRO ESTÁ CONECTADO
int leitura = 0; // VARIAVEL PARA ARMAZENAR VALOR LIDO PELO ADC
float tensao = 0.0; // VARIAVEL PARA ARMAZER A TENSAO

void setup() {
  // Inicia e configura a Serial
  Serial.begin(9600);

  // CONFIGURA O PINO COM POTENCIOMETRO COMO ENTRADA
  pinMode(pinoPotenciometro, INPUT); // Pino A0
  
}

void loop() {
  // Le o valor de tensao no pino do potenciometro 
  leitura = analogRead(pinoPotenciometro);

  //CONVERTE E IMPRIME O VALOR EM TENSAO ELÉTRICA
  tensao = leitura * 5.0 / 1023;

  // IMPRIME VALOR NO PLOTTER SERIAL
  Serial.println(leitura);
  Serial.print(" "); // Separa as variáveis
  Serial.println(tensao*100);
  Serial.print(" "); // Separa as variáveis
  Serial.println(tensao*90);
  Serial.print(" "); // Separa as variáveis
  Serial.println(tensao*2);
  Serial.print(" "); // Separa as variáveis
  Serial.println(tensao*80);
  Serial.print(" "); // Separa as variáveis

  delay(100); // Intervalo de tempo para nova leitura

}
