#include <FastLED.h>
#include <arduino-timer.h>

/* number of LEDS in a WS2811 strip = 10 
  number of Strips in build = 4 */
#define NUM_LEDS 5 // per LED strip
#define DATA_PIN 5
#define NUM_TILES 9
#define MODE_UP 2
#define MODE_DOWN 3
#define COLOUR_ORDER BRG
#define LED_TYPE WS2811
#define heart_beat_pin LED_BUILTIN  // digital pin for heart beat LED 

//Function prototypes
void discoNeon(int ledNum, int tileNum);
void synthwave(int ledNum, int tileNum);
void electroswing(int ledNum, int tileNum);
void darksynth(int ledNum, int tileNum);
void stripTest(int ledNum, int tileNum);
void startupRGB(int ledNum, int tileNum);

volatile byte g_buttonUpReleased = false;
volatile byte g_buttonDownReleased = false;
int g_mode = 1;
unsigned long g_interval= 900; 

// timer creation
//auto timer_create_default();
Timer<1> timer;

//Interrupt Service Routines
void buttonUpReleasedInterrupt(){
  g_buttonUpReleased = true;
}
void buttonDownReleasedInterrupt(){
  g_buttonDownReleased = true;
}
volatile bool heartbeat(void *){
  digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN)); // toggle the LED
  return true; // repeat? true
}

bool changeColourCallback(void *){
  //mode check to determine tile mode function call
  switch(g_mode) {
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
  return true; //repeat this task
}

void updateInterval(){
    switch(g_mode) {
    case 1:
      g_interval = 900;
      break;
    case 2:
      g_interval = 1300;
      break;
    case 3:
      g_interval = 500;
      break;
    case 4:
      g_interval = 1200;
      break;
    case 5:
      g_interval = 900;
      break;
    case 6:
      g_interval = 100;
      break;
    default:
      g_interval = 900;
      break;
  }
  timer.cancel();
  timer.every(g_interval, changeColourCallback);
}
//setup LED object
CRGB leds[NUM_TILES*NUM_LEDS]; //struct array CRGB combining all hardware strips into one big strip for data output

void setup() {

  // initialise builtin LED for heartbeat status
  pinMode(LED_BUILTIN, OUTPUT); 

  //add pin 2 interrupt 
  pinMode(MODE_UP, INPUT);
  attachInterrupt(digitalPinToInterrupt(MODE_UP), buttonUpReleasedInterrupt, FALLING);

  //add pin 3 interrupt 
  pinMode(MODE_DOWN, INPUT);
  attachInterrupt(digitalPinToInterrupt(MODE_DOWN), buttonDownReleasedInterrupt, FALLING);

  //schedule heartbeat timer to run every 1000ms
  //timer.every(1000, heartbeat);
  updateInterval(); //initialise with default mode

  // sanity check delay - allows reprogramming if accidently blowing power w/leds
  delay(1000);
  FastLED.addLeds<LED_TYPE, DATA_PIN, COLOUR_ORDER>(leds, NUM_LEDS*NUM_TILES);

  // start test - loop through red, green, blue
  startupRGB(NUM_LEDS, NUM_TILES);
}
 
void loop() {
// checks for button interrupts and increments or decrements mode value
  if (g_buttonUpReleased){
    g_buttonUpReleased = false;
    if(g_mode < 6){ //check that mode is within define int range and increase
      g_mode++;
    }
    else { //else loop mode back to 1
      g_mode=1;
    }
  }
  if (g_buttonDownReleased){
    g_buttonDownReleased = false;
    if(g_mode > 0){ //check that mode is within define int range and reduce
      g_mode--;
    }
    else { //else loop mode back to 5
      g_mode=6;
    }
  }

  timer.tick();
}