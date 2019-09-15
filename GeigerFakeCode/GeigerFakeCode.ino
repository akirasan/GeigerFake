// Geiger Fake Code
// Simulador del sonido de un Geiger
//
// By Akirasan (@akirasan) SEPT 2019
//
//*****************************************

#include <Ultrasonic.h>

#define buzzer 8
#define led_rojo 2
#define led_verde 3

Ultrasonic ultrasonic(12, 13);

void setup() {
  pinMode(buzzer, OUTPUT);
  digitalWrite(buzzer, LOW);

  pinMode(led_verde, OUTPUT);
  digitalWrite(led_verde, LOW);
  pinMode(led_rojo, OUTPUT);
  digitalWrite(led_rojo, LOW);

  //Serial.begin(115200);
}


void loop() {
  int d = ultrasonic.distanceRead();
  delay(10);

  //Serial.println(d);
  if (d < 80 && d > 0) {
    digitalWrite(led_verde, LOW);
    digitalWrite(led_rojo, HIGH);

    int freq = random (150, 350);     // random tone frequency
    tone(buzzer, freq);   // Send sound signal
    delay(10);            // for 10 ms
    noTone(buzzer);       // Stop sound
    if (d > 50) {
      delay(100 + d);
    }
    else {
      if (d > 30) {
        delay(30 + d);
      }
      else {
        delay(d);
      }
    }
    digitalWrite(led_rojo, LOW);
  }
  else {
    digitalWrite(led_verde, HIGH);
  }

}
