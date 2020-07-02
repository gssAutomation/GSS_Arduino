#include <LiquidCrystal.h>

LiquidCrystal lcd(7,6,5,4,3,2);

#define pinSom 8
#define pinRele1 9
#define pinRele2 12
#define tempoMaximoDeUmaPalma  150 //milisegundos
#define tempoMaximoEntrePalmas 500 //milisegundos

int contaPalmas = 0;
long tempoEspera = 0;
long tempoEsperaEntrePalmas = 0;

void executarAcao();

void setup() {
  lcd.begin(16,2);
  lcd.clear();
  pinMode(pinSom, INPUT);
  pinMode(pinRele1, OUTPUT);
  pinMode(pinRele2, OUTPUT);
}

void loop() {
  //verifica o estado do sensor de som (ele fica normalmente com a porta ligada. Quando ouver uma palma, ele desliga momentaneamente a porta)
  int sensorSom = digitalRead(pinSom);

  //se o sensor detectou palmas
  if (sensorSom == LOW) {

     //espera um tempo para nao detectar a mesma palma mais de uma vez 
     if (tempoEspera == 0) {
        tempoEspera = tempoEsperaEntrePalmas = millis(); 
        contaPalmas++;
     } else if ((millis() - tempoEspera) >= tempoMaximoDeUmaPalma) {
        tempoEspera = 0;
     }
  }

  //caso exceda o tempo maximo entre palmas, zera o contador de palmas
  if ( (contaPalmas != 0) && ((millis() - tempoEsperaEntrePalmas) > 500) ) {
     executarAcao();
     contaPalmas = 0;
     tempoEsperaEntrePalmas = millis();
  }
  
}


void executarAcao() 
{
  
  switch (contaPalmas) {
    case 2: 
       digitalWrite(pinRele1, !digitalRead(pinRele1));
       break;
    case 3:
       digitalWrite(pinRele2, !digitalRead(pinRele2));
       break;
  }
}

void Display() {
  lcd.setCursor(2,0);
  lcd.print("Sistema");
  lcd.setCursor(2,1);
  lcd.print("Automatizado");
  delay(5000);

  for (int pos = 0; pos < 3; pos++){
    lcd.scrollDisplayLeft();
    delay(100);
  }

    for (int pos = 0; pos < 6; pos++){
    lcd.scrollDisplayRight();
    delay(100);
  }

    for (int pos = 0; pos < 3; pos++){
    lcd.scrollDisplayLeft();
    delay(100);
  }
  delay(1000);

  lcd.noDisplay(); //Apaga o display 
  delay(500);
  lcd.display();
  delay(500);

  lcd.setCursor(2,0);
  lcd.print("Tudo OK");
  lcd.setCursor(2,1);
  lcd.print("Sr. Edinaldo");
  delay(5000);

    for (int pos = 0; pos < 3; pos++){
    lcd.scrollDisplayLeft();
    delay(100);
  }

    for (int pos = 0; pos < 6; pos++){
    lcd.scrollDisplayRight();
    delay(100);
  }

    for (int pos = 0; pos < 3; pos++){
    lcd.scrollDisplayLeft();
    delay(100);
  }
  delay(1000);

  lcd.noDisplay(); //Apaga o display 
  delay(500);
  lcd.display();
  delay(500);

  lcd.clear();
}
