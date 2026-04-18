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
  Serial.print(digitalRead(PIN_COL0));
  Serial.print(" ");
  Serial.print(digitalRead(PIN_COL1));
  Serial.print(" ");
  Serial.print(digitalRead(PIN_COL2));
  Serial.println();
  delay(500);
}