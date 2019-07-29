//piezos
int sensorPinOne = A0;
int sensorValueOne = 0;
int outputValueOne = 0;

int sensorPinTwo = A1;
int sensorValueTwo = 0;
int outputValueTwo = 0;

int sensorPinThree = A2;
int sensorValueThree = 0;
int outputValueThree = 0;

int sensorPinFour = A3;
int sensorValueFour = 0;
int outputValueFour = 0;

int sensorPinFive = A4;
int sensorValueFive = 0;
int outputValueFive = 0;

//pots
int potInputValueOne = 0; 
int potOutputValueOne = 0;
int potInputValueTwo = 0;
int potOutputValueTwo = 0;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(A9, INPUT);
  
  Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop() {
  
  // read the value from the sensor:
  sensorValueOne = analogRead(sensorPinOne);
  outputValueOne = map(sensorValueOne, 0, 1023, 0, 255);
  sensorValueTwo = analogRead(sensorPinTwo);
  outputValueTwo = map(sensorValueTwo, 0, 1023, 0, 255);
  sensorValueThree = analogRead(sensorPinThree);
  outputValueThree = map(sensorValueThree, 0, 1023, 0, 255);
  sensorValueFour = analogRead(sensorPinFour);
  outputValueFour = map(sensorValueFour, 0, 1023, 0, 255);
  sensorValueFive = analogRead(sensorPinFive);
  outputValueFive = map(sensorValueFive, 0, 1023, 0, 255);

  //pot
  potInputValueTwo = analogRead(A9);
  potOutputValueTwo = map(potInputValueTwo, 0, 1023, 5, 50);

  if (potOutputValueTwo > 0){
    Serial.println(potOutputValueTwo);
  }
  
  if (outputValueOne > 50 || outputValueTwo > 50 || outputValueThree > 50 || outputValueFour > 50 || outputValueFive > 50) 
{
  Serial.print(outputValueFive);
    Serial.print(" ");
    Serial.print(outputValueFour);
    Serial.print(" ");
    Serial.print(outputValueThree);
    Serial.print(" ");
    Serial.print(outputValueTwo);
    Serial.print(" ");
    Serial.println(outputValueOne);
  
//  mycounter++;
//  if (mycounter > 1)
//    mycounter = 0;
//  if (mycounter==1){
//    digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
//    delay(potOutputValueOne);                       // wait for a second
//    digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
//    delay(potOutputValueOne);   
//  } else if (mycounter==0) {
//    digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
//    delay(5);                       // wait for a second
//    digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
//    delay(5);   
//  }

digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(potOutputValueTwo);                       // wait for a second
    digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
    delay(potOutputValueTwo); 
  }
}
