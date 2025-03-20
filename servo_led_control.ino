#include <Servo.h>

// 定義腳位
const int SERVO_PIN = 9;    // 伺服馬達腳位
const int LED1_PIN = 7;     // 第一顆LED腳位
const int LED2_PIN = 8;     // 第二顆LED腳位
const int POT_PIN = A0;     // 可調式電阻腳位

// 創建伺服馬達物件
Servo myservo;

// 儲存上一次的可調式電阻值
int lastPotValue = 0;

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
  
  // 讀取初始可調式電阻值
  lastPotValue = analogRead(POT_PIN);
}

void loop() {
  // 讀取可調式電阻的值（0-1023）
  int potValue = analogRead(POT_PIN);
  
  // 將可調式電阻的值映射到伺服馬達角度（0-180）
  int servoAngle = map(potValue, 0, 1023, 0, 180);
  
  // 控制伺服馬達
  myservo.write(servoAngle);
  
  // 判斷轉動方向並控制LED
  if (potValue > lastPotValue + 10) {  // 向右轉動
    digitalWrite(LED1_PIN, HIGH);
    digitalWrite(LED2_PIN, LOW);
  }
  else if (potValue < lastPotValue - 10) {  // 向左轉動
    digitalWrite(LED1_PIN, LOW);
    digitalWrite(LED2_PIN, HIGH);
  }
  
  // 更新上一次的可調式電阻值
  lastPotValue = potValue;
  
  // 小延遲以避免讀取過於頻繁
  delay(50);
} 