// Wireless Joystick Example Code for 433 MHz Robot with Joystick Control
// 08.27.2023

#include <RH_ASK.h>
#include <SPI.h>  // Not actually used but needed to compile

RH_ASK driver;

// connect Joystick x and y to analog channels A0 and A1

int vx = A0;
int vy = A1;
int buttonPin = 2;
int xdata, ydata, buttondata = 0;
String message = "";

void setup() {
  Serial.begin(9600);  // Debugging only
  if (!driver.init())
    Serial.println("init failed");
  pinMode(13, OUTPUT);
}

void loop() {
  buttondata = digitalRead(buttonPin);
  xdata = analogRead(vx);
  ydata = analogRead(vy);
  //Serial.println(xdata);
  //Serial.println(ydata);
  if (ydata > 700) {
    driver.send((uint8_t *) "u", 1);
    driver.waitPacketSent();
  }
  else if (ydata < 500) {
    driver.send((uint8_t *) "d", 1);
    driver.waitPacketSent();
  }
  else if (xdata > 700) {
    driver.send((uint8_t *) "r", 1);
    driver.waitPacketSent();
  }
  else if (xdata < 500) {
    driver.send((uint8_t *) "l", 1);
    driver.waitPacketSent();
  }

  //SendData(xdata, ydata, buttondata);
  digitalWrite(13, LOW);
  delay(100);
}