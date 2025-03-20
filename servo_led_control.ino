#include <Servo.h>

// 定義腳位
const int SERVO_PIN = 9;    // 伺服馬達腳位
const int LED1_PIN = 7;     // 第一顆LED腳位
const int LED2_PIN = 8;     // 第二顆LED腳位
const int SERVO_POT_PIN = A0;    // 伺服馬達可調式電阻腳位
const int LED_POT_PIN = A1;      // LED可調式電阻腳位

// 創建伺服馬達物件
Servo myservo;

void setup() {
  // 設定LED腳位為輸出
  pinMode(LED1_PIN, OUTPUT);
  pinMode(LED2_PIN, OUTPUT);
  
  // 連接伺服馬達
  myservo.attach(SERVO_PIN);
  
  // 初始化LED狀態為關閉
  digitalWrite(LED1_PIN, LOW);
  digitalWrite(LED2_PIN, LOW);
  
  // 初始化伺服馬達角度為90度
  myservo.write(90);
}

void loop() {
  // 讀取伺服馬達可調式電阻的值（0-1023）
  int servoPotValue = analogRead(SERVO_POT_PIN);
  
  // 將伺服馬達可調式電阻的值映射到角度（0-180）
  int servoAngle = map(servoPotValue, 0, 1023, 0, 180);
  
  // 控制伺服馬達
  myservo.write(servoAngle);
  
  // 讀取LED可調式電阻的值（0-1023）
  int ledPotValue = analogRead(LED_POT_PIN);
  
  // 將LED可調式電阻的值映射到PWM值（0-255）
  int ledBrightness = map(ledPotValue, 0, 1023, 0, 255);
  
  // 控制兩顆LED的亮度
  analogWrite(LED1_PIN, ledBrightness);
  analogWrite(LED2_PIN, ledBrightness);
} 