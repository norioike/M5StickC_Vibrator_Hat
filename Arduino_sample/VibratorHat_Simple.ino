#include <M5StickC.h>
#include "FastLED.h" //FastLEDライブラリが必要です。
//インストールされてない方は ->　https://github.com/FastLED/FastLED

#define PIN 26 //バイブの制御をするピン

void setup() {
  // put your setup code here, to run once:
  M5.begin();

  M5.Lcd.setRotation(1);//画面の向きを変更
  M5.Lcd.setTextFont(4);//フォントの設定
  M5.Lcd.fillScreen(BLACK);//背景をブラックに
  M5.Lcd.setCursor(0, 0);//カーソルを左上に。
  M5.Lcd.printf("Enjoy\n        Vibrator\n                    Hat!!");

  //pwmの設定。最初の引数がchannel,次が周波数,最後が解像度（ここでは8bit = 256段階）
  ledcSetup(0, 500, 8);
  //ピンをチャンネルに接続
  ledcAttachPin(PIN, 0);

}

void loop() {
  // put your main code here, to run repeatedly:
  M5.update();

  // ホームボタンを押したか？（1度だけ取得可能）
  if ( M5.BtnA.wasPressed() ) {
    Serial.println("BtnA.wasPressed() == TRUE");

    ledcWrite(0, 255);
    delay(1000);
    ledcWrite(0, 128);
    delay(1000);
    ledcWrite(0, 0);
  }

}
