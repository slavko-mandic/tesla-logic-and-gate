#include <Arduino.h>
#include <FastLED.h>

// How many leds in your strip?
#define NUM_LEDS 159
#define NUMBER_OF_STEPS 4
#define BRIGHTNESS 32

#define DATA_PIN A0
#define INPUT_PIN_1 11
#define INPUT_PIN_2 12

int step = 0;

// Define the array of leds
CRGB leds[NUM_LEDS];

byte ledSection[NUM_LEDS] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                            1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                            2, 2, 2, 2, 2, 2, 2, 2, 2,
                            3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
                            4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
                            5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
                            6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,
                            7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
                            8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
                            9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9};

byte activeSection[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

void displyLeds();
boolean isSectionActive(int sect);
boolean isLedActive(int led);
byte getLedSection(int led);
void setSectionStatus(int sect, int status);

void setup() {
  pinMode(INPUT_PIN_1, INPUT_PULLUP);
  pinMode(INPUT_PIN_2, INPUT_PULLUP);

  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
  FastLED.setBrightness(BRIGHTNESS);
}



void loop() {
  int i = digitalRead(INPUT_PIN_1);
  int j = digitalRead(INPUT_PIN_2);

  if ((i == 0) && (j==0)){
    setSectionStatus(0, 1);
    setSectionStatus(2, 1);
  }
  if ((i == 1) && (j==0)){
    setSectionStatus(0, 0);
    setSectionStatus(2, 0);
  }

  if ((i == 1) && (j=1)){
    setSectionStatus(1, 1);
    setSectionStatus(3, 1);
  }
  if ((i == 0) && (j==1)){
    setSectionStatus(1, 0);
    setSectionStatus(3, 0);
  }

  delay(50);

  displyLeds();
  step++;

  if (step == NUMBER_OF_STEPS)
    step = 0;
}

void displyLeds(){
  for (int i = 0; i < NUM_LEDS; i ++){
    if (isLedActive(i)){
      leds[i] = CRGB::Red;
    }
    else {
      leds[i] = CRGB::Blue;
    }
  }
  FastLED.show();
}

boolean isSectionActive(int sect){
  return (activeSection[sect] == 1);
}

boolean isLedActive(int led){
  boolean currentStep = (led % 3 == step);
  return (isSectionActive(getLedSection(led)) && currentStep);
}

byte getLedSection(int led){
  return ledSection[led];
}

void setSectionStatus(int sect, int status){
  activeSection[sect] = status;
}