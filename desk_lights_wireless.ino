// to control the LEDs
#include <FastLED.h>
// to communicate via radio
#include <RF24.h>
#include <SPI.h>

//const int max_light_settings = 9;
const int max_leds = 75;
int displaytype = 1;

//for the radio
RF24 radio(9,10);
const byte address[6] = "24116";
int packet_recieved;



CRGB led[max_leds];
void color_selector(int packet_recieved){
  switch (packet_recieved){
      case 1:
        fill_solid(led, max_leds, CRGB(0,0,0));
        break;
      case 2:
        fill_solid(led, max_leds, CRGB::Red);
        break;
      case 3:
        fill_solid(led, max_leds, CRGB::Green);
          break;
        case 4:
          fill_solid(led, max_leds, CRGB::Blue);
          break;
      case 5:
        fill_solid(led, max_leds, CRGB(0,255,255));
          break;
      case 6:
        fill_solid(led, max_leds, CRGB(255,255,0));
        break;
      case 7:
      fill_solid(led, max_leds, CRGB(255,255,255));
        break;
      case 8:
      fill_solid(led,max_leds, CRGB(255, 0, 255));
        break;
      case 9:
      fill_rainbow(led,max_leds, 0, 3);
      break;

    }
}

void setup(void) {
  pinMode(6, INPUT_PULLUP);
  pinMode(7,INPUT_PULLUP);
  FastLED.addLeds<WS2812B, 5, GRB>(led, max_leds);
  FastLED.setBrightness(25);
  fill_solid(led, max_leds, CRGB::Red);
  //radio
	radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();

}

void loop(void) {

    if (radio.available()) {

      radio.read(&packet_recieved, sizeof(packet_recieved));
      Serial.println(packet_recieved);
      
      if (packet_recieved >= '1' && packet_recieved <= '9'){
        displaytype = packet_recieved - '0';
        color_selector(displaytype);
        FastLED.show();
        delay(100);
      }
    }
  }
