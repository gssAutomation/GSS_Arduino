// Aprendendo a configurar o Display LCD 
// Utilizando Display 16x2 com Módulo I2C

//Incluindo Bibliotecas 
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

//Definindo as portas lógicas 
#define I2C_ADDR  0x3F
#define BACKLIGHT_PIN 3
#define En 2
#define Rw 1
#define Rs 0
#define D4 4
#define D5 5
#define D6 6
#define D7 7
LiquidCrystal_I2C lcd(I2C_ADDR, En, Rw, Rs, D4, D5, D6, D7);

void setup() {
  // Setando o display
  lcd.begin (16,2); // Tipo de Display
  lcd.setBacklightpin(BACKLIGHT, POSITIVE);
  lcd.setBacklight(HIGH); // Ligando Fundo do Display

  lcd.setCursor(4,0);
  lcd.print("Guilherme");
  lcd.setCursor("Vem Comigo");
}

void loop() {
  // put your main code here, to run repeatedly:

}
