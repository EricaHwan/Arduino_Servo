# Arduino 伺服馬達與LED控制專案

本專案展示如何使用Arduino控制伺服馬達和兩顆LED，並使用可調式電阻來控制伺服馬達的角度。

## 版本
v1.0.1

## 最後更新
2024-03-21

## 硬體需求
- Arduino開發板（例如：Arduino Uno）
- 1個伺服馬達
- 2顆LED
- 1個10kΩ可調式電阻（電位計）
- 2個220Ω電阻（用於LED限流）
- 跳線
- 麵包板

## 接線方式
### 伺服馬達接線
1. 伺服馬達紅線 → Arduino 5V
2. 伺服馬達棕線 → Arduino GND
3. 伺服馬達橙線 → Arduino 數位腳位9

### LED接線
#### LED 1
1. LED長腳（正極）→ 220Ω電阻 → Arduino 數位腳位7
2. LED短腳（負極）→ Arduino GND

#### LED 2
1. LED長腳（正極）→ 220Ω電阻 → Arduino 數位腳位8
2. LED短腳（負極）→ Arduino GND

### 可調式電阻接線
1. 可調式電阻左腳 → Arduino 5V
2. 可調式電阻中間腳 → Arduino 類比腳位A0
3. 可調式電阻右腳 → Arduino GND

## 功能特點
- 使用可調式電阻控制伺服馬達角度（0-180度）
- 兩顆LED獨立控制
- 序列通訊除錯功能
- 即時角度顯示

## 使用方式
1. 按照接線方式連接硬體
2. 將程式碼上傳至Arduino開發板
3. 開啟序列監視器查看除錯訊息
4. 轉動可調式電阻來控制伺服馬達角度
5. 使用序列監視器控制LED

## 控制指令
- 輸入 '1' 開啟第一顆LED
- 輸入 '0' 關閉第一顆LED
- 輸入 '3' 開啟第二顆LED
- 輸入 '2' 關閉第二顆LED

## 注意事項
1. LED必須使用限流電阻（220Ω）以防止燒毀
2. 確保可調式電阻接線正確，避免短路
3. 伺服馬達需要足夠的電源供應，建議使用外部電源
4. 如果使用外部電源，請確保Arduino和外部電源的GND相連 