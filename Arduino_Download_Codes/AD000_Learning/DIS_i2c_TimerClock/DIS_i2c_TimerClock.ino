/*
     CÓDIGO:  Display LCD 16x2 Módulo I2C - Relógio Digital
     AUTOR:   GUILHERME SOUZA
     DATA:    Inicio: 15/05/2020 - 18/05/2020 
     OBS: Houve alguns problemas de falta de atenção e percebi que tenho que ter mais atenção na hora das coisas 
*/

//______________________________________________________________________INCLUINDO BIBLIOTECAS_______________________________________________________________________________ 
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <TimerOne.h>

//______________________________________________________________________Display______________________________________________________________________________________________
#define endereco 0x27
#define colunas 16
#define linhas 2

LiquidCrystal_I2C lcd(endereco, colunas, linhas);

//_____________________________________________________________________Variáveis_____________________________________________________________________________________________
int hor = 0, Min = 0, sec = 0,  rg_hor = 0, rg_min = 0;
byte mod, set = 2, up = 3, dw = 4, buzz = 5, t_ant;
bool k = false, ring = false;


void setup() {
  /*--------------------------------------Inicializando o Display------------------------*/ 
  lcd.init();
  lcd.noBacklight();
  delay(1000);
  lcd.backlight();
  lcd.clear();
  /*---------------------------------------LAÇO PARA BUT---------------------------------*/
  for (byte i = 2; i < 5; i++) pinMode(i, INPUT_PULLUP);
  pinMode(buzz, OUTPUT);
  Timer1.initialize(1000000); // 1 segundo
  Timer1.attachInterrupt(clk);
  /*-------------------------------------------------------------------------------------*/
}

void loop() {
  /*---------------------------------------Chama as funções------------------------------*/ 
  ajust();
  Display();
  alarme();
  /*-------------------------------------------------------------------------------------*/
}

void ajust(){
  int h = 0, hh = 0, m = 0, mm = 0;
  if(!digitalRead(set) and !k) mod++;   /*Botão para configurar a hora*/ 
  if(mod > 4){
    lcd.clear();
    ring = !ring;
    mod  = ring;
  }
  /*   Ajustes de tempo / Ajuste de alarme   */
  if (ring){
  m =  rg_min % 10;
  mm = rg_min / 10;
  h =  rg_hor % 10;
  hh = rg_hor / 10;
  } else {
  m =  Min % 10;
  mm = Min / 10;
  h =  hor % 10;
  hh = hor / 10;
  }
  /*Configura o botão do set para o relógio digital */
  if (!k){
         if ((m  += mod == 1 and !digitalRead(up)) > 9) m = 0;   //Botão UP
    else if ((m  -= mod == 1 and !digitalRead(dw)) < 0) m = 9;   //Botão DOWN
    else if ((mm += mod == 2 and !digitalRead(up)) > 5) mm = 0;  //Botão UP
    else if ((mm -= mod == 2 and !digitalRead(dw)) < 0) mm = 5;  //Botão DOWN
    else if ((h  += mod == 3 and !digitalRead(up)) > 9) h = 0;   //Botão UP
    else if ((hh -= mod == 3 and !digitalRead(dw)) < 0) hh = 9;  //Botão DOWN
    else if (mod == 4 and !digitalRead(up)){
         if (++hh > 2 or (hh > 1 and h > 3)) hh = 0;}
    else if (mod == 4 and !digitalRead(dw)){
      if (--hh < 0 and h < 4 ) hh = 2;
    else if (hh < 0 and h > 3) hh = 1;
    }
  }
  if (ring){
    rg_min = m + mm * 10;
    rg_hor = h + hh * 10;
  } else {
    Min = m + mm * 10;
    hor = h + hh * 10;
  } 
  
  k = false;
  for (byte i = 2; i < 5; i++) if (!digitalRead(i)) k = true;
}

void clk(){
  /*Vai acrescentando de 1 em 1 segundo conforme o tempo*/
  sec++;
}

void alarme(){
  /*-----------------------------Alarme-------------------------------------*/
  if (rg_hor == hor and rg_min == Min and rg_hor + rg_min){
    if(sec % 2){
      tone (buzz, 100, 100); /*Adiciona o som para o speaker*/
      lcd.setCursor(14, 1);
      lcd.print(" ");
    }
  }
}

void Display(){
    if(ring){
      if (sec > 59){      // Quando os segundos passarem de 59 ele volta a ser 0 e acrescenta 1 min
    sec = 0;
    Min++;
  }
  if (Min > 59){
    Min = 0;
    hor++;
  }
  if (hor > 23){
    hor = 0;
  }
  lcd.setCursor(3, 1);
  if (rg_hor < 10){
    lcd.print("0");
    lcd.setCursor(4, 1);
  }
  lcd.print(rg_hor);
  lcd.setCursor(5, 1);
  lcd.print(":");
  lcd.setCursor(6, 1);
  if (rg_min < 10){
    lcd.print("0");
    lcd.setCursor(7, 1);
  }
  lcd.print(rg_min);
  /* Mostra o cursor de cada número para configuração dos sec, min e hor; */
  lcd.setCursor(0, 0);
       if (mod == 1) lcd.print("       _  Alarme");
  else if (mod == 2) lcd.print("      _   Alarme");
  else if (mod == 3) lcd.print("    _     Alarme");
  else if (mod == 4) lcd.print("   _      Alarme");
 } else {
  if (sec > 59){      /*Quando os segundos passarem de 59 ele volta a ser 0 e acrescenta 1 min*/ 
    sec = 0;
    Min++;
  }
  if (Min > 59){
    Min = 0;
    hor++;
  }
  if (hor > 23){
    hor = 0;
  }
  lcd.setCursor(3, 1);
  if (hor < 10){
    lcd.print("0");
    lcd.setCursor(4, 1);
  }
  lcd.print(hor);
  lcd.setCursor(5, 1);
  lcd.print(":");
  lcd.setCursor(6, 1);
  if (Min < 10){
    lcd.print("0");
    lcd.setCursor(7, 1);
  }
  lcd.print(Min);
  lcd.setCursor(8, 1);
  lcd.print(":");
  lcd.setCursor(9, 1);
  if (sec < 10){
    lcd.print("0");
    lcd.setCursor(10, 1);
  }
  lcd.print(sec);
  /* Mostra o cursor de cada número para configuração dos sec, min e hor; */
  lcd.setCursor(0, 0);
       if (mod == 1) lcd.print("       _   Ajuste");
  else if (mod == 2) lcd.print("      _    Ajuste");
  else if (mod == 3) lcd.print("    _      Ajuste");
  else if (mod == 4) lcd.print("   _       Ajuste");
    }
  /* Períodos de horas faz aparecer mensagens de madrugada, manhã, tarde e noite; */
  if (mod == 0){
         if (hor < 6)               lcd.print("Boa Madrugada");
    else if (hor > 6  and hor < 12) lcd.print("Bom dia");
    else if (hor > 11 and hor < 18) lcd.print("Boa Tarde");
    else if (hor > 18)              lcd.print("Boa Noite");
  }
  /*Apresenta no display um caracter especial quando o alarme for ligado e 
   * quando deligar o alarme desligara o caracter especial; */
  lcd.setCursor(14, 1);
  if (rg_hor + rg_min) lcd.print(char(016));
  else lcd.print("  ");
}
