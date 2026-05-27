# Desk-Lights
## Review
### Rotary Encoder
This project used a rotary encoder to get an input from the user. I used this compared to other devices like a potentiometer because of the low amount of power needed, whereas a potentiometer needs a much higher amount of power, with a lot of it being wasted and transferred to heat.  
A rotary encoder also makes it just as easy to tell which direction it has been turned. If turned left, both the DT and CLK pins will have the same output (being 0 or 1, depending on what the last CLK output is, it will never be the same twice in a row). When turned right both pins will give a different output. This makes it simple to accurately tell which way the rotary encoder has been turned.  
Another benefit of using a rotary encoder is that it can also be pressed in and used as a second input. When pressed in the MS pin outputs 0, and when it is released it outputs 1. This can be used so that when a 0 is output we know the user wants to change the brightness, and thus change the brightness level, which is controlled via an array. This is a feature that a potentiometer could not provide without having a second input device. However, if it was added as a separate device to control brightness it would give the user much more freedom over how bright they would like the LEDs. Although the system would also be made much less power efficient.  
### External Power Supply
The whole project could not be powered via the Arduinos USB, because its 5V pin cannot supply enough head room for the project for it to be 100% reliable. Therefor the power source was changed to ensure that the project could work without power issues.



## Components
Arduino Nano  
LED strip(WS2812B)  
Rotary encoder  
5V Power supply (which can provide enough current)

## Wiring
For the connections from the Arduino Nano to the rotary encoder:  
D10 -- MS  
D7 -- DT  
D6 --CLK  

For the connections from the Arduino to the LED strip(WS2812B):  
D8 -- DIN

For the 5V power supply for each of the 3 components they should be connected to a 5V power source with surge protection. This is because the Arduino will have to be powered via its own 5V pin, which bypasses its own surge protection. The ground pin for each component should also be connected to the power supply's ground.

## Final Product
<img width="4032" height="2268" alt="1000006686" src="https://github.com/user-attachments/assets/51ea3b65-44b7-4ec6-8ab4-46b5eb11d699" />
