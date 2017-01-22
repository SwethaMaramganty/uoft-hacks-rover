/*
 * Duct Tape Rover
 * 
 * Program that receives data from the Raspberry Pi and 
 * drives the motors, claw, and buzzer.
 */
 
#include <Servo.h>

// Pin assignments
int RIGHT_FORWARD = 2;
int RIGHT_BACKWARD = 3;
int LEFT_FORWARD = 4;
int LEFT_BACKWARD = 5; 
int RIGHT_ENABLE = 6;
int LEFT_ENABLE = 9;
int CLAW = 10;
int BUZZER = 11;

// Integer values for controlling components
int dir = 0;
int claw_val = 180;
int buzzer_tone = 10000;

Servo claw;

void setup() {
  Serial.begin(9600);

  // Sets up pins 2, 3, 4, 5, 6, 9, 10, 11 for output
  for (int i=2; i<7; i++) {
    pinMode(i, OUTPUT);
  }
  for (int i=9; i<12; i++) {
    pinMode(i, OUTPUT);
  }

  // Sets up claw
  claw.attach(CLAW);
  claw.write(claw_val);
}

void loop() {
  // Sets the speed for the left and right wheels
  analogWrite(RIGHT_ENABLE, 255);
  analogWrite(LEFT_ENABLE, 255);

  // Receives data from the Raspberry Pi
  if (Serial.available()) {
    dir = Serial.read();
    if (dir != 6) {
      // Turns off buzzer
      noTone(11);
    }
  }
  switch (dir) {
    case 0:
      // stop
      digitalWrite(RIGHT_FORWARD, LOW);
      digitalWrite(RIGHT_BACKWARD, LOW);
      digitalWrite(LEFT_FORWARD, LOW);
      digitalWrite(LEFT_BACKWARD, LOW);
      break;
      
    case 1:
      // forward
      digitalWrite(RIGHT_FORWARD, HIGH);
      digitalWrite(RIGHT_BACKWARD, LOW);
      digitalWrite(LEFT_FORWARD, HIGH);
      digitalWrite(LEFT_BACKWARD, LOW);
      break;
      
    case 2:
      // backward
      digitalWrite(RIGHT_FORWARD, LOW);
      digitalWrite(RIGHT_BACKWARD, HIGH);
      digitalWrite(LEFT_FORWARD, LOW);
      digitalWrite(LEFT_BACKWARD, HIGH);
      break;
      
    case 3:
      // left
      digitalWrite(RIGHT_FORWARD, HIGH);
      digitalWrite(RIGHT_BACKWARD, LOW);
      digitalWrite(LEFT_FORWARD, LOW);
      digitalWrite(LEFT_BACKWARD, HIGH);
      break;
      
    case 4:
      // right
      digitalWrite(RIGHT_FORWARD, LOW);
      digitalWrite(RIGHT_BACKWARD, HIGH);
      digitalWrite(LEFT_FORWARD, HIGH);
      digitalWrite(LEFT_BACKWARD, LOW);
      break;
      
    case 5:
      // claw
      if (claw_val == 0) {
        // close claw
        claw_val = 180;
      }
      else if (claw_val == 180) {
        // open claw
        claw_val = 0;
      }
      claw.write(claw_val);
      delay(1000);
      break;
      
    case 6:
      // annoying buzzer
      tone(BUZZER, buzzer_tone);
      break;
  }
}
