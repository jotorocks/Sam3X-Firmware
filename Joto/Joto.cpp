/*
  Copyright 2018 Those Ltd.
  GNU General Public License
*/

#include "Repetier.h"

//BUTON HOLD FUNCTION
static unsigned long lastRefreshTime = 0;
int previousState = LOW;
int beatState = LOW;             // ledState used to set the LED
long previousMillis = 0;        // will store last time LED was updated

void Joto::setup(){
    digitalWrite(59, LOW); 
    pinMode(11, OUTPUT);       // DC STEP
    pinMode(15, OUTPUT);       // DC STEP
    digitalWrite(11, LOW);     // DC STEP
    digitalWrite(15, LOW);     // DC STEP
    analogWrite(DAC0, 0);      // TMC DAC
    analogWrite(DAC1, 0);      // TMC DAC
    pinMode(ESP_SIGNAL, INPUT);        // HEARTBEAT PIN
    pinMode(JOTO_LED_PIN, OUTPUT);       // LED PIN
    pinMode(LED_STATE, INPUT);        // HEARTBEAT PIN
    pinMode(HEARTBEAT_PIN, OUTPUT);        // HEARTBEAT PIN
    pinMode(BUTTON_PIN, OUTPUT);       // BUTTON PIN
    digitalWrite(JOTO_LED_PIN, HIGH);       // LED PIN
    Joto::buttonSetup();
}


void Joto::loop(){
      analogWrite(DAC0, 128);
      analogWrite(DAC1, 128);
      Joto::buttonloop();
      Joto::ledloop();
      Joto::heartbeat();
}


void Joto::buttonSetup(){
  PMC->PMC_PCER0 = PMC_PCER0_PID12;
  PIOB->PIO_PER = PIO_PB10;
  PIOB->PIO_ODR = PIO_PB10;
  PIOB->PIO_PUDR = PIO_PB10;
}

void Joto::buttonloop(){
 //IO16 ESP32
  if ((PIOB->PIO_PDSR & PIO_PB10) == PIO_PB10){
    digitalWrite(BUTTON_PIN, LOW);
    previousState = LOW;
  }
  else{
    if(previousState == LOW){
       lastRefreshTime = millis();
       previousState = HIGH;
    }
    Joto::buttonHeldFunction();
    digitalWrite(BUTTON_PIN, HIGH);
  }
}

void Joto::buttonHeldFunction()
{
  if(millis() - lastRefreshTime >= CHIRP_INTERVAL )
  {
    lastRefreshTime += CHIRP_INTERVAL;
    Joto::chirp();
  }
}

void Joto::ledloop() {
 if(digitalRead(ESP_SIGNAL) == LOW){
    if(digitalRead(LED_STATE) == HIGH){
    digitalWrite(JOTO_LED_PIN, HIGH);
   }else{
    digitalWrite(JOTO_LED_PIN, LOW);
   }
 }else{
  digitalWrite(JOTO_LED_PIN, HIGH);
 }
}

void Joto::heartbeat(){
   unsigned long currentMillis = millis();
   if(currentMillis - previousMillis > HEARTBEAT_INTERVAL) {
    previousMillis = currentMillis;   
    if (beatState == LOW){
      beatState = HIGH;
    }
    else{
      beatState = LOW;
    }
    digitalWrite(HEARTBEAT_PIN, beatState);
  }
}

void  Joto::chirp(){
  int servoPos = Printer::fanSpeed;
  if(servoPos == 0){
    servoPos = CHIRP_POS;
  }
  Printer::setFanSpeedDirectly(servoPos);
  delay(200);
  Printer::setFanSpeedDirectly(servoPos-20);
  delay(200);
  Printer::setFanSpeedDirectly(servoPos);
  delay(200);
  Printer::setFanSpeedDirectly(servoPos-20);
  delay(200);
  Printer::setFanSpeedDirectly(servoPos);
  Printer::setFanSpeedDirectly(0);
}

void Joto::restartESP(){
  //ESP - EN
  pinMode(59, OUTPUT);
  digitalWrite(12, LOW);
  digitalWrite(59, LOW); 
  delay(500); 
  digitalWrite(59, HIGH);  
  digitalWrite(12, HIGH); 
}
