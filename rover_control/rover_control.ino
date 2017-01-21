int RIGHT_FORWARD = 2;
int RIGHT_BACKWARD = 3;
int LEFT_FORWARD = 4;
int LEFT_BACKWARD = 5; 
int RIGHT_ENABLE = 6;
int LEFT_ENABLE = 9;
int dir = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for (int i=2; i<7; i++) {
    pinMode(i, OUTPUT);
  }
  pinMode(9, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(RIGHT_ENABLE, 100);
  analogWrite(LEFT_ENABLE, 100);
  if (Serial.available()) {
    dir = Serial.parseInt();
    Serial.print(dir);
  }
  switch (dir) {
    case 0:
      // forward
      digitalWrite(RIGHT_FORWARD, HIGH);
      digitalWrite(RIGHT_BACKWARD, LOW);
      digitalWrite(LEFT_FORWARD, HIGH);
      digitalWrite(LEFT_BACKWARD, LOW);
      break;
    case 1:
      // backward
      digitalWrite(RIGHT_FORWARD, LOW);
      digitalWrite(RIGHT_BACKWARD, HIGH);
      digitalWrite(LEFT_FORWARD, LOW);
      digitalWrite(LEFT_BACKWARD, HIGH);
      break;
    case 2:
      // left
      digitalWrite(RIGHT_FORWARD, HIGH);
      digitalWrite(RIGHT_BACKWARD, LOW);
      digitalWrite(LEFT_FORWARD, LOW);
      digitalWrite(LEFT_BACKWARD, HIGH);
      break;
    case 3:
      // right
      digitalWrite(RIGHT_FORWARD, LOW);
      digitalWrite(RIGHT_BACKWARD, HIGH);
      digitalWrite(LEFT_FORWARD, HIGH);
      digitalWrite(LEFT_BACKWARD, LOW);
      break;
  }
}
