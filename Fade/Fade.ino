//Programmer: Lauren Dunning
//Date 3.14.2023
//Program: Fade

/*
  Fade

  This example shows how to fade an LED on pin 9 using the analogWrite()
  function.

  The analogWrite() function uses PWM, so if you want to change the pin you're
  using, be sure to use another PWM capable pin. On most Arduino, the PWM pins
  are identified with a "~" sign, like ~3, ~5, ~6, ~9, ~10 and ~11.

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/Fade
*/

int ledTen = 10;       // Pin 10 utilizing PWM
int ledEleven = 11;    // Pin 11 utilizing PWM
int brightness = 0;    // how bright the LED is
int fadeAmount = 5;    // how many points to fade the LED by

// the setup routine runs once when you press reset:
void setup() {
  // declare pin 10 and 11 to be an output:
  pinMode(ledTen, OUTPUT);
  pinMode(ledEleven, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  // set the brightness of pin 10 and 11:
  analogWrite(ledTen, brightness);
  analogWrite(ledEleven, brightness);

  // change the brightness for next time through the loop:
  brightness = brightness + fadeAmount;

  // reverse the direction of the fading at the ends of the fade:
  if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount;
  }
  // wait for 30 milliseconds to see the dimming effect
  delay(30);
}
