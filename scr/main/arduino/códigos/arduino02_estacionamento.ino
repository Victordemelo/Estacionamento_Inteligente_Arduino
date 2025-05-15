//Bibliotecas
#include <Servo.h>

unsigned long tempo_01, tempo_02;
double distancia_01, distancia_02;

//Servo e sensor 01
Servo servo_01;
#define trig_01 4
#define echo_01 5

//Servo e sensor 02
Servo servo_02;
#define trig_02 10
#define echo_02 11


void setup() {

  //Sensores Ultrasônicos para medir
  Serial.begin(9600);
  digitalWrite(trig_01, LOW);
  digitalWrite(trig_02, LOW);


  //Definindo entrada e saida
  pinMode(trig_01, OUTPUT);
  pinMode(echo_01, INPUT);
  servo_01.attach(3);

  pinMode(trig_02, OUTPUT);
  pinMode(echo_02, INPUT);
  servo_02.attach(9);



  //Definindo a posicação inicial do servos
  servo_01.write(20);
  servo_02.write(20);

}

void loop() {

  //medição sensor_01
  {
  digitalWrite(trig_01, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_01, LOW);

  tempo_01 = pulseIn(echo_01, HIGH);
  distancia_01 = tempo_01/58;
  Serial.println(distancia_01);
  delay(200);
  }

  //medição sensor_02 
  {
  digitalWrite(trig_02, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_02, LOW);

  tempo_02 = pulseIn(echo_02, HIGH);
  distancia_02 = tempo_02/58;
  Serial.println(distancia_02);
  }


  //Cancela de entrada
  if(distancia_01 < 15){
    servo_01.write(90);
  } else {
    delay(1200);
    servo_01.write(20);
  }

  //Cancela de Saida
  if(distancia_02 < 15){
    servo_02.write(90);
  } else {
    delay(1200);
    servo_02.write(20);
  }
}
