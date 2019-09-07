# Repetier-Firmware - the fast and user friendly firmware

## Notes for developers/pull requests

This software is open source licensed under the GPL V3. Please see gpl.txt

### WARRANTY
WARNING: Please note that Those Ltd. cannot be held responsible for any damage done to your Joto device if you modify or upload a custom version of this firmware. 
This firmware is provided 'as is' with no warranty. Modified firmware can harm your Joto. Use at your own risk.

<!-- 
### Version 1.0 information

Version 2 will be a incompatible refactoring of version 1.0. We will try to keep
commands and communication identical to 1.0, but for the configuration we see
a much more flexible way that makes it much easier to adjust the firmware to
nowadays needs. But that requires a different configuration at several parts.

Planned stages:
1. Merge AVR and Due into one fileset.
2. Split long files like boards, displays, languages in several files into a subfolder.
    That way it gets much faster to search the right place.
3. Update used libraries.
4. Change configuration.
5. Change motion planner.
6. Create a config tool.
7. Public testing with more users. We assume until a config tool is available the configuration
will get several changes and only users with programming skills will do it manually
to benefit already from improvements achieved.

Until 6. the version should be considered alpha stage. We do expect errors from all
the changes and there may be bigger mods with an update. Of course we will try
to keep every release workable, but as work in progress there is no guarantee. 

## Installation
                               
Please use your configuration tool at 
[http://www.repetier.com/firmware/v100](http://www.repetier.com/firmware/v100)
or for latest 1.0.x development version at
[http://www.repetier.com/firmware/dev](http://www.repetier.com/firmware/dev)
for easy and fast configuration. You get the complete sources you need to compile from the online configurator.
This system also allows it to upload configurations created with this tool and modify the configuration. This is handy for updates as you get all newly introduced parameter just by uploading the old version and downloading the
latest version. New parameter are initalized with default values.

## Version 1.0.0
* Fixed many autoleveling bugs.
* More supported boards and displays.
* Added CNC/Laser modes.
* Improved event system to extend firmware without modification of files.
* Dual X axis support (2 separate x axis)
* New gcode handler for more flexible support of different inputs.
* Improved menu.
* Jam detection.
* More stable temperature control with PID.
* Per axis homing flag.
* Keep alive signals for hosts.
* Support capabilities protocol.
* Many bug fixes.

## Version 0.92.8 
* Cleaner code base.
* Pulse dense modulation for heater and fans.
* Bed bump correction for delta printer.
* Correction of parallelogram distortions.
* Decoupling test for heater and sensor for more safety.
* Mixing extruder support.
* Test for watchdog.
* Allow cold extrusion.
* Fixed pause sd print issues.
* Commands on sd stop.
* Disable heaters/extruders on sd stop.
* Safety question for sd stop.
* Many minor corrections and improvements.
* Extra motor drivers.
* Event system for lights etc.
* New homing sequence with preheat for nozzle based z sensors.
* Language selectable on runtime.
* Fix structure for Arduino 1.6.7
* New bed leveling.
* Fatal error handling added.

## Version 0.91 released 2013-12-30

WARNING: This version only compiles with older Arduino IDE 1.0.x, for
compilation with newest version use 0.92

Improvements over old code:
* Better readable code.
* Long filename support (from Glenn Kreisel).
* Animated menu changes.
* Separation of logic and hardware access to allow different processor architectures
  by changing the hardware related files.
* z-leveling support.
* Mirroring of x,y and z motor.
* Ditto printing.
* Faster and better delta printing.
* New heat manager (dead time control).
* Removed OPS handling.
* Full graphic display support.
* Many bug fixes.
* many other changes.

## Documentation

For documentation please visit [http://www.repetier.com/documentation/repetier-firmware/](http://www.repetier.com/documentation/repetier-firmware/)

## Developer

The sources are managed by the Hot-World GmbH & Co. KG
It was initially based on the Sprinter firmware from Kliment, but the code has run
through many changes since them.
Other developers:
- Glenn Kreisel (long filename support)
- Martin Croome (first delta implementation)
- John Silvia (Arduino Due port)
- sdavi (first u8glib code implementation)
- plus several small contributions from other users.

## Introduction

Repetier-Firmware is a firmware for RepRap like 3d-printer powered with
an arduino compatible controller.
This firmware is a nearly complete rewrite of the sprinter firmware by kliment
which based on Tonokip RepRap firmware rewrite based off of Hydra-mmm firmware.
Some ideas were also taken from Teacup, Grbl and Marlin.

## Controlling firmware

Also you can control the firmware with any reprap compatible host, you will only get
the full benefits with the following products, which have special code for this
firmware:

* [Repetier-Host for Windows/Linux](http://www.repetier.com/download/)
* [Repetier-Host for Mac](http://www.repetier.com/download/)
* [Repetier-Server](http://www.repetier.com/repetier-server-download/)

## Installation

For documentation and installation please visit 
[http://www.repetier.com/documentation/repetier-firmware/](http://www.repetier.com/documentation/repetier-firmware/).

## Changelog

See changelog.txt -->
