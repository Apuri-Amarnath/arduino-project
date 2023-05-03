#include <LiquidCrystal_I2C.h>

int emptyVal = -1;
int buttonx0y0 = A0;
int buttonx0y1 = A2;
int buttonx1y0 = A4;
int buttonx1y1 = A5;
int valuecmp = 0;
int storedpassword[] = { emptyVal, emptyVal, emptyVal, emptyVal };
int maxUserInputLength = 4;
int readvalues[] = { emptyVal, emptyVal, emptyVal, emptyVal };
int vccreciver = 3;  //+ve of ir reciever
int vccsender = 2;   // +ve of ir sender
int buzzer = 4;

LiquidCrystal_I2C lcd(0x3F,20,4);// address of i2c module.
//int buttondel = ;// del button
void setup() {

  lcd.init();
  pinMode(7, OUTPUT);
  pinMode(vccreciver, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(vccsender, OUTPUT);
  digitalWrite(vccsender, HIGH);
  digitalWrite(vccreciver, HIGH);
}

void loop() {
  int displayreturnvalue = displayCodeEntryScreen();
  if(displayreturnvalue == 1){
    readpassword(readvalues);
    validatepassword(storedpassword,readvalues);
    }
    else{
      readpassword(storedpassword);
      lcd.setCursor(0,1);
      lcd.print("New pass saved");
      }
    //displayCodeEntryScreen();
    //readpassword(readvalues);
    //validatepassword(storedpassword,readvalues);
}
void readpassword(int readpass[]){
  int storecount = 0;
  //Serial.print("storecount:");
  //Serial.println(storecount);
  while (storecount != maxUserInputLength) {
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
      storeuserinput(readpass ,1);
      digitalWrite(buzzer, LOW);
    }
    if (readbuttonx0y1 == valuecmp && readbuttonx1y0 == valuecmp) {  // 2 & 3
      digitalWrite(buzzer, HIGH);
      delay(100);
      storeuserinput(readpass ,2);
      digitalWrite(buzzer, LOW);
    }
    if (readbuttonx0y0 == valuecmp && readbuttonx1y1 == valuecmp) {  // 1 & 4
      digitalWrite(buzzer, HIGH);
      delay(100);
      storeuserinput(readpass ,3);
      digitalWrite(buzzer, LOW);
    }
    if (readbuttonx1y1 == valuecmp && readbuttonx0y1 == valuecmp) {  // 2 & 4
      digitalWrite(buzzer, HIGH);
      delay(100);
      storeuserinput(readpass ,4);
      digitalWrite(buzzer, LOW);
    }
    storecount = userinputready(readpass);
    //Serial.print("readvalues[0]");
    //Serial.println(readvalues[0]);
  }
  }
void storeuserinput(int arraytostore[],int inputval) {
  for (int i = 0; i < maxUserInputLength; i++) {
    if (arraytostore[i] == emptyVal) {
      arraytostore[i] = inputval;
      lcd.print("*");
      break;
    }
  }
}
int userinputready(int valuesTocheck[]) {
  int storecount = 0;
  for (int i = 0; i < maxUserInputLength; i++) {
    if (valuesTocheck[i] != emptyVal) {
      storecount++;
    } else {
      break;
    }
  }
  return storecount;
  //if (storecount == maxUserInputLength) {
}
void printuserinput() {
  for (int i = 0; i < maxUserInputLength; i++) {
    Serial.print(readvalues[i]);
  }
}
void clearuserinput() {
  for (int i = 0; i < maxUserInputLength; i++) {
    readvalues[i] = emptyVal;
  }
}
void delinput(){
for (int i = (maxUserInputLength-1); i <= 0; i--) {
    if (readvalues[i] != emptyVal) {
      readvalues[i] = emptyVal;
      break;
    } 
}
}
int displayCodeEntryScreen()
{
  clearuserinput();
  lcd.clear();
  lcd.setCursor(0,0);
  if(userinputready(storedpassword) == maxUserInputLength){
  lcd.print("Code:");
  return 1;
  }
  else {
  lcd.print("New pass:");
  return 0;
  }
  }
 void validatepassword(int storedpassword[] ,int readvalues[] ){
 for(int i = 0 ; i < maxUserInputLength ; i++){
  if (storedpassword[i] != readvalues[i]){
     lcd.print("Invalid code");
     return;
    } 
 }
 if(sizeof(storedpassword) == sizeof(readvalues) && sizeof(storedpassword) == maxUserInputLength){
 lcd.print("Access Granted");
 }
 else{
     lcd.print("Invalid code");
  }
 }
