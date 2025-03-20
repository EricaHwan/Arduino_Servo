#include <Servo.h>

// 定義腳位
const int SERVO_PIN = 9;    // 伺服馬達腳位
const int LED1_PIN = 7;     // 第一顆LED腳位
const int LED2_PIN = 8;     // 第二顆LED腳位

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
  Serial.println("0-180: Set servo angle");
}

void loop() {
  // 檢查是否有可讀取的數據
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
        
      default:
        // 檢查是否為數字（用於控制伺服馬達）
        if (command >= '0' && command <= '9') {
          // 讀取完整的數字
          String numberString = "";
          numberString += command;
          while (Serial.available() > 0) {
            char nextChar = Serial.read();
            if (nextChar >= '0' && nextChar <= '9') {
              numberString += nextChar;
            } else {
              break;
            }
          }
          
          // 轉換為整數
          int angle = numberString.toInt();
          
          // 確保角度在有效範圍內
          if (angle >= 0 && angle <= 180) {
            myservo.write(angle);
            Serial.print("Servo angle set to: ");
            Serial.println(angle);
          } else {
            Serial.println("Invalid angle! Please enter a value between 0 and 180.");
          }
        }
        break;
    }
  }
} 