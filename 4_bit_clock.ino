const int redLed1 = 3;
const int redLed2 = 5;
const int blueLed1 = 6; 
const int blueLed2 = 9; 

void setup() {
  pinMode(redLed1, OUTPUT);
  pinMode(redLed2, OUTPUT);
  pinMode(blueLed1, OUTPUT);
  pinMode(blueLed2, OUTPUT);
}

void loop() {
  unsigned long currentTime = millis();
  int seconds = (currentTime / 1000) % 60;
  int minutes = (currentTime / 60000) % 60;
  updateseconds(seconds);
  updateminutes(minutes);
}

void updateseconds(int sec) {
  digitalWrite(redLed1, sec % 2 == 0 ? HIGH : LOW);
  digitalWrite(redLed2, sec % 2 == 1 ? HIGH : LOW);
}

void updateminutes(int min) {
  digitalWrite(blueLed1, min % 2 == 0 ? HIGH : LOW);
  digitalWrite(blueLed2, min % 2 == 1 ? HIGH : LOW);
}
