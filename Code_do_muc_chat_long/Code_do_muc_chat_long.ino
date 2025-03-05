#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define cambien A0 // Định nghĩa chân cảm biến đất

// Khai báo LCD 1602 I2C tại địa chỉ 0x27
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.begin();            // Khởi động LCD
  lcd.backlight();        // Bật đèn nền LCD
  pinMode(cambien, INPUT);// Thiết lập chân cảm biến là đầu vào
 
}

void loop() {
  int val = analogRead(cambien);  // Đọc giá trị từ cảm biến đất
  int giatri = map(val, 530, 210, 0, 100); // Quy đổi giá trị ra %
  
  // Bảo đảm giá trị trong khoảng 0 - 100
  if (giatri <= 0) giatri = 0;
  if (giatri > 100) giatri = 100;

  // Hiển thị độ ẩm lên LCD
  lcd.setCursor(0, 0);
  lcd.print("Muc chat long: ");
  lcd.setCursor(0, 1);
  lcd.print(giatri);
  lcd.print("%   "); // In thêm khoảng trắng để xóa dư ký tự cũ

  delay(1000); // Độ trễ 1 giây
}
