void discoHalf(int ledNum, int tileNum){

int colours[] = {1,2,3,4,5,6,7,8,9,10};
int randomIndex;
int colourVal;

//Loop through tiles and assumes there are twice as many to split each in half
for(int j=1;j<=tileNum*2;j++){
  randomIndex = rand()%10;
  colourVal = colours[randomIndex];
  //loop through Leds in each half tile, setting half of the led strip to a single colour
  // ledNum needs to be halved as only half a strip makes up half a tile.
  for(int i=ledNum/2*j-ledNum/2;i<ledNum/2*j;i++){
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
    FastLED.setTemperature(Tungsten100W);
    FastLED.setCorrection(TypicalSMD5050);
    FastLED.show();
  }
}