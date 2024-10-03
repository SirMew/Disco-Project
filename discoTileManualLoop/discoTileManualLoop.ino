#include "FastLED.h"

/* number if LEDS in a WS2811 strip = 10 
  number of Strips in build = 4 */

#define NUM_LEDS 40 
#define NUM_TILES 4
#define DATA_PIN 5

int colours[] = {1,2,3,4,5,6};

CRGB leds[NUM_LEDS];

void setup() {
    // sanity check delay - allows reprogramming if accidently blowing power w/leds
    delay(500);

    FastLED.addLeds<WS2811, DATA_PIN, BRG>(leds, NUM_LEDS);
    //FastLED.setBrightness(CRGB(255,255,255));
}

void loop() {

for(int j =0;j<NUM_TILES;j++){
    int colourVal = randTileColour();
  // Tile 1
  for(int i=(j*10);i<(j*10)+10;i++){

      if (colourVal == 1){
        leds[i] = CRGB(255,0,0); //RED
      }

      else if (colourVal == 2){
        leds[i] = CRGB(0,255,0); //GREEN
      }

      else if (colourVal == 3){
        leds[i] = CRGB(0,0,255); //BLUE
      }

      else if (colourVal == 4){
        leds[i] = CRGB(255,128,0); //YELLOW
      }

      else if (colourVal == 5){
        leds[i] = CRGB(255,50,0); //ORANGE
      }

      else if (colourVal == 6){
        leds[i] = CRGB(128,0,128); //PURPLE
      }
    }
}

    FastLED.show();
    delay(1000);
}

int randTileColour(){
  int colour;
  int colours[] = {1,2,3,4,5,6};
  int randomIndex = rand()%6;
  colour = colours[randomIndex];
  return colour;
}
