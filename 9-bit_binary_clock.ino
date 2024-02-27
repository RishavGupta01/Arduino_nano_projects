
// ## Project Description: The 9-Bye LED Status Indicator on the chip ensures the 
//integrity of the timing.

// ### Overview:
// This clock's setup will give it a visually pleasing look and make it a dynamic
//  clock. The LEDs' different colors will be used to note hours, minutes and seconds. 
// The clock will be simple, user-friendly, and high-precision (while not being based
//off the Real Time Clock module).

// ### Components Used:
// 1. **Arduino Nano**: A small microcontroller board.
// 2. **Blue LEDs**: Clock hour marks.
// 3. **Green LEDs**: Symbolize the minutes.
// 4. **Red LEDs**: Portray seconds.

// 3. **Interactivity** (Optional):
// - Within every 10 seconds, the red LEDs (seconds hand) light on for just instants.
// - Every minute, all the LEDs light on for just instants.

const int hoursLeds[] = {12, 11, 10};    // blue leds for hrs
const int minutesLeds[] = {8, 7, 6};     // grn leds for min
const int secondsLeds[] = {4, 3, 2};     // red leds for sec

void setup() {
  for (int i = 0; i < 3; i++) {
    pinMode(hoursLeds[i], OUTPUT);
    pinMode(minutesLeds[i], OUTPUT);
    pinMode(secondsLeds[i], OUTPUT);
  }
}

void loop() {
  unsigned long currentTime = millis();
  int hours = (currentTime / 3600000) % 24; 
  int minutes = (currentTime / 60000) % 60; 
  int seconds = (currentTime / 1000) % 60;   

  displayHours(hours);
  displayMinutes(minutes);
  displaySeconds(seconds);

  static int prevMinute = -1;
  if (minutes != prevMinute) {
    swipeUpEffect(); 
    prevMinute = minutes;
  }

  delay(1000); 
}

void displayHours(int h) {
  for (int i = 0; i < 3; i++) {
    digitalWrite(hoursLeds[i], (h >> i) & 1);
    }
}

void displayMinutes(int m) {
  for (int i = 0; i < 3; i++) {
    digitalWrite(minutesLeds[i], (m >> i) & 1);
  }
}

void displaySeconds(int s) {
  for (int i = 0; i < 3; i++) {
    digitalWrite(secondsLeds[i], (s >> i) & 1);
  }
}
void swipeUpEffect() {
  for (int i = 0; i < 3; i++) {
    digitalWrite(hoursLeds[i], HIGH);
    digitalWrite(minutesLeds[i], HIGH);
    digitalWrite(secondsLeds[i], HIGH);
  }
  delay(500); 
  for (int i = 0; i < 3; i++) {
    digitalWrite(hoursLeds[i], LOW);
    digitalWrite(minutesLeds[i], LOW);
    digitalWrite(secondsLeds[i], LOW);
  }
}