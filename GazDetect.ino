/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
 
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int Acapt = A0;
int L3V = A1;
int L2V = A2;
int L1V = A3;
int BP = A4;
int Pot = A5;
int Dcapt = 7;
int L5R = 6;
int I3 = 5;
int I4 = 4;
int L6R = 3;
int I2 = 2;
int I1 = 1;
int L4J = 0;
int valuePot = 0;
int scalePot = 0;
int valueGaz = 0;
boolean clignote = false;
// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(L1V, OUTPUT);
  pinMode(L2V, OUTPUT);
  pinMode(L3V, OUTPUT);
  pinMode(L4J, OUTPUT);
  pinMode(L5R, OUTPUT);
  pinMode(L6R, OUTPUT);
  pinMode(I1, INPUT);
  pinMode(I2, INPUT);
  pinMode(I3, INPUT);
  pinMode(I4, INPUT);
  pinMode(BP, INPUT);
  pinMode(Pot, INPUT);
  
  digitalWrite(L1V, LOW);
  digitalWrite(L2V, LOW);
  digitalWrite(L3V, LOW);
  digitalWrite(L4J, LOW);
  digitalWrite(L5R, LOW);
  digitalWrite(L5R, LOW);
  
  Serial.begin(9600);
  
  for (int prechauff=0; prechauff <= 20; prechauff++) {
    digitalWrite(L1V, HIGH);
    delay(500);
    digitalWrite(L1V, LOW);
    delay(500);
  }
}

// the loop routine runs over and over again forever:
void loop() {
  int valBP = digitalRead(BP);
  if (valBP == HIGH) {
    digitalWrite(L1V, HIGH);
    digitalWrite(L2V, HIGH);
    digitalWrite(L3V, HIGH);
    digitalWrite(L4J, HIGH);
    digitalWrite(L5R, HIGH);
    digitalWrite(L6R, HIGH);
  }
  else
  {
    digitalWrite(L1V, LOW);
    digitalWrite(L2V, LOW);
    digitalWrite(L3V, LOW);
    digitalWrite(L4J, LOW);
    digitalWrite(L5R, LOW);
    digitalWrite(L6R, LOW);
  }
  valueGaz = analogRead(Acapt);
  valuePot = analogRead(Pot);
  Serial.println(valuePot);
  if (valueGaz > 50) {
    digitalWrite(L1V, HIGH);
  }
  if (valueGaz > 80) {
    digitalWrite(L2V, HIGH);
  }
  if (valueGaz > 100) {
    digitalWrite(L3V, HIGH);
  }
  if (valueGaz > 150) {
    digitalWrite(L4J, HIGH);
  }
  if (valueGaz > 200) {
    digitalWrite(L5R, HIGH);
  }
  if (digitalRead(Dcapt) == LOW) {
    if (clignote == false) {
      digitalWrite(L6R, LOW);
    }
    else
    {
      digitalWrite(L6R, HIGH);
    }
  clignote = !clignote;  
  }
  delay(200);
}
