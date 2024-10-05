#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <DFRobot_MAX30102.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

const char* ssid = "3"; // Wi-Fi SSID
const char* password = "00000011"; // Wi-Fi Password
const char* server = "203.253.128.177"; // 모비우스 서버 IP 주소
const int port = 7579; // 모비우스 서버 포트
const String cnt = "exingrate";
const String ae = "20191546"; // 모비우스에서 사용할 AE 이름

#define SCREEN_WIDTH 128 // OLED 디스플레이 너비, 픽셀 단위
#define SCREEN_HEIGHT 64 // OLED 디스플레이 높이, 픽셀 단위
#define OLED_RESET    -1 // 리셋 핀 # (또는 Arduino 리셋 핀을 공유하는 경우 -1)
#define SCREEN_ADDRESS 0x3C // 128x64 OLED I2C 주소
#define swich D3 // 스위치 핀 설정 (GPIO 0)

// I2C로 연결된 SSD1306 디스플레이에 대한 선언
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

DFRobot_MAX30102 particleSensor;

void send_data(String payload);

void setup() {
  Serial.begin(9600);

  // 스위치 핀 설정
  pinMode(swich, INPUT_PULLUP);

  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 할당 실패"));
    for (;;) ; // 진행하지 않고 영원히 루프 유지
  }

  // Wi-Fi 연결
  WiFi.begin(ssid, password);
  Serial.print("Wi-Fi에 연결 중");
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println();
  Serial.println("Wi-Fi에 연결되었습니다.");

  display.clearDisplay(); // 디스플레이 지우기
  display.setTextSize(1); // 보통 크기의 글꼴
  display.setTextColor(SSD1306_WHITE); // 흰색 글자
  display.setCursor(0, 0); // 좌상단에서 시작
  display.display();

  // MAX30102 센서 설정
  while (!particleSensor.begin()) {
    Serial.println("MAX30102 was not found");
    delay(1000);
  }

  particleSensor.sensorConfiguration(/*ledBrightness=*/0x1F, /*sampleAverage=*/SAMPLEAVG_4, \
                                  /*ledMode=*/MODE_MULTILED, /*sampleRate=*/SAMPLERATE_400, \
                                  /*pulseWidth=*/PULSEWIDTH_411, /*adcRange=*/ADCRANGE_4096);
}

void loop() {
  if (digitalRead(swich) == LOW) { // 스위치가 켜졌을 때
    int32_t SPO2; //SPO2
    int8_t SPO2Valid; //Flag to display if SPO2 calculation is valid
    int32_t heartRate; //Heart-rate
    int8_t heartRateValid; //Flag to display if heart-rate calculation is valid 

    particleSensor.heartrateAndOxygenSaturation(&SPO2, &SPO2Valid, &heartRate, &heartRateValid);

    String payload = "{\"m2m:cin\": {\"con\": \"" + String(heartRate, DEC) + "\"}}";
    send_data(payload);

    // 디스플레이에 하트 및 데이터를 표시
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 0);
    display.print("Heart Rate: ");
    display.println(heartRate);
    display.display();

    delay(1000); // 1초 대기
  } else { // 스위치가 꺼졌을 때 DeepSleep 모드로 전환
    Serial.println("Entering DeepSleep mode.");
    display.clearDisplay();
    display.setTextSize(2);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 0);
    display.println("DeepSleep");
    display.display();

    delay(1000); // 디스플레이에 DeepSleep 메시지 표시 후

    // DeepSleep 모드 설정 (스위치 핀으로 깨어남)
    ESP.deepSleep(0); // 0을 전달하면 외부 신호에 의해 깨어날 때까지 Sleep 유지
  }
}

void send_data(String payload) {
  WiFiClient client;
  HTTPClient http;

  // HTTP POST 요청 설정
  http.begin(client, "http://" + String(server) + ":" + String(port) + "/Mobius/" + ae + "/" + cnt);
  http.addHeader("Content-Type", "application/vnd.onem2m-res+json; ty=4");
  http.addHeader("Accept", "application/json");
  http.addHeader("X-M2M-RI", "12345");
  http.addHeader("X-M2M-Origin", ae);
  
  int httpCode = http.POST(payload); // HTTP POST 요청 전송
  String response = http.getString(); // 서버 응답 수신
  http.end(); // HTTP 연결 종료

  if (httpCode == 201) {
    Serial.println("데이터를 Mobius로 전송하였습니다.");
  } else {
    Serial.print("HTTP POST 실패: ");
    Serial.println(httpCode);
  }
}
