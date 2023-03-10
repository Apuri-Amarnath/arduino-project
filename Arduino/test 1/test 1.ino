
int buttonx0y0 = A0;
int buttonx0y1 = A2;
int buttonx1y0 = A4;
int buttonx1y1 = A5;
int valuecmp = 0;
int readvalues[] = { 1, 1, 1, 1 };
int vccreciver = 3;  //+ve of ir reciever
int vccsender = 2;   // +ve of ir sender
int buzzer = 4;
void setup() {

  Serial.begin(9600);
  pinMode(7, OUTPUT);
  pinMode(vccreciver, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(vccsender, OUTPUT);
  digitalWrite(vccsender, HIGH);
  digitalWrite(vccreciver, HIGH);
}

void loop() {
  int storecount = userinputready();
  //Serial.print("storecount:");
  //Serial.println(storecount);
  while (storecount != 4) {
    int readbuttonx0y0 = analogRead(buttonx0y0);
    // Serial.print("readbuttonx0y0:");
    // Serial.println(readbuttonx0y0);
    delay(100);
    int readbuttonx0y1 = analogRead(buttonx0y1);
    delay(100);
    int readbuttonx1y0 = analogRead(buttonx1y0);
    delay(100);
    int readbuttonx1y1 = analogRead(buttonx1y1);
    delay(100);
    if (readbuttonx0y0 == valuecmp && readbuttonx1y0 == valuecmp) {  //1 & 3
      digitalWrite(buzzer, HIGH);
      delay(100);
      storeuserinput(4);
      digitalWrite(buzzer, LOW);
    }
    if (readbuttonx0y1 == valuecmp && readbuttonx1y0 == valuecmp) {  // 2 & 3
      digitalWrite(buzzer, HIGH);
      delay(100);
      storeuserinput(7);
      digitalWrite(buzzer, LOW);
    }
    if (readbuttonx0y0 == valuecmp && readbuttonx1y1 == valuecmp) {  // 1 & 4
      digitalWrite(buzzer, HIGH);
      delay(100);
      storeuserinput(6);
      digitalWrite(buzzer, LOW);
    }
    if (readbuttonx1y1 == valuecmp && readbuttonx0y1 == valuecmp) {  // 2 & 4
      digitalWrite(buzzer, HIGH);
      delay(100);
      storeuserinput(8);
      digitalWrite(buzzer, LOW);
    }
    storecount = userinputready();
    //Serial.print("readvalues[0]");
    //Serial.println(readvalues[0]);
  }

  Serial.println("userInput ready");
  printuserinput();
  Serial.println("");
  clearuserinput();
}
void storeuserinput(int inputval) {
  for (int i = 0; i < 4; i++) {
    if (readvalues[i] == 1) {
      readvalues[i] = inputval;
      break;
    }
  }
}
int userinputready() {
  int storecount = 0;
  for (int i = 0; i < 4; i++) {
    if (readvalues[i] != 1) {
      storecount++;
    } else {
      break;
    }
  }
  return storecount;
  //if (storecount == 4) {
}
void printuserinput() {
  for (int i = 0; i < 4; i++) {
    Serial.print(readvalues[i]);
  }
}
void clearuserinput() {
  for (int i = 0; i < 4; i++) {
    readvalues[i] = 1;
  }
}
