// Receiver Example Code for 433 MHz Robot with L298 Motor Driver
// 08.27.2023

#include <RH_ASK.h>
#include <SPI.h>  // Not actualy used but needed to compile

RH_ASK driver;

// connect L298 Driver to Arduino pins
int motorIN1 = 4;  // motor 1 direction
int motorIN2 = 5;  // motor 1 direction
int motorIN3 = 6;  // motor 2 direction
int motorIN4 = 7;  // motor 2 direction

void setup() {
  Serial.begin(9600);  // Debugging only
  if (!driver.init())
    Serial.println("init failed");
  pinMode(motorIN1, OUTPUT);  // Motor A
  pinMode(motorIN2, OUTPUT);  // Motor A
  pinMode(motorIN3, OUTPUT);  // Motor B
  pinMode(motorIN4, OUTPUT);  // Motor B
}

void loop() {
  uint8_t buf[12];
  uint8_t buflen = 1;
  char inData;
  if (driver.recv(buf, &buflen))  // Non-blocking
  {
    inData = (char)buf[0];
    // Message with a good checksum received, dump it.
    Serial.print("Message: ");
    Serial.println((char*)buf);
    if (inData == 'd') {
      Serial.println("Reverse!");
      // motor 1 CCW
      digitalWrite(motorIN1, LOW);
      digitalWrite(motorIN2, HIGH);
      // motor 2 CW
      digitalWrite(motorIN3, HIGH);
      digitalWrite(motorIN4, LOW);
    } else if (inData == 'u') {
      Serial.println("Forward!");
      // motor 1 CW
      digitalWrite(motorIN1, HIGH);
      digitalWrite(motorIN2, LOW);
      // motor 2 CCW
      digitalWrite(motorIN3, LOW);
      digitalWrite(motorIN4, HIGH);
    } else if (inData == 'l') {
      // Turn Left
      Serial.println("Left!");
      // motor 1 CW
      digitalWrite(motorIN1, HIGH);
      digitalWrite(motorIN2, LOW);
      // motor 2 CW
      digitalWrite(motorIN3, HIGH);
      digitalWrite(motorIN4, LOW);
    } else if (inData == 'r') {
      // Turn right
      Serial.println("Right!");
      // motor 1 CCW
      digitalWrite(motorIN1, LOW);
      digitalWrite(motorIN2, HIGH);
      // motor 2 CCW
      digitalWrite(motorIN3, LOW);
      digitalWrite(motorIN4, HIGH);
    }
  }
}