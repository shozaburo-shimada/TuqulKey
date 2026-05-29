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

  //LEDタイマーの初期設定
  last_update = millis();

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
    delay(1000);
  }
  
  if(key2 == 0){
    //Key2が押されたとき
    Keyboard.press(KEY_LEFT_GUI); // Command
    Keyboard.press('v');
    delay(1000);
    Keyboard.releaseAll();
    delay(1000);

  }

  if(key3 == 0){
    //Key3が押されたとき
    Keyboard.print("key3");
    delay(1000);
    Keyboard.releaseAll();
    delay(1000);

  }

  //Key4, Key5, Key6の値を読み取る
  digitalWrite(PIN_ROW0, HIGH);
  digitalWrite(PIN_ROW1, LOW);
  int key4 = digitalRead(PIN_COL0);
  int key5 = digitalRead(PIN_COL1);
  int key6 = digitalRead(PIN_COL2);
  if(key4 == 0){
    //Key4が押されたとき
    Keyboard.press('b');
    delay(1000);
    Keyboard.releaseAll();
    delay(1000);

  }
  
  if(key5 == 0){
    //Key5が押されたとき
    Keyboard.press('c');
    delay(1000);
    Keyboard.releaseAll();
    delay(1000);

  }

  if(key6 == 0){
    //Key6が押されたとき
    Keyboard.print("key3");
    delay(1000);
    Keyboard.releaseAll();
    delay(1000);

  }

  //LEDの色を変更
  updateLED();
}

const unsigned long INTERVAL_MS = 10; //LEDの色が変わる時間(ms)
const int HUE_STEP = 65535 / 360;     //LEDの色が変わるときの変化量
int hue = 0;
unsigned long last_update = 0;

void updateLED(){

  //前回、色が変わってからINTERVAL_MS秒経過したときだけ色を変更
  if(millis() - last_update > INTERVAL_MS){
    //色を変更
    hue = hue + HUE_STEP;
    if(hue > 65535){
      hue = 0;
    }
    
    //LEDの色を変更
    for(int i = 0; i < NUM_LED; i++){
      pixels.setPixelColor(i, pixels.ColorHSV(hue, 255, 255));
      pixels.show();
    }

    //LEDを変更した時刻を保存
    last_update = millis();
  }

}