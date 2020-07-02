// Projeto Alarme de temperatura atingida

#include <DHT.h>

// Define os pinos de cada componente conectado
const int pino_dht = 9; // DHT (Sensor de temperatura)
const int pinoLEDR = 11; // LED RGB (VERMELHO)
const int pinoLEDG = 12; // LED RGB (VERDE)
const int pinoLEDB = 13; // LED RGB (AZUL)
const int pinoBuzzer = 10; // BUZZER

//Variável para armazenar o valor de temperatura e umidade
float temperatura;
float umidade;

DHT dht(pino_dht, DHT11); // Define o pino e o tipo de DHT

void setup() {
  dht.begin(); // Inicializa o sensor DHT

  // Configura os pinos dos LEDs e buzzer
  pinMode(pinoLEDB, OUTPUT);
  pinMode(pinoLEDG, OUTPUT);
  pinMode(pinoLEDR, OUTPUT);
  pinMode(pinoBuzzer, OUTPUT);
}

void loop() {
  // Aguarda alguns segundos entre uma leotura e outra
  delay(200);

  // A leitura da temperatura ou umidade pode levar 250ms
  // O atraso do sensor pode chegar a 2 segundos
  temperatura = dht.readTemperature(); // le Celsius
  umidade = dht.readHumidity(); // Le a umidade

  // Se ocorreu alguma falha durante a leitura
  if (isnan(umidade) || isnan(temperatura)) {
    // Acende Branco
    digitalWrite(pinoLEDR, HIGH);
    digitalWrite(pinoLEDG, HIGH);
    digitalWrite(pinoLEDB, HIGH);
  }
  else {

    if (temperatura > 35 || temperatura < 15) {
      // Acende Vermelho e aciona buzzer a 2000hz
      digitalWrite(pinoLEDR, HIGH);
      digitalWrite(pinoLEDG, LOW);
      digitalWrite(pinoLEDB, LOW);
      tone(pinoBuzzer, 2000);
      delay(1000);
    }
    else if (temperatura > 30 || temperatura < 20){
      // Acende azul e aciona buzzer a 1000Hz
      digitalWrite(pinoLEDR, LOW);
      digitalWrite(pinoLEDG, LOW);
      digitalWrite(pinoLEDB, HIGH);
      tone(pinoBuzzer, 1000);
      delay(500);
    }
    else {
      // Acende verde
      digitalWrite(pinoLEDR, LOW);
      digitalWrite(pinoLEDG, HIGH);
      digitalWrite(pinoLEDB, LOW);
    }

    //Desliga o Buzzer 
    noTone(pinoBuzzer);
  }
}
