// Bibliotecas
#include <LiquidCrystal.h>

// Definindo a porta do Display LCD
const int rs = 8, en = 11, d4 = 10, d5 = 12, d6 = 9, d7 = 13;
LiquidCrystal display_01(rs, en, d4, d5, d6, d7);


// Definindo as portas dos leds RGB
#define vermelho_01 A0
#define verde_01 A1

#define vermelho_02 A2
#define verde_02 A3

#define vermelho_03 A4
#define verde_03 A5

#define vermelho_04 2 
#define verde_04 3


// Definindo as portas dos sensores de obstáculos
#define sensor_01 4
#define sensor_02 5 
#define sensor_03 6
#define sensor_04 7



void setup() {
  // Definindo o tamanho do display
  display_01.begin(16, 2);

  // Configurando os pinos como entrada ou saída
  pinMode(vermelho_01, OUTPUT);
  pinMode(verde_01, OUTPUT);
  pinMode(sensor_01, INPUT);

  pinMode(vermelho_02, OUTPUT);
  pinMode(verde_02, OUTPUT);
  pinMode(sensor_02, INPUT);

  pinMode(vermelho_03, OUTPUT);
  pinMode(verde_03, OUTPUT);
  pinMode(sensor_03, INPUT);

  pinMode(vermelho_04, OUTPUT);
  pinMode(verde_04, OUTPUT);
  pinMode(sensor_04, INPUT);

  // Leds começam com verde ligado e vermelho desligado
  digitalWrite(verde_01, HIGH);
  digitalWrite(vermelho_01, LOW);

  digitalWrite(verde_02, HIGH);
  digitalWrite(vermelho_02, LOW);

  digitalWrite(verde_03, HIGH);
  digitalWrite(vermelho_03, LOW);

  digitalWrite(verde_04, HIGH);
  digitalWrite(vermelho_04, LOW);

  display_01.clear();
  display_01.setCursor(0, 0);
  display_01.print("BEM VINDOS AO");
  display_01.setCursor(0, 1);
  display_01.print("ESTACIONAMENTO");
  delay(5000);
}

void loop() {

  // Definindo os if e else
  // Sensor 01
  if (digitalRead(sensor_01) == 0) {
    digitalWrite(verde_01, LOW);
    digitalWrite(vermelho_01, HIGH);
  } else {
    digitalWrite(verde_01, HIGH);
    digitalWrite(vermelho_01, LOW);
  }

  // Sensor 02
  if (digitalRead(sensor_02) == 0) {
    digitalWrite(verde_02, LOW);
    digitalWrite(vermelho_02, HIGH);
  } else {
    digitalWrite(verde_02, HIGH);
    digitalWrite(vermelho_02, LOW);
  }

  // Sensor 03
  if (digitalRead(sensor_03) == 0) {
    digitalWrite(verde_03, LOW);
    digitalWrite(vermelho_03, HIGH);
  } else {
    digitalWrite(verde_03, HIGH);
    digitalWrite(vermelho_03, LOW);
  }

  // Sensor 04
  if (digitalRead(sensor_04) == 0) {
    digitalWrite(verde_04, LOW);
    digitalWrite(vermelho_04, HIGH);
  } else {
    digitalWrite(verde_04, HIGH);
    digitalWrite(vermelho_04, LOW);
  }

  display_01.clear();
  display_01.setCursor(0, 0);
  display_01.print("V1:");
  display_01.print(digitalRead(sensor_01) == 0 ? "X " : "OK ");
  display_01.print("V2:");
  display_01.print(digitalRead(sensor_02) == 0 ? "X " : "OK");

  display_01.setCursor(0, 1);
  display_01.print("V3:");
  display_01.print(digitalRead(sensor_03) == 0 ? "X " : "OK ");
  display_01.print("V4:");
  display_01.print(digitalRead(sensor_04) == 0 ? "X " : "OK");

  delay(200);
}
