
#include "8x8.h"
#include "pitches.h"
#include "song.h"

int thisNote = -1, noteDuration = 0;
unsigned long previousTime = 0,
presentTime = 0,
pauseBetweenNotes = 0;

byte presentState = 1, previousState = 1, patternNumber = 0;

void setup() {
  for (byte i = 0; i < sizeof(row); i++) {
    pinMode(row[i], OUTPUT);
  }
  for (byte i = 0; i < sizeof(col); i++) {
    pinMode(col[i], OUTPUT);
  }  
  Serial.begin(9600);

  pinMode(A5, OUTPUT);
  pinMode(2, INPUT_PULLUP);
}

void loop() {
  presentState = digitalRead(2);
  if(presentState == 0 && previousState == 1){
    patternNumber = !patternNumber;
  }
  if(patternNumber == 0){
    showPattern(heart);
    checkToPlay();
    delay(1);
  }else if(patternNumber == 1){
    showPattern(squaree);
    checkToPlay();
    delay(1);
  }
  previousState = presentState;
}


void checkToPlay() {
  presentTime = millis();
  if (presentTime - previousTime >= pauseBetweenNotes) {
    thisNote += 1;
    if(thisNote >= 32 ) {
      thisNote = -1;
      pauseBetweenNotes = 100;
      previousTime = millis();
    } else {
      noteDuration = noteDurations2[thisNote];
      tone(A5, melody2[thisNote], noteDuration);
      pauseBetweenNotes = noteDuration * 1.2;
      previousTime = millis();
    }
  }
}
