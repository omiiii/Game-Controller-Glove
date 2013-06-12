// constants won't change. They're used here to 
// set pin numbers:
const int tiltPin = 6;     // the number of the pushbutton pin
const int tiltPin2 = 7;     // the number of the pushbutton pin

// variables will change:
int tiltState = 0;         // variable for reading the pushbutton status
int tiltState2 = 1;         // variable for reading the pushbutton status

void setup() {
  Serial.begin(115200); 
  // initialize the pushbutton pin as an input:
  pinMode(tiltPin, INPUT);
  pinMode(tiltPin2, INPUT); 
  Keyboard.begin(); 
}

void loop() {
  delay(200);
  // read the state of the pushbutton value:
  tiltState = digitalRead(tiltPin);
  tiltState2 = digitalRead(tiltPin2);

  if (tiltState == LOW) {
    Keyboard.write(KEY_DOWN_ARROW);
  }
  else {
    if (tiltState2 == HIGH) {
      Keyboard.press(KEY_RIGHT_ARROW);
      Keyboard.release(KEY_RIGHT_ARROW);
    } 
    else if (tiltState2 == LOW) {
      Keyboard.press(KEY_LEFT_ARROW);
      Keyboard.release(KEY_LEFT_ARROW);
    }
  }

}

