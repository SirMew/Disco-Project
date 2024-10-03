void startTest(int ledNum, int tileNum){
int colourVal =0;
//Loop through RGB
for(int t=0;t<3;t++){
  colourVal=colourVal+1;
  //Loop through tiles
  for(int j=1;j<=tileNum;j++){
    
    for(int i=10*j-10;i<10*j;i++){
    
        if (colourVal == 1){
          leds[i] = 0xFF0000; //red
        }
  
        else if (colourVal == 2){
          leds[i] = 0x00FF00; //green
        }
    
        else if (colourVal == 3){
          leds[i] = 0x0000FF; //blue
      }
    }
    
  }
  FastLED.show();
    delay(1000);
}
}
