#include "FastLED.h"

/* number if LEDS in a WS2811 strip = 10 
  number of Strips in build = 4 */
 
#define NUM_LEDS 40 
#define DATA_PIN 5
#define NUM_TILES 4
#define MODE 1

//Function prototypes
void discoNeon(int ledNum, int tileNum);
void synthwave(int ledNum, int tileNum);
void electroswing(int ledNum, int tileNum);
void darksynth(int ledNum, int tileNum);
void startTest(int ledNum, int tileNum);
 
CRGB leds[NUM_LEDS];
void setup() {
    // sanity check delay - allows reprogramming if accidently blowing power w/leds
    delay(1000);
    FastLED.addLeds<WS2811, DATA_PIN, BRG>(leds, NUM_LEDS);//.setCorrection(ClearBlueSky);
    //FastLED.setBrightness(CRGB(255,255,255));

    // start test - loop through red, green, blue
    startTest(NUM_LEDS, NUM_TILES);
    

}
 
void loop() {

  if (MODE == 1){
    discoNeon(NUM_LEDS, NUM_TILES);
  }
  else if(MODE == 2){
    synthwave(NUM_LEDS, NUM_TILES);
  }
  else if(MODE == 3){
    electroswing(NUM_LEDS, NUM_TILES);
  }
  else if(MODE == 4){
    darksynth(NUM_LEDS, NUM_TILES);
  }
  else{
    discoNeon(NUM_LEDS, NUM_TILES);
    }
  //delay(500);
}
