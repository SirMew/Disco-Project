void stripTest(int ledNum, int tileNum){

//Loop all leds one at a time a set one to red at a time
  for(int i=1;i<ledNum*tileNum;i++){
    leds[i] = CRGB::Red;
    FastLED.setTemperature(Tungsten100W);
    FastLED.setCorrection(TypicalSMD5050);
    FastLED.show();
    leds[i] = CRGB::Black; // clear this LED for next time around in loop
    FastLED.show();
  }
}