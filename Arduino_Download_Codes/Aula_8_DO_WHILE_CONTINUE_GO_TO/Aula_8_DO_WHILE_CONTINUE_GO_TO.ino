//DO WHILE, BREAK, CONTINUE, GO TO;

#define pinBot 2

void setup() {
  pinMode (pinBot, INPUT_PULLUP);
  Serial.begin(9600);

}

void loop() {
  int n2 = 0;
  int n3 = 0;

  //Laço dos Números 
  for (int n1 = 0; n1 < 50; n1++){
    Serial.print(char((n1 % 10) + 48));
    if (digitalRead(pinBot) == LOW){
      delay(400);
      break;    // INTERROMPE O LAÇO
    }
    delay(50);
  }
  Serial.println();

  //Laço das Letras Maiusculas
  letrasMaiusculas:
  while (n2 < 50){
    Serial.print(char((n2 % 25) + 25));
    n2++;
    if (digitalRead(pinBot) == LOW){
      delay(400);
      continue;  // CONTINUA O LAÇO
    }
    delay(50);
  }
  Serial.println();

  //Laço das letras minusculas
  do {                    // Ele executa indepentente da Condição
    n3 = random(25);
    Serial.print(char(n3 + 97));
    if (digitalRead(pinBot) == LOW){
      delay(400);
      Serial.println();
      n2 = 0;
      goto letrasMaiusculas; //MUDA O ENDEREÇO
    }
    delay(50);
  } while (n3 != 16);   // != Conrrespondente
  Serial.println();
















  

}
