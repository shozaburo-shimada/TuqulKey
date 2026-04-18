# include "Keyboard.h"

const int PIN_COL0 = 2; 
const int PIN_COL1 = 3;
const int PIN_COL2 = 4;

const int PIN_ROW0 = 5;
const int PIN_ROW1 = 6;

void setup(){
  //シリアル通信の初期設定
  Serial.begin(9600);

  //キーボードライブラリの初期設定
  Keyboard.begin();

  //GPIOの初期設定
  pinMode(PIN_COL0, INPUT_PULLUP);
  pinMode(PIN_COL1, INPUT_PULLUP);
  pinMode(PIN_COL2, INPUT_PULLUP);

  pinMode(PIN_ROW0, OUTPUT);
  digitalWrite(PIN_ROW0, LOW);

  Serial.println("Hello");
}


void loop(){

  int key1 = digitalRead(PIN_COL0);
  int key2 = digitalRead(PIN_COL1);
  int key3 = digitalRead(PIN_COL2);

  if(key1 == 0){
    Keyboard.press('a');
    delay(10);
    Keyboard.releaseAll();
    delay(300);
  }
  
  if(key2 == 0){
    Keyboard.press(KEY_RIGHT_CTRL);
    Keyboard.press('v');
    delay(10);
    Keyboard.releaseAll();
    delay(300);
  }

  if(key3 == 0){
    Keyboard.print("key3");
    delay(10);
    Keyboard.releaseAll();
    delay(300);
  }
  
  delay(10);
}