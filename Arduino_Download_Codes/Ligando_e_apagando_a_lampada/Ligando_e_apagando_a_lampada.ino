 /*
     CÓDIGO:  Ligar e apagar a luz com sensor de som 
     AUTOR:   Guilherme Silva De Souza
     SKETCH:  TESTE 01
     DATA:    26/05/20
*/

//Programa para acender as luzes com palmas
int pino_som = 8;                     //Define o pino que será utilizado para o sensor de som
int pino_rele = 9;                    //E o que será utilizado para o rele
boolean rele = HIGH;                  // Define um booleano para poder usar a operacao NAO

#include <LiquidCrystal.h>

LiquidCrystal lcd(7,6,5,4,3,2);

void setup() {
  lcd.begin(16,2);
  lcd.clear();
  pinMode(pino_som, INPUT);           //Coloca o pino do sensor de som como entrada
  pinMode(pino_rele, OUTPUT);         // E o do rele como saida
}
 
void loop() {
  int som = digitalRead(pino_som);    //Verifica se a saida do sensor esta ativa
   
   if(som){                           // Se o som estiver alto
    rele = !rele;                     //Operacao NAO: Se estiver LOW, passa pra HIGH. Se estiver HIGH passa para LOW
    digitalWrite(pino_rele, rele);    // Manda o valor da variavel para o rele
    delay(1000);                      // Aguarda 1 segundo para não ficar ligando e desligando sem parar
   }

  lcd.setCursor(2,0);
  lcd.print("Sistema");
  lcd.setCursor(2,1);
  lcd.print("Automatizado");

  /*for (int pos = 0; pos < 3; pos++){
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

  /*lcd.noDisplay(); //Apaga o display 
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

  lcd.clear();*/
}

/*void Display() {
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
}*/
