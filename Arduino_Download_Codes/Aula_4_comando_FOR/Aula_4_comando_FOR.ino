
int pinLed[9] = {12,11,10,9,8,7,6,5,4};

void setup() {
  // Comando FOR
  for (x = 0; x <= 9; x = x + 1){
    pinMode(pinLed[x],OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
