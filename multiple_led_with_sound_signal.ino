int analogPin = A0;
int ledPins[] = {2,3,4,5,6,7,8,9}; //an array of pin numbers that LEDs are connected to
int bias = 0;
int ledCount = 8;

void setup() {
  for(int i=0; i<=7; i++){
  pinMode(ledPins[i], OUTPUT);
  }
  delay(1000); //for the transients to die out.
  bias = analogRead(analogPin);

}

void loop() {
  int sample = analogRead(analogPin);
  if (sample>=bias){
    sample = sample - bias;
  }
  else{
    sample = bias - sample;
  }
  sample = sample * 16;
  //map the sample to a range of 0 - ledCount
  int ledLev = map(sample,0,1023,0,ledCount); //map the result to a range of 0 to the number of LEDs
  for(int thisLed = 0; thisLed < ledCount; thisLed++){
    if (thisLed < ledLev){
      digitalWrite(ledPins[thisLed], HIGH);
    }
    else {
      digitalWrite(ledPins[thisLed], LOW);
    }
  }
  delay(10);
}
