/*
     CÓDIGO:  Montando um relógio digital
     AUTOR:   Guilherme Silva De Souza
     DATA:    14/05/2020
*/

//                          Incluindo as bibliotecas
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <TimerOne.h> 

//                          Definições do Display
#define endereco 0x27
#define colunas 16
#define linhas 2

//                          Instaciando objetos
LiquidCrystal_I2C lcd(endereco, colunas, linhas);

//    Setando  --------------->
int hor = 0, Min = 0, sec = 0;
byte mod, set = 2, up = 3, dw =4, buzz = 5, t_ant;
bool k = false, ring = false;

void setup() {
  // Iniciando 
  lcd.init();             // Inicializando
  lcd.backlight();        // Ligando
  lcd.clear();            // Limpando dados

  //Primeiro comando
  for (byte i = 2; i < 5 ; i++) pinMode(i, INPUT_PULLUP);
  pinMode(buzz, OUTPUT);
  Timer1.initialize(1000000); // 1 segundo
  Timer1.attachInterrupt(clk);
}

void loop() {
  // Chama as funções 
  adjust();
  Display();
  alarme();
}

//Ajuste do relógio
void adjust(){
  int h = 0, hh = 0, m = 0, mm = 0;         // Configura as variáveis
  if(!digitalRead(set) and !k) mod++;       // Fas o teste se esta HIGH ou LOW
  if(mod > 4){
    lcd.clear();                            // Limpa o display
  }
  //Ajustes de horário
  m = Min % 10;
  mm = Min / 10;
  h = hor % 10;
  hh = hor / 10;

  if (!k){
         if ((m += mod == 1 and !digitalRead(up)) > 9) m = 0;
    else if ((m -= mod == 1 and !digitalRead(dw)) < 0) m = 9;
  }
  Min = m + mm * 10; // Os minutos recebe as unidades x 10
  hor = h + hh * 10; // As horas recebem as unidades x 10 

  k = false;
  for(byte i = 2; i < 5; i++) if (!digitalRead(i)) k = true;
}

// CLOCK
void clk(){
  sec++;
}

//Alarme para o Relógio
void alarme(){
  
}

//Configuração do Display
void Display(){
  if(sec > 59){
    sec = 0;
    Min++;
  }
  if(Min > 59){
    Min = 0;
    hor++;
  }
  if(hor > 23){
    hor = 0;
  }
  lcd.setCursor(3,1);
  if(hor < 10){
    lcd.print("0");
    lcd.setCursor(4,1);
  }
  lcd.print(hor);
  lcd.setCursor(5,1);
  lcd.print(":");
  lcd.setCursor(6,1);
  if (Min < 10){
    lcd.print("0");
    lcd.setCursor(7,1);
  }
  lcd.print(Min);
  lcd.setCursor(8,1);
  lcd.print(":");
  lcd.setCursor(9,1);
  if(sec < 10){
    lcd.print("0");
    lcd.setCursor(10,1);
  }
  lcd.print(sec);
}
