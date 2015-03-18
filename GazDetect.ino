/*
  Détecte le taux de gaz, pousse le niveau sur un bargraph et détecte le seuil.
 */
 
// Définition des variables

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

void setup() {                
  // initialize the digital pin as output or input.
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
  
  // Turn off all the LEDs
  digitalWrite(L1V, LOW);
  digitalWrite(L2V, LOW);
  digitalWrite(L3V, LOW);
  digitalWrite(L4J, LOW);
  digitalWrite(L5R, LOW);
  digitalWrite(L5R, LOW);
  
  // Initialise serial port
  Serial.begin(9600);
  
  // Delay for sensor preheating
  for (int prechauff=0; prechauff <= 20; prechauff++) {
    digitalWrite(L1V, HIGH);
    delay(500);
    digitalWrite(L1V, LOW);
    delay(500);
  }
}


void loop() {
  // Turn ON all the LEDs if PushButton switched ON
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
  
  // Read sensor value
  valueGaz = analogRead(Acapt);
  Serial.println(valueGaz);
  
  // Switch ON LED depending of valueGaz
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
  
  // Report Digital output from sensor to LED with blinking function
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
