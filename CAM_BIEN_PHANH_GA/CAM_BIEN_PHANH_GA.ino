#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Khai báo địa chỉ I2C và kích thước của LCD
LiquidCrystal_I2C lcd(0x27, 16, 2); // Thay 0x27 bằng địa chỉ I2C của bạn nếu cần

void setup() {
  Serial.begin(9600);
    // Khởi động giao tiếp I2C và LCD
    lcd.init();
    lcd.backlight();

    // Thiết lập các chân đầu vào
    pinMode(A0, INPUT); // Cảm biến mức ga
    pinMode(A1, INPUT); // Cảm biến mức phanh

    // Hiển thị thông báo khởi động trên LCD
    lcd.setCursor(0, 0);
    lcd.print("Init Complete");
    delay(2000); // Dừng 2 giây để người dùng thấy thông báo
    lcd.clear();
}

void loop() {
    // Đọc giá trị analog từ các cảm biến
    int rawGa = analogRead(A0);
    int rawphanh = analogRead(A1);

    // Chuyển đổi giá trị từ 0-1023 sang 0-100
    int GaLevel = map(rawGa, 0, 1023, 0, 100);
    int phanhLevel = map(rawphanh, 0, 1023, 0, 100);

    // Hiển thị giá trị mức ga và mức phanh trên LCD
    lcd.setCursor(0, 0); // Dòng đầu tiên
    lcd.print("Ga: ");
    lcd.print(GaLevel);
    lcd.print("%  ");

    lcd.setCursor(0, 1); // Dòng thứ hai
    lcd.print("phanh: ");
    lcd.print(phanhLevel);
    lcd.print("%  ");
    Serial.print(GaLevel);
    Serial.print("   ");
    Serial.println(phanhLevel);

    delay(100); // Đợi 100ms trước khi cập nhật giá trị
}
