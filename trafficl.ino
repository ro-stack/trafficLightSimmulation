// TRAFFIC LIGHT 1
int red1 = 13;
int yellow1 = 12;
int green1 = 11;

// TRAFFIC LIGHT 2
int red2 = 10;
int yellow2 = 9;
int green2 = 8;

// PEDESTRIAN CROSSING
int pedCross = 7;
int pedCrossOn = 6;
int incomingByte;

void setup() {
  // TRAFFIC LIGHT 1
  pinMode(red1, OUTPUT);
  pinMode(yellow1, OUTPUT);
  pinMode(green1, OUTPUT);

  // TRAFFIC LIGHT 2
  pinMode(red2, OUTPUT);
  pinMode(yellow2, OUTPUT);
  pinMode(green2, OUTPUT);

  //  PEDESTRIAN CROSSING
  pinMode(pedCross, OUTPUT);
  pinMode(pedCrossOn, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  changeLights();

}

void changeLights() {

  // TRAFFIC LIGHT1 AND 2 YELLOW ON
  digitalWrite(green1, LOW);
  digitalWrite(yellow1, HIGH);
  digitalWrite(yellow2, HIGH);
  digitalWrite(pedCross, HIGH);
  digitalWrite(pedCrossOn, LOW);
  delay(5000);

  // TRAFFIC LIGHT2 GREEN ON, TRAFFIC LIGHT1 RED OFF
  digitalWrite(yellow1, LOW);
  digitalWrite(red1, HIGH);
  digitalWrite(yellow2, LOW);
  digitalWrite(red2, LOW);
  digitalWrite(green2, HIGH);
  digitalWrite(pedCross, HIGH);
  digitalWrite(pedCrossOn, LOW);
  delay(5000);

  // TRAFFIC LIGHT1 AND 2 YELLOW ON
  digitalWrite(yellow1, HIGH);
  digitalWrite(yellow2, HIGH);
  digitalWrite(green2, LOW);
  digitalWrite(pedCross, HIGH);
  digitalWrite(pedCrossOn, LOW);
  delay(3000);

  // TRAFFIC LIGHT1 GREEN ON, TRAFFIC LIGHT 2 RED ON
  digitalWrite(green1, HIGH);
  digitalWrite(yellow1, LOW);
  digitalWrite(red1, LOW);
  digitalWrite(yellow2, LOW);
  digitalWrite(red2, HIGH);
  digitalWrite(pedCrossOn, LOW);
  delay(5000);

  // PEDESTRIAN GREEN ON WHEN '1' ENTERED TO SERIAL PORT
  if (Serial.available() > 0) {
    incomingByte = Serial.read();
    if (incomingByte == '1') {
      digitalWrite(green1, LOW);
      digitalWrite(yellow1, LOW);
      digitalWrite(red1, HIGH);
      digitalWrite(yellow2, LOW);
      digitalWrite(green2, LOW);
      digitalWrite(red2, HIGH);
      digitalWrite(pedCrossOn, HIGH);
      digitalWrite(pedCross, LOW);
      delay (4000);

      // GREEN WARNING FLASH
      digitalWrite(pedCrossOn, LOW);
      delay (500);
      digitalWrite(pedCrossOn, HIGH);
      delay (500);
      digitalWrite(pedCrossOn, LOW);
      delay (500);
      digitalWrite(pedCrossOn, HIGH);
      delay (500);

    }
  }
}



