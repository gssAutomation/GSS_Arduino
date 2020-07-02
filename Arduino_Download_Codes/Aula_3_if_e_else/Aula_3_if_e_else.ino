int pin_ama = 10; 
int pin_ver = 9;
int pin_vrm = 8;
int pinbot = 7;

int faseFarol;
int estadoBot;

void setup() {
  // put your setup code here, to run once:
  pinMode(pin_ama, OUTPUT);
  pinMode(pin_ver, OUTPUT);
  pinMode(pin_vrm, OUTPUT);
  pinMode(pinbot, INPUT);

  faseFarol = 1;
}

void loop() {
  // put your main code here, to run repeatedly:

  estadoBot = digitalRead(pinbot);

  if (estadoBot == HIGH){
    if (faseFarol < 3){
      faseFarol = faseFarol + 1;
    }else{
      faseFarol = 1;
    }
  }
  
  if (faseFarol == 1){
    digitalWrite(pin_ver, HIGH);
    digitalWrite(pin_ama, LOW);
    digitalWrite(pin_vrm, LOW);
  }
  
  if (faseFarol == 2){
    digitalWrite(pin_ver, LOW);
    digitalWrite(pin_ama, HIGH);
    digitalWrite(pin_vrm, LOW);
  }

  if (faseFarol == 3){
    digitalWrite(pin_ver, LOW);
    digitalWrite(pin_ama, LOW);
    digitalWrite(pin_vrm, HIGH);
  }
  delay(100);
}
