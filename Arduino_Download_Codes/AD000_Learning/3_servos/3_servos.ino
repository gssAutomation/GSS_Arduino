#include <Servo.h> //Inclui biblioteca para servo motor

const int s_garra = 53;                  // Pino de comandos para o servo motor
const int s_motA = 51;                  // Pino de comandos para o servo motor
const int s_motB = 49;                  // Pino de comandos para o servo motor
const int VRY = A0;                     // Pino para leitura do eixo X
const int VRX = A1;                     // Pino para leitura do eixo Y
const int SW = 13;                       // Pino para o botão do joystick

const int CLOSE = 120;                  // Limite de fechamento do servo
const int OPEN = 50;                    // Limite de abertura do servo

int leitura_vrx;                        // Variável de armazenamento do Eixo X
int leitura_vry;                        // Variável de armazenamento do Eixo Y
int leitura_sw;                         // Variável de armazenamento da leitura do botão
int posi_atual = 520;                   // Variável de referência
boolean abrir = 0;                      // Variável de sentido.
boolean fechar = 0;                     // Variável de sentido.


int l_vermelho = 5, l_amarelo = 4, l_verde = 3;

Servo s_GA;
Servo s_MA;
Servo s_MB;

void setup() {
  pinMode(l_vermelho, OUTPUT);
  pinMode(l_amarelo, OUTPUT);
  pinMode(l_verde, OUTPUT);
  pinMode(VRX, INPUT);
  pinMode(VRY, INPUT);
  pinMode(SW, INPUT_PULLUP);
  s_GA.attach(s_garra);
  s_MA.attach(s_motA);
  s_MB.attach(s_motB);
}

void loop(){
  leitura_vry = analogRead(VRY);
  leitura_vrx = analogRead(VRX);
  leitura_sw = digitalRead(SW);
  
  leitura_vrx = map(leitura_vrx, 0, 1023, CLOSE, OPEN);  // Converte valor do potenciometro
  s_MB.write(leitura_vrx); // Aciona servo motor, com base na leitura do eixo x
  delay(10);
  //Verificação da posição do joytick
  if (leitura_vrx >= 550) {
    abrir = 1; // Seta a flag caso o movimento do joystick indicar uma tendencia de abertura
  }
  else if (leitura_vrx <= 490) {
    fechar = 1; // Seta a flag caso o movimento do joystick indicar uma tendencia de fechamento
  }
  
//------------------------------------------------------------------------------------------------
  leitura_vry = map(leitura_vry, 0, 1023, 10, 120);  // Converte valor do potenciometro
  // Aciona servo motor, com base na leitura do eixo x
  s_MA.write(leitura_vry);
  delay(10);
  //Verificação da posição do joytick
  if (leitura_vry >= 550) {
    abrir = 1; // Seta a flag caso o movimento do joystick indicar uma tendencia de abertura
    digitalWrite(l_amarelo,HIGH);
  }
  else if (leitura_vry <= 490) {
    fechar = 1; // Seta a flag caso o movimento do joystick indicar uma tendencia de fechamento
    digitalWrite(l_amarelo,LOW);
  }
//------------------------------------------------------------------------------------------------

  //Leitura do botão Joystick
  if (leitura_sw == 1) {
    s_GA.write(50); // Aciona servo motor com botão
    digitalWrite(l_verde, HIGH);
  } else if (leitura_sw == 0) {
    s_GA.write(120);
  }
}
