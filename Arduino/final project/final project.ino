//#include <Wire.h>
//#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
//LiquidCrystal_I2C lcd(0x27, 16, 2);

int analogPin1 = A0;  // choose an analog input pin
int analogPin2 = A2;
int analogPin3 = A4;
int analogPin4 = A5;
int digitalPin1 = 9;
int digitalPin2 = 10;
int digitalPin3 = 5;
int digitalPin4 = 6;
int vccreciver = 3;  //+ve of ir reciever
int vccsender = 2;   // +ve of ir sender
int buzzer = 4;
/*const byte numRows=2;
const byte numCols=2;
char keymap[numRows][numCols]={
{'1','2'},
{'3','4'},
};
byte rowPins[numRows]={5,6};
byte colPins[numCols]={9,10};
Keypad myKeypad=Keypad(makeKeymap(keymap),rowPins,colPins,numRows,numCols);*/

void setup() {
  Serial.begin(9600);
  //lcd.begin(2,16);
  pinMode(buzzer, OUTPUT);  // initialize serial communication
  pinMode(digitalPin1, OUTPUT);
  pinMode(digitalPin2, OUTPUT);
  pinMode(digitalPin3, OUTPUT);
  pinMode(digitalPin4, OUTPUT);
  pinMode(vccreciver, OUTPUT);
  pinMode(vccsender, OUTPUT);
  digitalWrite(vccsender, HIGH);
  digitalWrite(vccreciver, HIGH);  // set the digital pin as output
}

void loop() {
  int analogValue1 = analogRead(analogPin1);               // read the analog value
  int digitalValue1 = map(analogValue1, 0, 1023, 0, 255);  // convert the analog value to a digital value
  digitalWrite(digitalPin1, digitalValue1);                // output the digital value to the digital pin
  int readValue1 = digitalRead(digitalPin1);               // read the digital value from the digital pin
  /*Serial.print("Analog value: ");
  Serial.print(analogValue1);
  Serial.print(" Digital value: ");
  Serial.print(digitalValue1);
  Serial.print(" Read value1: ");
  Serial.println(readValue1);*/
  //second pin
  int analogValue2 = analogRead(analogPin2);               // read the analog value
  int digitalValue2 = map(analogValue2, 0, 1023, 0, 255);  // convert the analog value to a digital value
  digitalWrite(digitalPin2, digitalValue2);                // output the digital value to the digital pin
  int readValue2 = digitalRead(digitalPin2);               // read the digital value from the digital pin
  /*Serial.print("Analog value: ");
  Serial.print(analogValue2);
  Serial.print(" Digital value: ");
  Serial.print(digitalValue2);
  Serial.print(" Read value2: ");
  Serial.println(readValue2);*/
  //third pin
  int analogValue3 = analogRead(analogPin3);               // read the analog value
  int digitalValue3 = map(analogValue3, 0, 1023, 0, 255);  // convert the analog value to a digital value
  digitalWrite(digitalPin3, digitalValue3);                // output the digital value to the digital pin
  int readValue3 = digitalRead(digitalPin3);               // read the digital value from the digital pin
  /*Serial.print("Analog value: ");
  Serial.print(analogValue3);
  Serial.print(" Digital value: ");
  Serial.print(digitalValue3);
  Serial.print(" Read value3: ");
  Serial.println(readValue3);*/
  //4th pin
  int analogValue4 = analogRead(analogPin4);               // read the analog value
  int digitalValue4 = map(analogValue4, 0, 1023, 0, 255);  // convert the analog value to a digital value
  digitalWrite(digitalPin4, digitalValue4);                // output the digital value to the digital pin
  int readValue4 = digitalRead(digitalPin4);               // read the digital value from the digital pin
  /*Serial.print("Analog value: ");
  Serial.print(analogValue4);
  Serial.print(" Digital value: ");
  Serial.print(digitalValue4);
  Serial.print(" Read value4: ");
  Serial.println(readValue4);*/
  /*char key = myKeypad.getKey();
  Serial.println(key);
   //geting the key value and storing in keypressed
  if (key = NO_KEY){
    Serial.println("no key");
  }
  */
  //lcd.print("HELO");
  if (readValue1 == LOW && readValue3 == LOW) {//reading values from 1 , 3
    //lcd.backlight();
    //lcd.print("A");
    Serial.println("Key 1 pressed");
    digitalWrite(buzzer, HIGH);
    delay(100);
    digitalWrite(buzzer, LOW);
  } else if (readValue2 == LOW && readValue3 == LOW) {//reading values from 2 , 3
    //lcd.backlight();
    //lcd.print("B");
    Serial.println("Key 2 pressed");
    digitalWrite(buzzer, HIGH);
    delay(100);
    digitalWrite(buzzer, LOW);
  } else if (readValue1 == LOW && readValue4 == LOW) {//reading values from 1 , 4
    //lcd.backlight();
    //lcd.print("C");
    Serial.println("Key 3 pressed");
    digitalWrite(buzzer, HIGH);
    delay(100);
    digitalWrite(buzzer, LOW);
  } else if (readValue4 == LOW && readValue2 == LOW) {//reading values from 2 , 4
    //lcd.print("D");
    Serial.println("Key 4 pressed");
    digitalWrite(buzzer, HIGH);
    delay(100);
    digitalWrite(buzzer, LOW);
  } else {
    Serial.println("No input??!");
  }
  delay(1000);  // wait for 1000 milliseconds
}