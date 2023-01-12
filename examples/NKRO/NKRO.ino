#include "NKeyboard.h"

void setup()
{
  // open the serial port:
  Serial.begin(9600);
  // initialize control over the keyboard:

  Keyboard.begin();
  pinMode(0, INPUT_PULLUP);
}
void loop()
{
  char SendChar = 33;

  // check for incoming serial data:
  if (!digitalRead(0))
  {
    for (int i = 0; i < 96 - 32; i++)
    {
      Keyboard.press(SendChar);
      SendChar++;
    }
  }
  else
  {
    Keyboard.releaseAll();
  }
}