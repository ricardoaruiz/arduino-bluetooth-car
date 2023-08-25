int setSpeed(int command) {
  if (command == '0') {
    speed = 0;
    return;
  }
  if (command == 'q') {
    speed = 255;
    return;
  }

  if (command >= 50 and command <= 57) {
    speed = map(command, 50, 57, 100, 240);
    return;
  }
}

void stop() {
  analogWrite(ENGINE_RIGHT_IN1, 0);
  analogWrite(ENGINE_RIGHT_IN2, 0);
  analogWrite(ENGINE_LEFT_IN3, 0);
  analogWrite(ENGINE_LEFT_IN4, 0);
}

void goForward() {
  analogWrite(ENGINE_RIGHT_IN1, speed);
  analogWrite(ENGINE_RIGHT_IN2, 0);
  analogWrite(ENGINE_LEFT_IN3, speed);
  analogWrite(ENGINE_LEFT_IN4, 0);
}

void goForwardLeft() {
  analogWrite(ENGINE_RIGHT_IN1, speed);
  analogWrite(ENGINE_RIGHT_IN2, 0);
  analogWrite(ENGINE_LEFT_IN3, speed / 2);
  analogWrite(ENGINE_LEFT_IN4, 0);
}

void goForwardRight() {
  analogWrite(ENGINE_RIGHT_IN1, speed / 2);
  analogWrite(ENGINE_RIGHT_IN2, 0);
  analogWrite(ENGINE_LEFT_IN3, speed);
  analogWrite(ENGINE_LEFT_IN4, 0);
}

void goBackward() {
  analogWrite(ENGINE_RIGHT_IN1, 0);
  analogWrite(ENGINE_RIGHT_IN2, speed);
  analogWrite(ENGINE_LEFT_IN3, 0);
  analogWrite(ENGINE_LEFT_IN4, speed);
}

void goBackwardLeft() {
  analogWrite(ENGINE_RIGHT_IN1, 0);
  analogWrite(ENGINE_RIGHT_IN2, speed);
  analogWrite(ENGINE_LEFT_IN3, 0);
  analogWrite(ENGINE_LEFT_IN4, speed / 2);
}

void goBackwardRight() {
  analogWrite(ENGINE_RIGHT_IN1, 0);
  analogWrite(ENGINE_RIGHT_IN2, speed / 2);
  analogWrite(ENGINE_LEFT_IN3, 0);
  analogWrite(ENGINE_LEFT_IN4, speed);
}

void goLeft() {
  analogWrite(ENGINE_RIGHT_IN1, speed);
  analogWrite(ENGINE_RIGHT_IN2, 0);
  analogWrite(ENGINE_LEFT_IN3, 0);
  analogWrite(ENGINE_LEFT_IN4, 0);
}

void goRight() {
  analogWrite(ENGINE_RIGHT_IN1, 0);
  analogWrite(ENGINE_RIGHT_IN2, 0);
  analogWrite(ENGINE_LEFT_IN3, speed);
  analogWrite(ENGINE_LEFT_IN4, 0);
}