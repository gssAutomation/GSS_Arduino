/*
     CÓDIGO:  Régua com Sensor Ultrassõnico
     AUTOR:   Guilherme Silva De Souza 
     SKETCH:  LiquidCrystal_I2C -- Sensor Ultrassonico
     DATA:    14/05/2020
*/

// INCLUSÃO DE BIBLIOTECAS
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Ultrasonic.h>

// DEFINIÇÕES
#define endereco  0x27 // Endereços comuns: 0x27, 0x3F
#define colunas   16
#define linhas    2
#define pin_TRIG 3
#define pin_ECHO 2

// INSTANCIANDO OBJETOS
LiquidCrystal_I2C lcd(endereco, colunas, linhas);
Ultrasonic sensor(pin_TRIG, pin_ECHO);

void setup() {
  //Star
  lcd.init();      // Inicia o Display
  lcd.backlight(); // Iluminação
  lcd.clear();     // Limpa Display
  delay(100);
  lcd.print("GSS_AUTOMATION");
  
}

void loop() {
  // put your main code here, to run repeatedly:
  /*
  long microsec = sensor.timing();
  float cm = sensor.convert(microsec, Ultrasonic::CM);
  */
  lcd.setCursor(1,1);
  lcd.print("Distancia: ");
  lcd.setCursor(1,12);
  //  lcd.print(cm);
}
