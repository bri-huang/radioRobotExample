# radioRobotExample
Arduino examples using the Radiohead library and the 433 MHz Tx / Rx modules

## radio_tx.ino - Transmit code example
* Connect 433 MHz transmit module data to pin 12
* Connect Joystick Potentiometer to pins A0 (X) and A1 (Y)

## radio_rx.ino - Receive code example
* Connect 433 MHz receive module data to pin 11
* Connect L298 Motor Driver:
  * IN1 -> pin 4 (motor 1 direction)
  * IN2 -> pin 5 (motor 1 direction)
  * IN3 -> pin 6 (motor 2 direction)
  * IN4 -> pin 7 (motor 2 direction)
