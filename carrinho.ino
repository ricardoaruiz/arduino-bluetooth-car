#include "SoftwareSerial.h"

#define ENGINE_RIGHT_IN1 5
#define ENGINE_RIGHT_IN2 6
#define ENGINE_LEFT_IN3 9
#define ENGINE_LEFT_IN4 10

#define BUZZER 12

SoftwareSerial bluetooth(2, 3);  // pinos utilizados pelo TX e RX do módulo Bluetooth

int bluetoothReceivedData;
unsigned long lastReceivedData = 0;
int speed = 255;

void setup() {
  bluetooth.begin(9600);

  pinMode(ENGINE_RIGHT_IN1, OUTPUT);
  pinMode(ENGINE_RIGHT_IN2, OUTPUT);
  pinMode(ENGINE_LEFT_IN3, OUTPUT);
  pinMode(ENGINE_LEFT_IN4, OUTPUT);
  pinMode(BUZZER, OUTPUT);
}

void loop() {
  if (bluetooth.available()) {
    bluetoothReceivedData = bluetooth.read();

    lastReceivedData = millis();

    setSpeed(bluetoothReceivedData);

    switch (bluetoothReceivedData) {
      case 'F':
        goForward();
        break;
      case 'B':
        goBackward();
        break;
      case 'L':
        goLeft();
        break;
      case 'R':
        goRight();
        break;
      case 'G':
        goForwardLeft();
        break;
      case 'I':
        goForwardRight();
        break;
      case 'H':
        goBackwardLeft();
        break;
      case 'J':
        goBackwardRight();
        break;
      case 'S':
        stop();
        break;
      case 'V':
        tone(BUZZER, 500);
        break;
      case 'v':
        noTone(BUZZER);
        break;
    }
  } else {
    if ((millis() - lastReceivedData) > 500) {
      stop();
    }
  }
}
