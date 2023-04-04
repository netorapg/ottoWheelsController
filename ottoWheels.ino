#include <Servo.h>
#include <SoftwareSerial.h>

SoftwareSerial HC05(11, 12);

Servo meuServo1;
Servo meuServo2;


int state = 0;
int state2 = 0;
int state3 = 0;

void setup(){
Serial.begin(9600);
HC05.begin(9600);
meuServo1.attach(2);
meuServo2.attach(3);
}

void loop(){
 if (HC05.available() > 0) {
    char data = HC05.read();
    executeAction(data);
  }
}

void executeAction(char action) {
  switch (action) {
    case 'f':
      state = !state;
      moveForward();
      break;
    case 'b':
      state2 = !state2;
      moveBackward();
      break;
  }

}

void moveForward() {
  for (int i = 1500; i < 2500; i++) {
    meuServo1.writeMicroseconds(400 - i);
    meuServo2.writeMicroseconds(400 + i);
    break;
  }
  
}

void moveBackward(){
  for (int i = 2500; i > 1500; i--) {
    meuServo1.writeMicroseconds(400 + i);
    meuServo2.writeMicroseconds(i - 400);
    break;
  }
}