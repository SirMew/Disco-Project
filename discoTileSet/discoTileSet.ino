#include "FastLED.h"

/* number if LEDS in a WS2811 strip = 10 
  number of Strips in build = 4 */
 
#define NUM_LEDS 40 
#define DATA_PIN 5
#define NUM_TILES 4
#define MODE_UP 2
#define MODE_DOWN 3

//Function prototypes
void discoNeon(int ledNum, int tileNum);
void synthwave(int ledNum, int tileNum);
void electroswing(int ledNum, int tileNum);
void darksynth(int ledNum, int tileNum);
void startTest(int ledNum, int tileNum);

volatile byte buttonUpReleased = false;
volatile byte buttonDownReleased = false;
int mode = 1;

//Mode button functions
void buttonUpReleasedInterrupt(){
  buttonUpReleased = true;
}
void buttonDownReleasedInterrupt(){
  buttonDownReleased = true;
}
 
CRGB leds[NUM_LEDS];

void setup() {

  //add pin 2 interrupt 
  pinMode(MODE_UP, INPUT);
  attachInterrupt(digitalPinToInterrupt(MODE_UP), buttonUpReleasedInterrupt, FALLING);

  //add pin 3 interrupt 
  pinMode(MODE_DOWN, INPUT);
  attachInterrupt(digitalPinToInterrupt(MODE_DOWN), buttonDownReleasedInterrupt, FALLING);

  // sanity check delay - allows reprogramming if accidently blowing power w/leds
  delay(1000);
  FastLED.addLeds<WS2811, DATA_PIN, BRG>(leds, NUM_LEDS);//.setCorrection(ClearBlueSky);
  //FastLED.setBrightness(CRGB(255,255,255));

  // start test - loop through red, green, blue
  startTest(NUM_LEDS, NUM_TILES);
    

}
 
void loop() {

  if (buttonUpReleased){
    buttonUpReleased = false;
    if(mode < 4){ //check that mode is within define int range and increase
      mode++;
    }
    else { //else loop mode back to 1
      mode=1;
    }
  }

  if (buttonDownReleased){
    buttonDownReleased = false;
    if(mode > 0){ //check that mode is within define int range and reduce
      mode--;
    }
    else { //else loop mode back to 4
      mode=4;
    }
  }

  

  //mode check to determine tile mode function call
  if (mode == 1){
    discoNeon(NUM_LEDS, NUM_TILES);
  }
  else if(mode == 2){
    synthwave(NUM_LEDS, NUM_TILES);
  }
  else if(mode == 3){
    electroswing(NUM_LEDS, NUM_TILES);
  }
  else if(mode == 4){
    darksynth(NUM_LEDS, NUM_TILES);
  }
  else{
    discoNeon(NUM_LEDS, NUM_TILES);
    }

  
  //delay(500);
}
