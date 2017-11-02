#define buttonPin     2   // the number of the pushbutton pin
#define debounceDelay 50  // the debounce time; increase if the output flickers

// Variables will change:
bool ledState                  = HIGH;  // the current state of the output pin
//The following would be needed if generalizing this Debounce without delay
bool lastButtonState           = LOW;   // the previous reading from the input pin
bool alreadyResponded          = true;  // verify that the debounce only runs once
unsigned long lastDebounceTime = 0;     // the last time the output pin was toggled


void setup() {
  pinMode(buttonPin, INPUT); //This sketch is assuming there is a PULL-DOWN resistor

  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, ledState);
}

void loop() {
  bool reading = digitalRead(buttonPin);

  if (reading != lastButtonState) {
    lastDebounceTime = millis();
    alreadyResponded = false;
  }

  //if PULL-DOWN assumption first described in 'void setup()' is false change to !reading
  if (reading && !alreadyResponded && ((millis() - lastDebounceTime) > debounceDelay)) {
    ledState = !ledState;
    alreadyResponded = true;
  }
  
  digitalWrite(LED_BUILTIN, ledState);

  lastButtonState = reading;
}

