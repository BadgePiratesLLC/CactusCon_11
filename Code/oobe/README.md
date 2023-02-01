# CactusCon information
WiFi SSID: cactus-badge
WiFi PW: 313v3nC4ct1 (ElevenCacti in leetspeak)
OTA Server: http://discord.gr/cc11discord/updates (BadgePirates OTA server, contact @J19Bush on Twitter to upload binaries or change it to your own HTTP server.)

Out of box experience will show all LEDS on boot, then change the colors on the WS2812B to indicate the button state
Click the boot button to initialize OTA mode

# OTA LED Codes
| Left   	| Right  	| Reason                                         	|
|--------	|--------	|------------------------------------------------	|
|        	| Green  	| OTA Started - WiFi Scanning                    	|
| Green  	| Green  	| WiFi connected                                 	|
| Green  	| Yellow 	| Update manifest downloaded - Loading firmware  	|
| Yellow 	| Yellow 	| Update downloading                             	|
| Red    	| Yellow 	| WiFi scan failed/Connection Failed             	|
| Red    	| Red    	| Firmware Download failed but WiFi connected OK 	|
| Blue   	| Blue   	| Firmware is latest version                     	|
|        	|        	|                                                	|

# Moving to using this code for production
First off, don't remove any of the factory code, while it mainly serves as debugging it also stands as a boilerplate for our badges and it facilitates testing and production. 

You can write all of your code after the IFDEF for the factory mode, make sure to disable it in `config.hpp`!

When you are ready to upload changes, make sure to change the version number in the config file and upload a bin. 

# BadgePirates Base
This project serves as a boilerplate for badgepirates code, it is designed to facilitate rapid developement and production of badges.

When you are creating a new badge, clone this repo, delete the .git folder and copy it into a badge project. 

Configure `prototype.cpp/hpp` to add code to drive hardware necessary to perform a functional test of components, and set up OTA information in `config.hpp`.

Create a binary and save it to be used later during initial flashing. Flash it with esptool.

Start development on the project and remove the test code, change the version in `config.hpp` to `1` and code as you wish. 

When you are ready to make production binaries, made sure debug mode is off and compile, compile and save.

For an OTA server, run an HTTP server with two files, `version` and `binary` (can change in config), the version file will be a number represending `VERSION` in `config.hpp` and binary will be the .bin file without the extension. (E.g. binary is just binary, not binary.bin)

## Capabilities

* In-production automatic hardware testing and WiFi flashing
* OTA
