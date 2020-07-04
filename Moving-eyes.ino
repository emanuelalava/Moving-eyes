#include <Servo.h>

Servo servo;
const int PIN_SERVO = 11;
const int SERIAL_BAUD = 9600;
const int DELAY = 25;
void setup() {
  Serial.begin(SERIAL_BAUD);
  servo.attach(PIN_SERVO);
  servo.write(90);
  delay(2000);
}

void loop() {
  String command = Serial.readString();// s1 is String type variable.
  Serial.print(command.indexOf("MOVER") >= 0);
  Serial.print("Received Data => ");
  Serial.println(command);
  if (command.indexOf("UP") >= 0) {
    Serial.println("Moving...");
    Up(servo);
  }
  if (command.indexOf("DOWN") >= 0) {
    Serial.println("Moving...");
    Down(servo);
  }
  if (command.indexOf("CENTER") >= 0) {
    Serial.println("Moving...");
    Center(servo);
  }
//  delay(100);
}


void Down(Servo servoMotor) {
  int posActual = servoMotor.read();
  for (int i = posActual; i < 135; i++) {
    if ((servoMotor.read() >= 0) && (servoMotor.read() <= 180)) {
      servoMotor.write(i);
    }
    delay(DELAY);
  }
  Serial.print("END OF DOWN");
}

void Up(Servo servoMotor) {
  int posActual = servoMotor.read();
  for (int i = posActual; i > 45; i--) {
    if ((servoMotor.read() >= 0) && (servoMotor.read() <= 180)) {
      servoMotor.write(i);
    }
    delay(DELAY);
  }
  Serial.print("END OF UP");

}


void Center(Servo servoMotor) {
  int posActual = servoMotor.read();
  Serial.print("Center");
  Serial.print(posActual);
  if (posActual > 90) {

    for (int i = posActual; i > 90; i--) {
      if ((servoMotor.read() >= 0) && (servoMotor.read() <= 180)) {
        servoMotor.write(i);
      }
      delay(DELAY);
    }
  } else {
    for (int i = posActual; i < 90; i++) {
      if ((servoMotor.read() >= 0) && (servoMotor.read() <= 180)) {
        servoMotor.write(i);
      }
      delay(DELAY);
    }
  }
  Serial.print("END OF CENTER");

}
