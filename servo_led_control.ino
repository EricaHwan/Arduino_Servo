#include <Servo.h>

// 定義腳位
const int SERVO_PIN = 9;    // 伺服馬達腳位
const int LED1_PIN = 7;     // 第一顆LED腳位
const int LED2_PIN = 8;     // 第二顆LED腳位
const int POT_PIN = A0;     // 可調式電阻腳位

// 創建伺服馬達物件
Servo myservo;

void setup() {
  // 初始化序列通訊
  Serial.begin(9600);
  
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
  
  // 顯示歡迎訊息
  Serial.println("Arduino Servo and LED Control System");
  Serial.println("Commands:");
  Serial.println("1: LED1 ON");
  Serial.println("0: LED1 OFF");
  Serial.println("3: LED2 ON");
  Serial.println("2: LED2 OFF");
}

void loop() {
  // 讀取可調式電阻的值（0-1023）
  int potValue = analogRead(POT_PIN);
  
  // 將可調式電阻的值映射到伺服馬達角度（0-180）
  int servoAngle = map(potValue, 0, 1023, 0, 180);
  
  // 控制伺服馬達
  myservo.write(servoAngle);
  
  // 檢查是否有LED控制指令
  if (Serial.available() > 0) {
    char command = Serial.read();
    
    switch (command) {
      case '1':
        digitalWrite(LED1_PIN, HIGH);
        Serial.println("LED1 ON");
        break;
        
      case '0':
        digitalWrite(LED1_PIN, LOW);
        Serial.println("LED1 OFF");
        break;
        
      case '3':
        digitalWrite(LED2_PIN, HIGH);
        Serial.println("LED2 ON");
        break;
        
      case '2':
        digitalWrite(LED2_PIN, LOW);
        Serial.println("LED2 OFF");
        break;
    }
  }
  
  // 每100毫秒輸出一次當前角度
  static unsigned long lastPrint = 0;
  if (millis() - lastPrint > 100) {
    Serial.print("Servo Angle: ");
    Serial.println(servoAngle);
    lastPrint = millis();
  }
} 