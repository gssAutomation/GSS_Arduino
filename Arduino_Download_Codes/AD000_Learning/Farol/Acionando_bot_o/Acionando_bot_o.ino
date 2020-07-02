// Ligando com botão 

void setup() {
  pinMode(9,INPUT); // CONFIGURA O BOTÃO COMO ENTRADA
  pinMode(12,OUTPUT); // CONFIGURA O LED COMO SAIDA
}

void loop() {
  // COMANDO PARA ACIONAMENTO DE BOTÃO
  if (digitalRead(9) == HIGH){ // SE O BOTÃO ESTIVER PRESSIONADO (HIGH)
    digitalWrite(12,HIGH); // LED ACENDE
  }
  else{
    digitalWrite(12,LOW);
  }

  if (digitalRead(10) == HIGH){
    digitalWrite(13,HIGH);
  }
  else{
    digitalWrite(13,LOW);
  }

}
