#include "demo.h"
#include "pitches.h"

DemoClass demo;

int melody[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  4, 8, 8, 4, 4, 4, 4, 4
};

void setup()
{
  pinMode(8, OUTPUT);
  pinMode(7, INPUT);
  Serial.begin(115200);
}

int line = 0;
void loop()
{
  demo.ledcolor(255, 0, 0);
  delay(1000);
  demo.ledcolor(0, 255, 0);
  delay(1000);
  demo.ledcolor(0, 0, 255);
  delay(1000);

  demo.move(1, 255);
  delay(1000);
//  demo.move(1, 0);
//  delay(100);
  demo.move(2, 255);
  delay(1000);
//  demo.move(1, 0);
//  delay(100);
  demo.move(3, 255);
  delay(1000);
//  demo.move(1, 0);
//  delay(100);
  demo.move(4, 255);
  delay(1000);

  //  demo.motor(2,255);
  //  delay(500);
  //  demo.motor(2,-255);
  //  delay(500);
  demo.move(1, 0);
  delay(1000);


  for (int thisNote = 0; thisNote < 8; thisNote++) {
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(8, melody[thisNote], noteDuration);
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(8);
  }

  while (1)
  {
    line = demo.linesensor();
    switch (line)
    {
      case 1:
        demo.ledcolor(255, 0, 0);
        Serial.println("1");
        break;

      case 2:
        demo.ledcolor(0, 0, 255);
        Serial.println("2");
        break;

      case 3:
        demo.ledcolor(0, 255, 0);
        Serial.println("3");
        break;

      default :
        demo.ledcolor(0, 0, 0);
        Serial.println("default");
    }

    if (digitalRead(7) == 1)
    {
      break;
    }
  }

  for (int thisNote = 0; thisNote < 8; thisNote++) {
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(8, melody[thisNote], noteDuration);
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(8);
  }

}
