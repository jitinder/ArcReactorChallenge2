#include <math.h>
#include <msp430.h>

const int ThermistorPin = P1_0; //A0
const int heaterPin = P1_1; //A1 

void setup() {
  Serial.begin(9600); //Set the Serial port at 9600 baud rate
  pinMode(ThermistorPin, INPUT);
  pinMode(heaterPin, OUTPUT);
}

//Use the Steinhart-Hart equation to convert to degrees C
double getTemperature(int RawADC) {
  /* Line of Regression found using points and comparing with rawADC value
  y = 314.6139 + (295.4974 - 314.6139)/(1 + (x/499.5793)^45.39041)*/
 double Temp;
 Temp = 314.6139 + (295.4974 - 314.6139)/(1 + powf((RawADC/499.5793),45.39041));
 return Temp-273;
}

void loop() {
  double output = analogRead(ThermistorPin);
  double temp = getTemperature(output);
  if (temp < 26.5)
  {
    digitalWrite(heaterPin, HIGH);
  }
  else{
    digitalWrite(heaterPin, LOW);
  }
  Serial.println(temp);

  delay(1000); //Frequency of data collection
}