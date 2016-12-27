#include"pitches.h"

const int enableChord = 10; //Reads from Arduino 1 pin A1
const int chordSignal1 = 12; //Reads from Arduino 1 pin A3
const int chordSignal2 = 13; //Reads from Arduino 1 pin A2

void setup() {
  pinMode(chordSignal1, INPUT);
  pinMode(chordSignal2, INPUT);
  Serial.begin(9600);
}

void loop () {
  noTone(11);
  delay(20);
  while(digitalRead(enableChord) == HIGH && (digitalRead(chordSignal1) == LOW) && (digitalRead(chordSignal2) == LOW)){
    tone(11, NOTE_E4);
    Serial.println("note e");
  }
  while((digitalRead(enableChord) == HIGH && digitalRead(chordSignal1) == LOW) && (digitalRead(chordSignal2) == HIGH)){
    tone(11, NOTE_F4);
    Serial.println("note f");
  }
  while((digitalRead(enableChord) == HIGH && digitalRead(chordSignal1) == HIGH) && (digitalRead(chordSignal2) == LOW)){
    tone(11, NOTE_G4);
    Serial.println("note g");
  }
  while((digitalRead(enableChord) == HIGH && digitalRead(chordSignal1) == HIGH) && (digitalRead(chordSignal2) == HIGH)){
    tone(11, NOTE_A4);
    Serial.println("note a");
  }
  if((digitalRead(enableChord) == LOW )){
    noTone(11);
    delay(20);
    Serial.println("Hello");
  }
}

