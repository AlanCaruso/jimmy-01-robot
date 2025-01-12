#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"

Adafruit_MotorShield AFMS = Adafruit_MotorShield();

Adafruit_DCMotor *motor1 = AFMS.getMotor(1);
Adafruit_DCMotor *motor2 = AFMS.getMotor(2);

void setup() {
  if(!AFMS.begin()){
    Serial.println("Shield Motor not found.");
    while(true);
  }
  motor1->setSpeed(200);
  motor2->setSpeed(200);

  motor1->run(RELEASE);
  motor2->run(RELEASE);

}

void loop() {
  motor1->run(FORWARD);
  motor2->run(FORWARD);
  delay(2000);

  motor1->run(RELEASE);
  motor2->run(RELEASE);
  delay(1000);

  motor1->run(BACKWARD);
  motor2->run(BACKWARD);
  delay(2000);

  motor1->run(RELEASE);
  motor2->run(RELEASE);
  delay(1000);

}
