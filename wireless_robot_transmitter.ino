/*
* Arduino Wireless Communication Tutorial
*     Example 1 - Transmitter Code
*                
* by Dejan Nedelkovski, www.HowToMechatronics.com
* 
* Library: TMRh20/RF24, https://github.com/tmrh20/RF24/
*/

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(7, 8); // CE, CSN

const int leftButtonPin = 2;
const int rightButtonPin = 3;

int leftButtonState = 0;
int rightButtonState = 0;
char text[2] ;
const byte address[6] = "00001";

void setup() {
  //for debug
  Serial.begin(9600);
  //internal pullup for input pins
  pinMode(leftButtonPin, INPUT_PULLUP);
  pinMode(rightButtonPin, INPUT_PULLUP);
  
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_HIGH);
  radio.stopListening();
}

void loop() {
  //const char text[] = "Hello World";
  leftButtonState = digitalRead(leftButtonPin);
  rightButtonState = digitalRead(rightButtonPin);
  if (leftButtonState==HIGH){
    text[0] = '1';
  } else {
    text[0] = '0';
  }
  if (rightButtonState==HIGH){
    text[1] = '1';
  } else {
    text[1] = '0';
  }
  radio.write(&text, sizeof(text));
  delay(50);
}
