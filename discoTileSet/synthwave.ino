void synthwave(int ledNum, int tileNum){

int colours[] = {1,2,3,4,5,6,7,8};
int randomIndex;
int colourVal;

//Loop through tiles
for(int j=1;j<=tileNum;j++){
  randomIndex = rand()%10;
  colourVal = colours[randomIndex];

  //loop through Leds in tile, setting all to a single a single colour
  for(int i=ledNum*j-ledNum;i<ledNum*j;i++){
      if (colourVal == 1){
        leds[i] = 0xFFE600;//yellow
      }
      else if (colourVal == 2){
        leds[i] = 0xFF6600; //orange
      }
      else if (colourVal == 3){
        leds[i] = 0xFF0000;//red
      }
      else if (colourVal == 4){
        leds[i] = 0x00FFFF; //cyan
      }
      else if (colourVal == 5){
        leds[i] = 0x0040FF; //blue
      }
      else if (colourVal == 6){
        leds[i] = 0x8000FF; //purple
      }
      else if (colourVal == 7){
        leds[i] = 0xFF00FF; //neon purple
      }
      else if (colourVal == 8){
        leds[i] = 0xFF0066; //neon pink
      }
    }
    FastLED.setTemperature(Candle);
    FastLED.setCorrection(TypicalSMD5050);
    FastLED.show();
  }
  delay(1300);
}