/*
 * Claw test - opens and closes the claw every second
 */

#include <Servo.h>

Servo claw;
int claw_val = 0;

void setup() {
  claw.attach(11);
  claw.write(claw_val);
}

void loop() {
  if (claw_val == 0) {
    // closes claw
    claw_val = 180;
  }
  if (claw_val == 180) {
    // opens claw
    claw_val = 0;
  }
  claw.write(claw_val);
  delay(1000);
}
