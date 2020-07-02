
unsigned char letra;

void setup() {
  Serial.begin(9600);

  char especial = '\n';

  Serial.println();
  Serial.print("Primeira Frase.\0Segunda Frase");
  Serial.print(especial);
  Serial.print("\tTerceira Frase.");
}

void loop() {
  // put your main code here, to run repeatedly:

}
