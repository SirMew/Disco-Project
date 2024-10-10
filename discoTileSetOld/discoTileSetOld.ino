#include "FastLED.h"
#include "discoNeon.h"

/* number if LEDS in a WS2811 strip = 10 
  number of Strips in build = 4 */
 
#define NUM_LEDS 40 
#define DATA_PIN 5

int colours[] = {1,2,3,4,5,6,7,8,9,10};
 
CRGB leds[NUM_LEDS];
 
void setup() {
    // sanity check delay - allows reprogramming if accidently blowing power w/leds
    delay(1000);
 
    FastLED.addLeds<WS2811, DATA_PIN, BRG>(leds, NUM_LEDS);
    //FastLED.setBrightness(CRGB(255,255,255));
}
 
void loop() {

int randomIndex = rand()%10;
int colourVal = colours[randomIndex];

// Tile 1
for(int i=0;i<10;i++){
 
    if (colourVal == 1){
      leds[i] = 0xB51D05;//orange
    }
 
    else if (colourVal == 2){
      leds[i] = 0xFFFF27;
    }
 
    else if (colourVal == 3){
      leds[i] = 0xFFDC40;//cyan
    }
 
    else if (colourVal == 4){
      leds[i] = 0x73FF37; //cyan
    }
 
    else if (colourVal == 5){
      leds[i] = 0x1D808B; //blue
    }
 
    else if (colourVal == 6){
      leds[i] = 0xFF0000; //neon pink
    }

    else if (colourVal == 7){
      leds[i] = 0x81217C; //purple
    }

    else if (colourVal == 8){
      leds[i] = 0x24AD2D; //green
    }

    else if (colourVal == 9){
      leds[i] = 0xE3092F; //hot neon pink
    }

    else if (colourVal == 10){
      leds[i] = 0xD13189; //purple
    }
  }
randomIndex = rand()%10;
colourVal = colours[randomIndex];
// Tile 2
for(int i=10;i<20;i++){
 
        if (colourVal == 1){
      leds[i] = 0xB51D05;
    }
 
    else if (colourVal == 2){
      leds[i] = 0xED7627;
    }
 
    else if (colourVal == 3){
      leds[i] = 0xFFDC40;
    }
 
    else if (colourVal == 4){
      leds[i] = 0x73BD37;
    }
 
    else if (colourVal == 5){
      leds[i] = 0x1D808B;
    }
 
    else if (colourVal == 6){
      leds[i] = 0xFC3756;
    }

    else if (colourVal == 7){
      leds[i] = 0x81217C;
    }

    else if (colourVal == 8){
      leds[i] = 0x24AD2D;
    }

    else if (colourVal == 9){
      leds[i] = 0xE3092F;
    }

    else if (colourVal == 10){
      leds[i] = 0xD13189;
    }
    
  }
randomIndex = rand()%10;
colourVal = colours[randomIndex];
// Tile 3
for(int i=20;i<30;i++){
 
        if (colourVal == 1){
      leds[i] = 0xB51D05;
    }
 
    else if (colourVal == 2){
      leds[i] = 0xED7627;
    }
 
    else if (colourVal == 3){
      leds[i] = 0xFFDC40;
    }
 
    else if (colourVal == 4){
      leds[i] = 0x73BD37;
    }
 
    else if (colourVal == 5){
      leds[i] = 0x1D808B;
    }
 
    else if (colourVal == 6){
      leds[i] = 0xFC3756;
    }

    else if (colourVal == 7){
      leds[i] = 0x81217C;
    }

    else if (colourVal == 8){
      leds[i] = 0x24AD2D;
    }

    else if (colourVal == 9){
      leds[i] = 0xE3092F;
    }

    else if (colourVal == 10){
      leds[i] = 0xD13189;
    }
  }
randomIndex = rand()%10;
colourVal = colours[randomIndex];
// Tile 4
for(int i=30;i<NUM_LEDS;i++){
 
        if (colourVal == 1){
      leds[i] = 0xB51D05;
    }
 
    else if (colourVal == 2){
      leds[i] = 0xED7627;
    }
 
    else if (colourVal == 3){
      leds[i] = 0xFFDC40;
    }
 
    else if (colourVal == 4){
      leds[i] = 0x73BD37;
    }
 
    else if (colourVal == 5){
      leds[i] = 0x1D808B;
    }
 
    else if (colourVal == 6){
      leds[i] = 0xFC3756;
    }

    else if (colourVal == 7){
      leds[i] = 0x81217C;
    }

    else if (colourVal == 8){
      leds[i] = 0x24AD2D;
    }

    else if (colourVal == 9){
      leds[i] = 0xE3092F;
    }

    else if (colourVal == 10){
      leds[i] = 0xD13189;
    }
    }
 
    FastLED.show();
    delay(1000);
}
