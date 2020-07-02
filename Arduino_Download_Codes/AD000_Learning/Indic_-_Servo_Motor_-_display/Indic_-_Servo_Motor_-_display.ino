/*
     CÓDIGO:  Display LCD 16x2 Módulo I2C - Servo Motor - Indicação de graus
     AUTOR:   GUILHERME SOUZA
     DATA:    Inicio: 20/05/2020 
     OBS: 
*/

// Bibliotecas
#include <Wire.h>               // Display
#include <LiquidCrystal_I2C.h>  // Display
#include <Servo.h>              // Servo Motor

//Instanciando Objetos 
#define endereco 0x27           // Endereço Serial do Display
#define colunas 16
#define linhas 2

LiquidCrystal_I2C lcd(endereco, colunas, linhas);

// Variáveis 
const int pot = A0;             // Potenciômetro
int leitura;                    // Leitura do potenciômetro
int graus = 0;                  // Graus
bool k = false;
byte buzz = 5;

Servo servo_motor;              // Objeto para o servo motor 

void setup() {
  // Pinagens
  for (byte  pot = A5; pot < 5; pot++) pinMode(pot, INPUT);          //Pinagem do potenciômetro
  pinMode(buzz, OUTPUT);
  servo_motor.attach(9);        //Pinagem do Servo motor

  //Inicializa o Display
  lcd.init();
  lcd.noBacklight();
  delay(1000);
  lcd.backlight();
  lcd.clear();

  //
}

void loop() {
  
  leitura = analogRead(pot);
  leitura = map(leitura, 0, 1023, 10, 170);
  servo_motor.write(leitura);
  delay(100);

  lcd.setCursor(0,0);
  lcd.print("Lendo:");
  lcd.setCursor(11,0);
  lcd.print("graus");
  lcd.setCursor(7,0);
  lcd.print(leitura);

  if (leitura < 85){
    lcd.setCursor(8,1);
    lcd.print("--->");
  }else{
    lcd.setCursor(8,1);
    lcd.print("<---");
  }
  
}
