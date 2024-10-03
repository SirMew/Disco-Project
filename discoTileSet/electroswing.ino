void electroswing(int ledNum, int tileNum){

int colours[] = {1,2,3,4,5,6,7,8,9,10};
int randomIndex;
int colourVal;
//Loop through tiles

for(int j=1;j<=tileNum;j++){
  randomIndex = rand()%10;
  colourVal = colours[randomIndex];
  for(int i=10*j-10;i<10*j;i++){
      if (colourVal == 1){
        leds[i] = 0xC7BB85;//light yellow
      }

      else if (colourVal == 2){
        leds[i] = 0xAB985B; //gold
      }
  
      else if (colourVal == 3){
        leds[i] = 0xAE855D;//brown
      }
  
      else if (colourVal == 4){
        leds[i] = 0xCE5067; //pink
      }
  
      else if (colourVal == 5){
        leds[i] = 0xBA1044; //neon pink
      }
  

    }
    FastLED.setTemperature(Candle);
    FastLED.setCorrection(TypicalSMD5050);
    FastLED.show();
  }
  delay(500);
}

  
