#include "Keyboard.h"
#include <Adafruit_NeoPixel.h>


const int PIN_COL0 = 2; 
const int PIN_COL1 = 3;
const int PIN_COL2 = 4;

const int PIN_ROW0 = 5;
const int PIN_ROW1 = 6;

const int PIN_LED = 7;
const int NUM_LED = 6;

const int BRIGHTNESS = 100;           //LEDの明るさ、0 ~ 255のどれか

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
  pinMode(PIN_ROW1, OUTPUT);

  //LEDの初期化
  pixels.begin(); 
  pixels.setBrightness(BRIGHTNESS); // 0 ~ 255
  pixels.clear();
  pixels.show();

  Serial.println("Hello");
}


void loop(){

  //Key1, Key2, Key3の値を読み取る
  digitalWrite(PIN_ROW0, LOW);
  digitalWrite(PIN_ROW1, HIGH);
  int key1 = digitalRead(PIN_COL0);
  int key2 = digitalRead(PIN_COL1);
  int key3 = digitalRead(PIN_COL2);
  if(key1 == 0){
    //Key1が押されたとき
    Keyboard.press('a');
    delay(1000);
    Keyboard.releaseAll();

    pixels.setPixelColor(0, pixels.Color(255, 0, 0));
    pixels.show();
    delay(1000);
    pixels.clear();
    pixels.show();

  }
  
  if(key2 == 0){
    //Key2が押されたとき
    pixels.setPixelColor(1, 0, 255, 0);
    pixels.show();

    Keyboard.press(KEY_RIGHT_CTRL);
    Keyboard.press('v');
    delay(1000);
    Keyboard.releaseAll();
    delay(1000);

    pixels.clear();
    pixels.show();
  }

  if(key3 == 0){
    //Key3が押されたとき
    pixels.setPixelColor(2, 0, 255, 255);
    pixels.show(); 

    Keyboard.print("key3");
    delay(1000);
    Keyboard.releaseAll();
    delay(1000);

    pixels.clear();
    pixels.show();
  }

  digitalWrite(PIN_ROW0, HIGH);
  digitalWrite(PIN_ROW1, LOW);
  int key4 = digitalRead(PIN_COL0);
  int key5 = digitalRead(PIN_COL1);
  int key6 = digitalRead(PIN_COL2);
  if(key4 == 0){
    //Key4が押されたとき
    pixels.setPixelColor(3, 255, 0, 0);
    pixels.show();

    Keyboard.press('b');
    delay(100);
    Keyboard.releaseAll();
    delay(1000);

    pixels.clear();
    pixels.show();
  }
  
  if(key5 == 0){
    //Key5が押されたとき
    pixels.setPixelColor(4, 0, 255, 0);
    pixels.show();

    Keyboard.press('c');
    delay(1000);
    Keyboard.releaseAll();
    delay(1000);

    pixels.clear();
    pixels.show();
  }

  if(key6 == 0){
    //Key6が押されたとき
    pixels.setPixelColor(5, 0, 255, 255);
    pixels.show(); 

    Keyboard.print("key3");
    delay(10);
    Keyboard.releaseAll();
    delay(1000);

    pixels.clear();
    pixels.show();
  }
  
}