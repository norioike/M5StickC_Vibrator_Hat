/*
   This is a basic example on how to use Espalexa with RGB color devices.
*/
#ifdef ARDUINO_ARCH_ESP32
#include <WiFi.h>
#else
#include <ESP8266WiFi.h>
#endif
//#define ESPALEXA_ASYNC //コメントアウト
#include <Espalexa.h>
#include <M5StickC.h>


//これはAlexaの仕様で固定された値。

#define BULB_COLOR    16753231
#define SOFT_WHITE    16755295
#define WHITE_COLOR   16760972
#define NOON_WHITE    16765615
#define NOON_LIGHT    16770253
#define RED_COLOR     16711680
#define CRYMSON       16717638
#define SERMON        16752762
#define ORANGE        16754176
#define GOLD          16765952
#define YELLOW        16711424
#define GREEN_COLOR   65280
#define TURKISH       4718572
#define CYAN          65279
#define SKY_BLUE      9691391
#define BLUE_COLOR    255
#define PURPLE        11215871
#define MAGENTA       16711934
#define PINK          16760779
#define LAVENDER      10452991

// prototypes
boolean connectWifi();

//callback function prototype
void colorLightChanged(uint8_t brightness, uint32_t rgb);
void brightnessChanged(uint8_t brightness);

// Change this!!
const char* ssid = "yukai2_g";
const char* password = "karin120";

boolean wifiConnected = false;

Espalexa espalexa;

#define PIN 26  //Vibrator Hatの制御ピン
#define LED 10  //M5StickCに内蔵されているLEDを使う

void setup()
{
  Serial.begin(115200);
  pinMode(LED, OUTPUT);
  digitalWrite(LED, HIGH);
  pinMode(PIN,OUTPUT);
  // Initialise wifi connection
  wifiConnected = connectWifi();


  if (wifiConnected) {
    espalexa.addDevice("カウントダウンタイマー", TimerHandler);
    espalexa.begin();

  } else
  {
    while (1) {
      Serial.println("Cannot connect to WiFi. Please check data and reset the ESP.");
      delay(2500);
    }
  }
  M5.begin();

  M5.Lcd.setRotation(1);
  M5.Lcd.setTextFont(4);
  M5.Lcd.fillScreen(BLACK);
  M5.Lcd.setCursor(0, 0);
  M5.Lcd.printf("IoT\nCountdown\nTimer!");

}

void loop()
{
  espalexa.loop();
  delay(1);
}


//the color device callback function has two parameters
void TimerHandler(uint8_t brightness, uint32_t rgb) {
  //do what you need to do here, for example control RGB LED strip
  Serial.print("Brightness: ");
  Serial.print(brightness);
  Serial.print(", Red: ");
  Serial.print((rgb >> 16) & 0xFF); //get red component
  Serial.print(", Green: ");
  Serial.print((rgb >>  8) & 0xFF); //get green
  Serial.print(", Blue: ");
  Serial.println(rgb & 0xFF); //get blue

  M5.Lcd.setTextSize(1);
  M5.Lcd.setTextFont(7);
  String viewNum = "";
  char buff[10];


  int value = 0;
  switch (rgb) {
    case LAVENDER://ラベンダー色が呼ばれる
      value = 180;
      break;
    case GOLD://金色が呼ばれる
      value = 300;
      break;
    case PINK://ピンク色が呼ばれる
      value = 20;
      break;
    default:
      value = 10;
      break;
  }


  for (int i = value; i >= 0; i--) {
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

  for (int j = 0 ; j < 3 ; j++) {
    digitalWrite(PIN, HIGH);
    delay(800);
    digitalWrite(PIN, LOW);
    delay(800);
  }
  M5.Lcd.fillScreen(BLACK);
  M5.Lcd.setCursor(0, 0);
  M5.Lcd.printf("IoT\nCountdown\nTimer!");
}

// connect to wifi – returns true if successful or false if not
boolean connectWifi() {
  boolean state = true;
  int i = 0;

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.println("");
  Serial.println("Connecting to WiFi");

  // Wait for connection
  Serial.print("Connecting...");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    if (i > 40) {
      state = false; break;
    }
    i++;
  }
  Serial.println("");
  if (state) {
    Serial.print("Connected to ");
    Serial.println(ssid);
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());
    digitalWrite(LED, LOW);
    delay(3000);
    digitalWrite(LED, HIGH);
  }
  else {
    Serial.println("Connection failed.");
    for (int i = 0; i < 5; i++) {
      digitalWrite(LED, LOW);
      delay(500);
      digitalWrite(LED, HIGH);
      delay(500);
    }
  }
  return state;
}
