/*
  Copyright 2018 Those Ltd.
  GNU General Public License
*/

#ifndef JOTO_H_INCLUDED
#define JOTO_H_INCLUDED


class Joto
{
public:

    #define CHIRP_INTERVAL 2000   //ms
    #define CHIRP_POS 145         //M106
   
    #define JOTO_LED_PIN 12       //LED
    #define LED_STATE 57     //ESP IO22 led on off pin mirroring
    #define ESP_SIGNAL 43    //ESP IO2 gains control of led once on
    #define BUTTON_EVENT 0   //BUTTON
    #define BUTTON_PIN 55    //ESP IO16
    
    #define HEARTBEAT_PIN 73            //HEARTBEAT //ESP IO17 73 //ESP35 PIN23 //IO20 PIN56  //IO27 PIN42
    #define HEARTBEAT_INTERVAL 1000     // interval at which to blink (milliseconds)

    static void setup();
    static void loop();
    static void buttonSetup();
    static void buttonloop();
    static void buttonHeld();
    static void ledloop();
    static void heartbeat();
    static void buttonHeldFunction();
    static void restartESP();
    static void chirp();
};

#endif // JOTO_H_INCLUDED
