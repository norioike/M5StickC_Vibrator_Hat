#include <M5StickC.h>

#define PIN 26 //バイブの制御をするピン

int time_value  = 180;  //sec

void setup() {
  // put your setup code here, to run once:

  M5.begin();

  M5.Lcd.setRotation(1);
  M5.Lcd.setTextFont(4);
  M5.Lcd.fillScreen(BLACK);
  M5.Lcd.setCursor(0, 0);
  M5.Lcd.printf("3 minutes\nCooking timer");

  pinMode(PIN, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  M5.update();

  // ホームボタンを押したか？（1度だけ取得可能）
  if ( M5.BtnA.wasPressed() ) { //M5と書かれたボタンを押すと動き出す
    Serial.println("BtnA.wasPressed() == TRUE");

    M5.Lcd.setTextSize(1);
    M5.Lcd.setTextFont(7);
    String viewNum = "";
    char buff[10];

    for (int i = time_value; i >= 0; i--) {
      Serial.println(i);
      M5.Lcd.fillScreen(BLACK);
      M5.Lcd.setCursor(10, 16);

      String minutes = String(int(i / 60));
      if (minutes.length() == 1) {
        minutes = "0" + minutes;
      }

      String seconds = String(i % 60);
      if (seconds.length() == 1) {
        seconds = "0" + seconds;
      }

      viewNum = minutes + ":" + seconds;

      int len = viewNum.length();
      viewNum.toCharArray(buff, len + 1);
      M5.Lcd.printf(buff);
      if (i != 0) {
        delay(1000);
      }
    }

    M5.Lcd.setTextFont(4);
    M5.Lcd.setTextSize(1);
    M5.Lcd.fillScreen(BLACK);
    M5.Lcd.setCursor(0, 0);
    M5.Lcd.printf("Let's eat!");

    for (int j = 0 ; j < 5 ; j++) {
      digitalWrite(PIN, HIGH);
      delay(800);
      digitalWrite(PIN, LOW);
      delay(800);
    }
    M5.Lcd.fillScreen(BLACK);
    M5.Lcd.setCursor(0, 0);
    M5.Lcd.printf("3 minutes\nCooking timer");
  }
}
