void darksynth(int ledNum, int tileNum){

int colours[] = {1,2,3,4,5,6,7};
int randomIndex;
int colourVal;

//Loop through tiles
for(int j=1;j<=tileNum;j++){
  randomIndex = rand()%7;
  colourVal = colours[randomIndex];

  //loop through Leds in tile, setting all to a single a single colour
  for(int i=ledNum*j-ledNum;i<ledNum*j;i++){
      if (colourVal == 1){
        leds[i] = 0xCA0137; //dark pink
      }
      else if (colourVal == 2){
        leds[i] = 0xB10A0D; //evil red
      }
      else if (colourVal == 3){
        leds[i] = 0x360e12; //burgundy
      }
      else if (colourVal == 4){
        leds[i] = 0xB10A0D; //evil red
      }
      else if (colourVal == 5){
        leds[i] = 0x621c32; //dark purple
      }
      else if (colourVal == 6){
        leds[i] = 0x376767; //dark cyan
      }
      else if (colourVal == 7){
        leds[i] = 0x376767; //dark
      }
    }
    FastLED.setTemperature(Candle);
    FastLED.setCorrection(TypicalSMD5050);
    FastLED.show();
  }
  delay(1200);
}