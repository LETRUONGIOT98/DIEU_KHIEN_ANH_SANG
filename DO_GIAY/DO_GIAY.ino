#include <Wire.h>  // Thư viện Wire cho giao tiếp I2C
#include <LiquidCrystal_I2C.h>  // Thư viện LCD I2C
#define echoPin 2  // Chân echo của SR04 kết nối với chân 2 của Arduino
#define trigPin 3  // Chân trig của SR04 kết nối với chân 3 của Arduino

LiquidCrystal_I2C lcd(0x27, 16, 2);  // Địa chỉ I2C của màn hình LCD

int toida = 40; // thiết lập khoảng cách từ cảm biến đến cuối hộp
void setup() {
  Serial.begin(9600);  // Khởi động giao tiếp Serial
  pinMode(trigPin, OUTPUT);  // Chân trig là đầu ra
  pinMode(echoPin, INPUT);   // Chân echo là đầu vào
  lcd.init();  // Khởi động màn hình LCD
  lcd.backlight();  // Bật đèn nền của LCD
  
}

void loop() {
  long duration, distance;
  digitalWrite(trigPin, LOW);   // Gửi xung LOW để đảm bảo trigger ở trạng thái ban đầu
  delayMicroseconds(2);  // Đợi 2 micro giây
  digitalWrite(trigPin, HIGH);  // Gửi xung HIGH để kích hoạt trigger
  delayMicroseconds(10);  // Đợi 10 micro giây
  digitalWrite(trigPin, LOW);   // Tắt trigger
 
  duration = pulseIn(echoPin, HIGH);  // Đọc thời gian từ chân echo
  distance = int(duration/2/29.1);   // Tính khoảng cách dựa trên thời gian và tốc độ âm thanh (tính bằng cm)
  distance = distance;
  Serial.println(distance);
  int dodai = map(distance,0,toida,toida,0);
  dodai = constrain(dodai,0,toida);
    lcd.setCursor(0, 0);  // Đặt con trỏ về vị trí (0, 0) trên LCD
  lcd.print(" DO DO DAI GIAY ");  // Hiển thị thông báo trên LCD
  
  lcd.setCursor(0, 1);  // Đặt con trỏ về vị trí (0, 0) trên LCD
  lcd.print("Do dai:      Cm");  // Hiển thị thông báo trên LCD
  lcd.setCursor(9, 1);  // Đặt con trỏ về vị trí (0, 0) trên LCD
  lcd.print(dodai);  // Hiển thị thông báo trên LCD
  delay(100);
}
