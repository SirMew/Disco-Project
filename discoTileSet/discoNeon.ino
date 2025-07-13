void discoNeon(int ledNum, int tileNum){

int colours[] = {1,2,3,4,5,6,7,8,9,10};
int randomIndex;
int colourVal;

//Loop through tiles
for(int j=1;j<=tileNum;j++){
  randomIndex = rand()%10;
  colourVal = colours[randomIndex];

  //loop through Leds in tile, setting all to a single a single colour
  for(int i=ledNum*j-ledNum;i<ledNum*j;i++){

          //mode check to determine tile mode function call
      switch(colourVal) {
        case 1:
          leds[i] = 0xB51D05;//orange
          break;
        case 2:
          leds[i] = 0xFFFF27; //yellow
          break;
        case 3:
          leds[i] = 0xFFDC40;//yellow
          break;
        case 4:
          leds[i] = 0x73FF37; //green
          break;
        case 5:
          leds[i] = 0x1D808B; //blue
          break;
        case 6:
          leds[i] = 0xFF0000; //red
          break;
        case 7:
          leds[i] = 0x81217C; //purple
          break;
        case 8:
          leds[i] = 0x24AD2D; //green
          break;
        case 9:
          leds[i] = 0xE3092F; //hot neon pink
          break;
        case 10:
          leds[i] = 0xD13189; //purple
          break;
        default:
          leds[i] = 0xFF0000; //red
          break;
  }
      /*if (colourVal == 1){
        leds[i] = 0xB51D05;//orange
      }

      else if (colourVal == 2){
        leds[i] = 0xFFFF27; //yellow
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
        leds[i] = 0xFF0000; //red
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
      } */
    }
    FastLED.setTemperature(Tungsten100W);
    FastLED.setCorrection(TypicalSMD5050);
    FastLED.setBrightness(200);
    FastLED.show();
  }
}

  
