/*
* Arduino Wireless Communication Tutorial
*       Example 1 - Receiver Code
*                
* by Dejan Nedelkovski, www.HowToMechatronics.com
* 
* Library: TMRh20/RF24, https://github.com/tmrh20/RF24/
*/

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(7, 8); // CE, CSN

const int motorPin0 = 2;
const int motorPin1 = 3;
const byte address[6] = "00001";

void setup() {
  pinMode(motorPin0, OUTPUT);
  pinMode(motorPin1, OUTPUT);
  
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
}

void loop() {
  char text[32] = "";
  if (radio.available()) {
    radio.read(&text, sizeof(text));
    Serial.println(text);
    if (text[0]=='1'){
      digitalWrite(motorPin0, HIGH);
    } else {
      digitalWrite(motorPin0, LOW);
    }
    if (text[1]=='1'){
      digitalWrite(motorPin1, HIGH);
    } else {
      digitalWrite(motorPin1, LOW);
    }
  }
  
}
