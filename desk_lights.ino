#include <FastLED.h>

const int max_light_settings = 9;
const int max_leds = 75;
const int brightnesses[] = {25, 15, 5, 0};
int displaytype = 1;
int output1;
int saved_output1;
int output2;
int saved_output2;
int brightness_counter = 0;
int brightness_button;
int saved_brightness_button;
CRGB led[max_leds];
void color_selector(int displaytype){
  switch (displaytype){
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
  pinMode(10, INPUT_PULLUP);
  FastLED.addLeds<WS2812B, 8, GRB>(led, max_leds);
  FastLED.setBrightness(25);
}

void loop(void) {
  output1 = digitalRead(6);
  output2 = digitalRead(7);
  brightness_button = digitalRead(10);
  if (output1 != saved_output1){ //if the rotary encoder is moved right
    if (output1 != output2){
      displaytype ++;
      if (displaytype > max_light_settings){
        displaytype = 1;
      }
    }
    else if(output1 == output2){// if the rotary encoder is turned left
      displaytype --;
      if (displaytype < 1){
        displaytype = max_light_settings;
      }
    }
    color_selector(displaytype);

    FastLED.show();
  }
  if (saved_brightness_button != brightness_button){
    if (brightness_button == 0){
    brightness_counter ++;
    if (brightness_counter >= 4){
      brightness_counter = 0;
    }
    FastLED.setBrightness(brightnesses[brightness_counter]);
    FastLED.show();

  }}

  saved_output1 = output1;
  saved_output2 = output2;
  saved_brightness_button = brightness_button;

}
