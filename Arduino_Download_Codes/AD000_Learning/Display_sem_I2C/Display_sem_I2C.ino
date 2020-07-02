/*
     CÓDIGO:  Display sem módulo I2C
     AUTOR:   Guilherme Silva De Souza
     SKETCH:  TESTE 01
     DATA:    26/05/20
*/

#include <LiquidCrystal.h>

LiquidCrystal lcd(7,6,5,4,3,2);

void setup() {
  // Inicia
  lcd.begin(16,2);
  lcd.clear();
}

void loop() {
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
