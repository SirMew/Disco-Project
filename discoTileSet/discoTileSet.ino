#include "FastLED.h"

/* number of LEDS in a WS2811 strip = 10 
  number of Strips in build = 4 */
 
#define NUM_LEDS 10 // per LED strip
#define DATA_PIN 5
#define NUM_TILES 4
#define MODE_UP 2
#define MODE_DOWN 3
#define COLOUR_ORDER BRG
#define LED_TYPE WS2811
#define heart_beat_pin   LED_BUILTIN  // digital pin for heart beat LED 

//Function prototypes
void discoNeon(int ledNum, int tileNum);
void synthwave(int ledNum, int tileNum);
void electroswing(int ledNum, int tileNum);
void darksynth(int ledNum, int tileNum);
void stripTest(int ledNum, int tileNum);
void startTest(int ledNum, int tileNum);
void heart_beat();

volatile byte buttonUpReleased = false;
volatile byte buttonDownReleased = false;
int mode = 1;
long unsigned heart_beat_freq = 10; // time(milliseconds) of heart beat frequency 
long unsigned heart_beat_on_off_time; // the time the LED is on and off - 1/2 frequency 
long unsigned last_heart_beat_time;   // time in milliseconds of last heart beat status change 
bool heart_beat_status = HIGH;        // current status of heart beat, start high 


//Mode button functions
void buttonUpReleasedInterrupt(){
  buttonUpReleased = true;
}
void buttonDownReleasedInterrupt(){
  buttonDownReleased = true;
}

//CRGB leds[NUM_TILES][NUM_LEDS]; // struct array CRGB leds[NUM_STRIPS][NUM_LEDS_PER_STRIP] if using strips on different pins to set up multiarrays
CRGB leds[NUM_TILES*NUM_LEDS]; //struct array CRGB combining all hardware strips into one big strip for data output

void setup() {

  // initialise builtin LED for heartbeat status
  pinMode(LED_BUILTIN, OUTPUT); 
  heart_beat_on_off_time = heart_beat_freq / 2; // LED is on and off at 1/2 frequency time 

  //add pin 2 interrupt 
  pinMode(MODE_UP, INPUT);
  attachInterrupt(digitalPinToInterrupt(MODE_UP), buttonUpReleasedInterrupt, FALLING);

  //add pin 3 interrupt 
  pinMode(MODE_DOWN, INPUT);
  attachInterrupt(digitalPinToInterrupt(MODE_DOWN), buttonDownReleasedInterrupt, FALLING);

  // sanity check delay - allows reprogramming if accidently blowing power w/leds
  delay(1000);
  FastLED.addLeds<LED_TYPE, DATA_PIN, COLOUR_ORDER>(leds, NUM_LEDS*NUM_TILES);//.setCorrection(ClearBlueSky);
  //FastLED.setBrightness(CRGB(255,255,255));

  // start test - loop through red, green, blue
  startTest(NUM_LEDS, NUM_TILES);
}
 

void loop() {

//heartbeat function
  heart_beat();

// checks for button interrupts and increments or decrements mode value
  if (buttonUpReleased){
    buttonUpReleased = false;
    if(mode < 6){ //check that mode is within define int range and increase
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
    else { //else loop mode back to 5
      mode=6;
    }
  }
  
  //mode check to determine tile mode function call
  switch(mode) {
    case 1:
      discoNeon(NUM_LEDS, NUM_TILES);
      break;
    case 2:
      synthwave(NUM_LEDS, NUM_TILES);
      break;
    case 3:
      electroswing(NUM_LEDS, NUM_TILES);
      break;
    case 4:
      darksynth(NUM_LEDS, NUM_TILES);
      break;
    case 5:
      discoHalf(NUM_LEDS, NUM_TILES);
      break;
    case 6:
      stripTest(NUM_LEDS, NUM_TILES);
      break;
    default:
      discoNeon(NUM_LEDS, NUM_TILES);
      break;
  }
  //delay(500);
}
