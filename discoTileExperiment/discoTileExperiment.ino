#include <FastLED.h>
#define NUM_LEDS 10
#define DATA_PIN 5

CRGBArray<NUM_LEDS> leds; //memory block

void setup() 
{ 
  FastLED.addLeds<WS2811,DATA_PIN>(leds, NUM_LEDS); 
}

void loop(){ 
        for(int dot = 0; dot < NUM_LEDS; dot++) { 
            leds[dot] = CRGB::Red;

            FastLED.show();
            // clear this led for the next time around the loop
            leds[dot] = CRGB::Black;
            FastLED.show();
            
            delay(500);
        }
}
