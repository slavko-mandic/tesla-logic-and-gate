#include <Arduino.h>
#include <FastLED.h>

/*
#define NUM_LEDS    1
#define DATA_PIN     A2
#define COLOR_ORDER GRB
#define LED_TYPE WS2812B
#define BRIGHTNESS 32
#define VOLTS 5
#define MAX_AMPS 2500
CRGB leds[NUM_LEDS];
*/

#define NUM_LEDS 1
#define DATA_PIN A0
CRGB leds[NUM_LEDS];


#define NUM_OF_STEPS 4

struct Section{
  int size;
  int members[10];
  boolean active = false;
};

Section sections[3];




void setup() {
  sections[0].size = 11;
  sections[0].members[0] = 0;
  sections[0].members[1] = 1;
  sections[0].members[2] = 2;
  sections[0].members[3] = 3;
  sections[0].members[4] = 4;
  sections[0].members[5] = 5;
  sections[0].members[6] = 6;
  sections[0].members[7] = 7;
  sections[0].members[8] = 8;
  sections[0].members[9] = 9;
  sections[0].members[10] = 10;
  sections[0].active = true;

  sections[1].size = 17;
  sections[1].members[0] = 11;
  sections[1].members[1] = 12;
  sections[1].members[2] = 13;
  sections[1].members[3] = 14;
  sections[1].members[4] = 15;
  sections[1].members[5] = 16;
  sections[1].members[6] = 17;
  sections[1].members[7] = 18;
  sections[1].members[8] = 19;
  sections[1].members[9] = 20;
  sections[1].members[10] = 21;
  sections[1].members[11] = 22;
  sections[1].members[12] = 23;
  sections[1].members[13] = 24;
  sections[1].members[14] = 25;
  sections[1].members[15] = 26;
  sections[1].members[16] = 27;
  sections[1].active = true;

  sections[2].size = 9;
  sections[2].members[0] = 28;
  sections[2].members[1] = 29;
  sections[2].members[2] = 30;
  sections[2].members[3] = 31;
  sections[2].members[4] = 32;
  sections[2].members[5] = 33;
  sections[2].members[6] = 34;
  sections[2].members[7] = 35;
  sections[2].members[8] = 36;
  sections[2].active = true;

  sections[3].size = 21;
  sections[3].members[0] = 37;
  sections[3].members[1] = 38;
  sections[3].members[2] = 39;
  sections[3].members[3] = 40;
  sections[3].members[4] = 41;
  sections[3].members[5] = 42;
  sections[3].members[6] = 43;
  sections[3].members[7] = 44;
  sections[3].members[8] = 45;
  sections[3].members[9] = 46;
  sections[3].members[10] = 47;
  sections[3].members[11] = 48;
  sections[3].members[12] = 49;
  sections[3].members[13] = 50;
  sections[3].members[14] = 51;
  sections[3].members[15] = 52;
  sections[3].members[16] = 53;
  sections[3].members[17] = 54;
  sections[3].members[18] = 55;
  sections[3].members[19] = 56;
  sections[3].members[20] = 57;
  sections[3].active = true;

  sections[4].size = 25;
  sections[4].members[0] = 58;
  sections[4].members[1] = 59;
  sections[4].members[2] = 60;
  sections[4].members[3] = 61;
  sections[4].members[4] = 62;
  sections[4].members[5] = 63;
  sections[4].members[6] = 64;
  sections[4].members[7] = 65;
  sections[4].members[8] = 66;
  sections[4].members[9] = 67;
  sections[4].members[10] = 68;
  sections[4].members[11] = 69;
  sections[4].members[12] = 70;
  sections[4].members[13] = 71;
  sections[4].members[14] = 72;
  sections[4].members[15] = 73;
  sections[4].members[16] = 74;
  sections[4].members[17] = 75;
  sections[4].members[18] = 76;
  sections[4].members[19] = 77;
  sections[4].members[20] = 78;
  sections[4].members[21] = 79;
  sections[4].members[22] = 80;
  sections[4].members[23] = 81;
  sections[4].members[24] = 82;
  sections[4].active = true;

  sections[5].size = 10;
  sections[5].members[0] = 83;
  sections[5].members[1] = 84;
  sections[5].members[2] = 85;
  sections[5].members[3] = 86;
  sections[5].members[4] = 87;
  sections[5].members[5] = 88;
  sections[5].members[6] = 89;
  sections[5].members[7] = 90;
  sections[5].members[8] = 91;
  sections[5].members[9] = 92;
  sections[5].active = true;

  sections[6].size = 15;
  sections[6].members[0] = 93;
  sections[6].members[1] = 94;
  sections[6].members[2] = 95;
  sections[6].members[3] = 96;
  sections[6].members[4] = 97;
  sections[6].members[5] = 98;
  sections[6].members[6] = 99;
  sections[6].members[7] = 100;
  sections[6].members[8] = 101;
  sections[6].members[9] = 102;
  sections[6].members[10] = 103;
  sections[6].members[11] = 104;
  sections[6].members[12] = 105;
  sections[6].members[13] = 106;
  sections[6].members[14] = 107;
  sections[6].active = true;

  sections[7].size = 26;
  sections[7].members[0] = 108;
  sections[7].members[1] = 109;
  sections[7].members[2] = 110;
  sections[7].members[3] = 111;
  sections[7].members[4] = 112;
  sections[7].members[5] = 113;
  sections[7].members[6] = 114;
  sections[7].members[7] = 115;
  sections[7].members[8] = 116;
  sections[7].members[9] = 117;
  sections[7].members[10] = 118;
  sections[7].members[11] = 119;
  sections[7].members[12] = 120;
  sections[7].members[13] = 121;
  sections[7].members[14] = 122;
  sections[7].members[15] = 123;
  sections[7].members[16] = 124;
  sections[7].members[17] = 125;
  sections[7].members[18] = 126;
  sections[7].members[19] = 127;
  sections[7].members[20] = 128;
  sections[7].members[21] = 129;
  sections[7].members[22] = 130;
  sections[7].members[22] = 131;
  sections[7].members[24] = 132;
  sections[7].members[25] = 133;
  sections[7].active = true;
  
  sections[8].size = 12;
  sections[8].members[0] = 134;
  sections[8].members[1] = 135;
  sections[8].members[2] = 136;
  sections[8].members[3] = 137;
  sections[8].members[4] = 138;
  sections[8].members[5] = 139;
  sections[8].members[6] = 140;
  sections[8].members[7] = 141;
  sections[8].members[8] = 142;
  sections[8].members[9] = 143;
  sections[8].members[10] = 144;
  sections[8].members[11] = 145;
  sections[8].active = true;

  sections[9].size = 13;
  sections[9].members[0] = 146;
  sections[9].members[1] = 147;
  sections[9].members[2] = 148;
  sections[9].members[3] = 149;
  sections[9].members[4] = 150;
  sections[9].members[5] = 151;
  sections[9].members[6] = 152;
  sections[9].members[7] = 153;
  sections[9].members[8] = 154;
  sections[9].members[9] = 155;
  sections[9].members[10] = 156;
  sections[9].members[11] = 157;
  sections[9].members[12] = 158;
  sections[9].active = true;
  /*  
  FastLED.addLeds<LED_TYPE, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS);
  FastLED.setMaxPowerInVoltsAndMilliamps(VOLTS, MAX_AMPS);
  FastLED.setBrightness(BRIGHTNESS);
  FastLED.clear();
  FastLED.show();
  */
 FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
}

int step=0;

void display_leds(int step){
  for(int i=0;i<NUM_LEDS;i++){
    if ((i % NUM_OF_STEPS == step)/* && ( is_in_section(i,9))*/) {
        leds[i] = CRGB(32,0,0);
    }
    else{
        leds[i] = CRGB(0,0,32);
    }
  }
  FastLED.show();

}

void loop() {
  // Turn the LED on, then pause
  leds[0] = CRGB::Red;
  FastLED.show();
  delay(500);
  // Now turn the LED off, then pause
  leds[0] = CRGB::Black;
  FastLED.show();
  delay(500);

  // put your main code here, to run repeatedly:
  /*
  display_leds(step);
  step++;
  if (step>NUM_OF_STEPS) step=0;  
  
  delay(100);  
  */
}



boolean is_in_section(int led, int section){
  for(int i=0;i<sections[section].size;i++){
    if (led == sections[section].members[i]){
      return true;
    }
  }
  return false;
}
