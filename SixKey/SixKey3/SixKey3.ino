#include "Keyboard.h"
#include <Adafruit_NeoPixel.h>


const int PIN_COL0 = 2; 
const int PIN_COL1 = 3;
const int PIN_COL2 = 4;

const int PIN_ROW0 = 5;
const int PIN_ROW1 = 6;

const int PIN_LED = 7;
const int NUM_LED = 6;

Adafruit_NeoPixel pixels(NUM_LED, PIN_LED, NEO_GRB + NEO_KHZ800);


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

  //LEDの初期化
  pixels.begin(); 
  pixels.setBrightness(128); // 0 ~ 255
  pixels.clear();
  pixels.show();

  Serial.println("Hello");
}


void loop(){

  int key1 = digitalRead(PIN_COL0);
  int key2 = digitalRead(PIN_COL1);
  int key3 = digitalRead(PIN_COL2);

  if(key1 == 0){
    pixels.setPixelColor(0, 255, 0, 0);
    pixels.show();

    Keyboard.press('a');
    delay(10);
    Keyboard.releaseAll();
    delay(300);

    pixels.clear();
    pixels.show();
  }
  
  if(key2 == 0){
    pixels.setPixelColor(1, 0, 255, 0);
    pixels.show();

    Keyboard.press(KEY_RIGHT_CTRL);
    Keyboard.press('v');
    delay(10);
    Keyboard.releaseAll();
    delay(300);

    pixels.clear();
    pixels.show();
  }

  if(key3 == 0){
    pixels.setPixelColor(2, 0, 255, 255);
    pixels.show(); 

    Keyboard.print("key3");
    delay(10);
    Keyboard.releaseAll();
    delay(300);

    pixels.clear();
    pixels.show();
  }
  
  delay(10);
}