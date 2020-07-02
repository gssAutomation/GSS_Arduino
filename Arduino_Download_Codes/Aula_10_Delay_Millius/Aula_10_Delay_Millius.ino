 //Delay and Millis
 #define pinLedVd 6
 #define pinLedVm 5
 #define pinBot 3

 boolean estadoBot = true;
 boolean estAntBot = true;
 boolean estPisca  = false;

 unsigned long delay1 = 0;
 
 void setup() {
  pinMode (pinLedVd, OUTPUT);
  pinMode (pinLedVm, OUTPUT);
  pinMode (pinBot, INPUT_PULLUP);
}

void loop() {
  // Delay tempo
  // Millis 
  estadoBot = digitalRead(pinBot);
  if (!estadoBot && estAntBot){
    estPisca = !estPisca;
  }
  estAntBot = estadoBot;

  if (estPisca) {
    if ((millis() - delay1) >= 500){
      digitalWrite(pinLedVm, HIGH);
    }
    if ((millis() - delay1) < 500){
      digitalWrite(pinLedVm, LOW);
    }
    if ((millis() - delay1) >= 1000){
      delay1 = millis();
    }
  } else {
    digitalWrite(pinLedVm, LOW);
  }

  delay(10);
}
