/*
     CÓDIGO:  Display - Servo Motor - Sensor Optico
     AUTOR:   GUILHERME SOUZA
     DATA:    Inicio: 25/05/2020
     OBS:  
*/
//>>>>>>>>>>>Incluir bilbiotecas
#include <Wire.h>                         //<-------Display
#include <LiquidCrystal_I2C.h>            //<-------Display
#include <Servo.h>                        //<-------Servo Motor
#include <Ultrasonic.h>                   //<-------Sensor Ultrassonico

// Defines
#define led_vermelho  5                  //<-------Led Vermelho garra aberta
#define led_verde  4                     //<-------Led Verde garra fechada

#define TRIG  3                          //<-------Sensor Ultrassonico
#define ECHO  2                          //<-------Sensor Ultrassonico

#define endereco 0x27                     //<-------Display
#define colunas 16                        //<-------Display
#define linhas 2                          //<-------Display

//Inicialização
Ultrasonic ultrasonic(TRIG, ECHO);
LiquidCrystal_I2C lcd(endereco, colunas, linhas);

//>>>>>>>>>>>Servo Motores
Servo s_Garra;
Servo s_motA;
Servo s_motB;
int base_servo;

void setup() {
  // Garra Robótica
  //Sensor Ultrasonico 
  pinMode(TRIG,OUTPUT);
  pinMode(ECHO,INPUT);
  // Servos
  s_Garra.attach(53);                                                // Informa qual pino será usado para o servo declarado anteriormente.
  s_motA.attach(10);                                                // Pino do servo base
  s_Garra.write(70);                                                //Informa ao servo que deverá se posicionar a 10 graus
  s_motA.write(10);
  //Leds
  pinMode(led_vermelho, OUTPUT);
  pinMode(led_verde, OUTPUT);

  //Servo base e servo alavanca
  //serv_motB.attach(32); //Pino do servo alavanca

  lcd.init();
  lcd.backlight();
  lcd.clear();
}

void loop() {
  //Sensor ultrasonico
  float cmMsec;
  long microsec = ultrasonic.timing();
  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
  if (cmMsec < 5) {                                             // Condicional para leituras inferiores a 10cm.
    s_Garra.write(120);
    //Colocar msg no display
    digitalWrite(led_verde, HIGH);
    digitalWrite(led_vermelho, LOW);
    delay(500);
  } else if (cmMsec > 20){                                      // 
      s_Garra.write(70);
      digitalWrite(led_vermelho, HIGH);
      digitalWrite(led_verde, LOW);
      delay(500);
  } 
  lcd.setCursor(2,0);
  lcd.print("GSS Automation");
  lcd.setCursor(2,1);
  lcd.print("Leitura:");
  lcd.setCursor(10,1);
  lcd.print(cmMsec);
  //optico_base();
}

/*void optico_base(){
  for (base_servo = 10; base_servo >= 10; base_servo++){
    s_motA.write(base_servo);
    delay(50);
    if (base_servo == 170){
      for (base_servo ; base_servo >=10; base_servo--){
        s_motA.write(base_servo);
        delay(50);
      }
    }
  }
}*/
