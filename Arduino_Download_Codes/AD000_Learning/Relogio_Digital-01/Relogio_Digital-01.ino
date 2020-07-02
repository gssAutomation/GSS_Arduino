
//---------------------------------------------------//Incluindo Bibliotecas
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <TimerOne.h>

//----------------------------------------------------//Display
#define endereco 0x23 // Endereço serial do display
#define colunas 16
#define linhas 2

//Instanciando Objetos
LiquidCrystal_I2C lcd(endereco, colunas, linhas);

int hor = 0, Min = 0, sec = 0;
byte mod, set = 2, up = 3, dw = 4, buzz = 5, t_ant;


void setup() {
  // Setando Display
  lcd.init();                       // Iniciando Display
  lcd.noBacklight();
  delay(200);
  lcd.backlight();
  lcd.clear();

  for (byte i = 2; i < 5; i++) pinMode(i, INPUT_PULLUP);
  pinMode(buzz, OUTPUT);
  Timer1.initialize(1000000);  // 1 Segundo
  Timer1.attachInterrupt(clk);
  
}

void loop() {
  // Chama as funções
  adjust();
  Display();
  alarme();

}

void adjust(){
  
}

void clk(){
  sec++;
}

void alarme(){
  
}

void Display(){
  if(sec > 59){        // Se os segundos for maior que 59 acrescenta 1 min
    sec = 0;
    Min++;
  }
  if (Min > 59){      // Se os minutos for maior que 59 acrescenta 1 hora
    Min = 0;
    hor++;
  }
  if (hor > 23){      // Se ás horas forem maiores que 23 acrescenta 00:00 noite
    hor = 0;
  }
  lcd.setCursor(3,1);
  if (hor < 10){
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
