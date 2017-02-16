
#include "pitches.h"

const int analogInPin = A0;
const int buzzerPin = 8;
const int ledPin = 7;
int sensorValue = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  // LED
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  sensorValue = analogRead(analogInPin);
  Serial.print("Sensor value: ");
  Serial.println(sensorValue);
  
  if (sensorValue < 1000) {
    
    playAlarmSound();
  } else {
    // Set LED off
    digitalWrite(ledPin, LOW);
  }
}

void playAlarmSound() {
  
  digitalWrite(ledPin, HIGH);
  
  for (int frequency = 500; frequency < 700; frequency++) {
//    noTone(buzzerPin);
    tone(buzzerPin, frequency);
    delay(3);
  }
  
  noTone(buzzerPin);

}
