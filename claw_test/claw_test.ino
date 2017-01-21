#include <Servo.h>

Servo claw;
int claw_val = 0;

void setup() {
  // put your setup code here, to run once:
  claw.attach(11);
  claw.write(claw_val);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (claw_val == 0) {
    claw_val = 180;
    claw.write(claw_val);
  }
  if (claw_val == 180) {
    claw_val = 0;
    claw.write(claw_val);
  }
  delay(1000);
}
