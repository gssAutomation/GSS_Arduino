// Dimmer LED com PWM

const int pinoPotenciometro = A0;
const int pinoLED = 11;
int leitura = 0;
int pwm = 0;

void setup() {
  pinMode(pinoPotenciometro, INPUT);
  pinMode(pinoLED, OUTPUT);

}

void loop() {
  // Le o valor de tensao no pino do potenciometro
  leitura = analogRead(pinoPotenciometro);

  // Converte o valor do potenciometro, de 0 a 1023, em um valor de 0 a 255
  pwm = map(leitura, 0, 1023, 0, 255);

  // Atualiza a razão ciclica do pino 11, variando  intensidade do led
  analogWrite(pinoLED, pwm);

}
