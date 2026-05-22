# Desk-Lights

For the connections from the Arduino Nano to the rotary encoder:
5V -- +
GND -- GND
D10 -- MS
D7 -- DT
D6 --CLK

For the conections from the Arduino to the light strip(WS2812B):
D8 -- DIN
GND -- GND
5V -- +5V 
however with more LEDs than this test a different power supply would be needed, thus the +5V and GND may be differnt.






DISCLAIMER: This is still a work in progress and has only been tested with 6 LEDs. For testing with more LEDs a greater power supply will be connected to the LEDs 5V pin, as the Arduino Nano cannot supply enough power. The Variable "max_leds" will also have to be changed to mirror the final amount of LEDs.
