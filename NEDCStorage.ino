const int  buttonPin = 2;    // the pin that the pushbutton is attached to
const int ledPin = 13;  // LED that signifies when recording is occurring (on = recording)
const int soundPin = A0; // Analog pin connected to audio output of amplified sound from the microphone piece of the smart hearing aid
int count = 0; // For formatting purposes
int num = 0;   // Random number generator to test serial output to text file capabilities with PuTTY
bool on = false;  // Recording is on or off
bool pressed = false;  // Controls functions when button is pressed

void setup() {
  Serial.begin(9600);
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {

  // If the button is pressed and the recorder is off
  if(digitalRead(buttonPin) == LOW && pressed == false){
    on = !on;
    pressed = true;
  }

  // If the button isn't pressed, pressed = false
  if(digitalRead(buttonPin) == HIGH){
    pressed = false;
  }
  
  if(on){
    
    digitalWrite(ledPin, HIGH);  // Turn on the LED

    //num = random(0, 255);  // Random number generator testing

    // Output audio data detected by analog pin A0
    Serial.println(analogRead(soundPin) + " ");

    // Increment counter for how many numbers have been inputted
    count++;
    
    //Serial.print(String(num) + " ");  // Printing for RNG testing

    // New line if 50 numbers have been outputted
    if(count % 50 == 0){
      Serial.println();
    }
    
  }

  else{
    digitalWrite(ledPin, LOW);  // If the button isn't pressed, turn off the LED
  }
  
}
