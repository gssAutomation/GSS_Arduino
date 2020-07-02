void setup() {
  pinMode(9,OUTPUT); //VERDE PEDESTRE
  pinMode(10,OUTPUT); //VERMELHO PEDESTRE
  pinMode(11,OUTPUT); //VERDE
  pinMode(12,OUTPUT); //AMARELO
  pinMode(13,OUTPUT); //VERMELHO

}

void loop() {

  //Linha de Código: PEDESTRE
  digitalWrite(9,LOW);
  digitalWrite(10,HIGH);

  // Linha de códigos para sistema do farol
  digitalWrite(11,HIGH);
  digitalWrite(12,LOW);
  digitalWrite(13,LOW);
  delay(3000);

  digitalWrite(11,LOW);
  digitalWrite(12,HIGH);
  digitalWrite(13,LOW);
  delay(2000);

  //Linha de Código: PEDESTRE
  digitalWrite(9,HIGH);
  digitalWrite(10,LOW);
  //Semaforo
  digitalWrite(11,LOW);
  digitalWrite(12,LOW);
  digitalWrite(13,HIGH);
  delay(5000);

  }
