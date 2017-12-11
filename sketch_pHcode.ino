int sensorPin = P1_5;

void setup()
{
  Serial.begin(9600);
  pinMode(P1_2, OUTPUT);
  //pinMode(P1_3, OUTPUT);
}

void loop()
{
  float x = analogRead(sensorPin);
  float pH =((-0.0067)*x) + 10.614;  // using equation from graph constructed by measuring the voltage at 2 pH values.
  Serial.println(pH);
  delay(1000);
  if (pH > 8)  // solution is too basic, need to add acid
  {
    //digitalWrite(P1_3, HIGH);
    digitalWrite(P1_2, LOW);
    
  }
  if (pH < 8) // solution is too acidic, need to add base
  {
    digitalWrite(P1_2, HIGH);
    
  }
}


