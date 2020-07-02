//Comando Switch e Case

#define pinBot 2
#define pinA 10
#define pinB 9
#define pinC 8
#define pinD 7
#define pinE 6
#define pinF 11 
#define pinG 12
#define pinPD 5

int numero = 10;
boolean botAnt = false ; 
boolean botAtu = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(pinBot,INPUT);
  pinMode(pinA, OUTPUT);
  pinMode(pinB, OUTPUT);
  pinMode(pinC, OUTPUT);
  pinMode(pinD, OUTPUT);
  pinMode(pinE, OUTPUT);
  pinMode(pinF, OUTPUT);
  pinMode(pinG, OUTPUT);
  pinMode(pinPD, OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  botAtu = digitalRead(pinBot);
  if (botAtu && !botAnt){
    numero++;
    if (numero > 9){
      numero = 0;
    }
  }
  botAnt = botAtu;
  switch (numero) {
    case 0:
      digitalWrite(pinA,HIGH);
      digitalWrite(pinB,HIGH);
      digitalWrite(pinC,HIGH);
      digitalWrite(pinD,HIGH);
      digitalWrite(pinE,HIGH);
      digitalWrite(pinF,HIGH);
      digitalWrite(pinG,LOW);
      digitalWrite(pinPD,LOW);
      break;
    case 1:
      digitalWrite(pinA,LOW);
      digitalWrite(pinB,HIGH);
      digitalWrite(pinC,HIGH);
      digitalWrite(pinD,LOW);
      digitalWrite(pinE,LOW);
      digitalWrite(pinF,LOW);
      digitalWrite(pinG,LOW);
      digitalWrite(pinPD,LOW);
      break;
    case 2:
      digitalWrite(pinA,HIGH);
      digitalWrite(pinB,HIGH);
      digitalWrite(pinC,LOW);
      digitalWrite(pinD,HIGH);
      digitalWrite(pinE,HIGH);
      digitalWrite(pinF,LOW);
      digitalWrite(pinG,HIGH);
      digitalWrite(pinPD,LOW);
      break;
    case 3:
      digitalWrite(pinA,HIGH);
      digitalWrite(pinB,HIGH);
      digitalWrite(pinC,HIGH);
      digitalWrite(pinD,HIGH);
      digitalWrite(pinE,LOW);
      digitalWrite(pinF,LOW);
      digitalWrite(pinG,HIGH);
      digitalWrite(pinPD,LOW);
      break;
    case 4:
      digitalWrite(pinA,LOW);
      digitalWrite(pinB,HIGH);
      digitalWrite(pinC,HIGH);
      digitalWrite(pinD,LOW);
      digitalWrite(pinE,LOW);
      digitalWrite(pinF,HIGH);
      digitalWrite(pinG,HIGH);
      digitalWrite(pinPD,LOW);
      break;
    case 5:
      digitalWrite(pinA,HIGH);
      digitalWrite(pinB,LOW);
      digitalWrite(pinC,HIGH);
      digitalWrite(pinD,HIGH);
      digitalWrite(pinE,LOW);
      digitalWrite(pinF,HIGH);
      digitalWrite(pinG,HIGH);
      digitalWrite(pinPD,LOW);
      break;
    case 6:
      digitalWrite(pinA,HIGH);
      digitalWrite(pinB,LOW);
      digitalWrite(pinC,HIGH);
      digitalWrite(pinD,HIGH);
      digitalWrite(pinE,HIGH);
      digitalWrite(pinF,HIGH);
      digitalWrite(pinG,HIGH);
      digitalWrite(pinPD,LOW);
      break;
    case 7:
      digitalWrite(pinA,HIGH);
      digitalWrite(pinB,HIGH);
      digitalWrite(pinC,HIGH);
      digitalWrite(pinD,LOW);
      digitalWrite(pinE,LOW);
      digitalWrite(pinF,LOW);
      digitalWrite(pinG,LOW);
      digitalWrite(pinPD,LOW);
      break;
    case 8:
      digitalWrite(pinA,HIGH);
      digitalWrite(pinB,HIGH);
      digitalWrite(pinC,HIGH);
      digitalWrite(pinD,HIGH);
      digitalWrite(pinE,HIGH);
      digitalWrite(pinF,HIGH);
      digitalWrite(pinG,HIGH);
      digitalWrite(pinPD,LOW);
      break;
    case 9:
      digitalWrite(pinA,HIGH);
      digitalWrite(pinB,HIGH);
      digitalWrite(pinC,HIGH);
      digitalWrite(pinD,LOW);
      digitalWrite(pinE,LOW);
      digitalWrite(pinF,HIGH);
      digitalWrite(pinG,HIGH);
      digitalWrite(pinPD,LOW);
      break;
    default:
      digitalWrite(pinA,LOW);
      digitalWrite(pinB,LOW);
      digitalWrite(pinC,LOW);
      digitalWrite(pinD,LOW);
      digitalWrite(pinE,LOW);
      digitalWrite(pinF,LOW);
      digitalWrite(pinG,LOW);
      digitalWrite(pinPD,HIGH);
      break;
    
  }
}
