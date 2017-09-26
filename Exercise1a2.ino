/************************************************************************/
/* @Authors: DIEGO SANZ VILLAFRUELA && MARKUS DRUFVA                    */
/* @Date: 9.14.2017                                                     */
/*                                                                      */
/* GNU General Public License                                           */
/* Test Git								*/
/************************************************************************/

#include <Arduino.h>

void blinkLed(const unsigned int code[],int lenght, int pin);

const int ledPin = 13;
/* SOS code */
unsigned int morseCode[] = { 1000,1000,1000,1000,1000, /* S */ 3000,
                  3000,1000,3000,1000,3000, /* O */ 3000 ,  
                  1000,1000,1000,1000,1000, /* S */ 3000};  
                    
const short int sizeMorse = 18;

void setup() {
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  delay(500);
}

void loop() {
  blinkLed(morseCode,sizeMorse,ledPin);
}

void blinkLed(const unsigned int code[],int lenght, int pin){
  int currentStateLed = LOW;
  for ( short int counter = 0; counter < lenght; counter++){
    // change the state
    if (currentStateLed == HIGH)
      currentStateLed = LOW;
    else
      currentStateLed = HIGH;
    digitalWrite(pin, currentStateLed);
    delay(code[counter]);
  }
}
