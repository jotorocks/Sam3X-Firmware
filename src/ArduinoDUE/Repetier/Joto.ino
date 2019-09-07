/*
  Copyright 2018 Those Ltd.
  GNU General Public License
*/

/*
    This file is part of Repetier-Firmware.
    Repetier-Firmware is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.
    Repetier-Firmware is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
    You should have received a copy of the GNU General Public License
    along with Repetier-Firmware.  If not, see <http://www.gnu.org/licenses/>.
    This firmware is a nearly complete rewrite of the sprinter firmware
    by kliment (https://github.com/kliment/Sprinter)
    which based on Tonokip RepRap firmware rewrite based off of Hydra-mmm firmware.
    Main author: repetier
*/

#include "Repetier.h"
#include <SPI.h>

//USB PD LIBRARY
#include <SimplyAtomic.h>
#define CONFIG_USB_PD_DUAL_ROLE
#define CONFIG_USB_PD_PULLUP TYPEC_RP_1A5
#include "FUSB302.h"
#include "USB_PD.h"RF
#include <Wire.h>
extern TwoWire Wire1;
bool executed = false;


#if UI_DISPLAY_TYPE == DISPLAY_ARDUINO_LIB
#endif

void setup()
{       
    Joto::setup();
    PDsetup();
    Printer::setup();
}

void loop()
{   
    if(!executed){
      PDloop();
    }else{
      Commands::commandLoop();
    }
}

timestamp_t get_time() {
  timestamp_t t;
  ATOMIC() {
    t.val = (1000*millis()) + (micros()%1000);
  }
  return t;
}




