#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP085_U.h>
#include <LiquidCrystal_I2C.h>

// Khai báo LCD với địa chỉ 0x27 và kích thước 16x2
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Khai báo đối tượng BMP180
Adafruit_BMP085_Unified bmp;

float pressure;  // Biến để lưu trữ giá trị áp suất

void setup() {
  // Khởi tạo LCD
  lcd.init();
  lcd.backlight();
   Serial.begin(9600);
  // Khởi tạo BMP180
  if (!bmp.begin()) {
    lcd.print("BMP180 error!");
    while (1);  // Dừng lại nếu không tìm thấy BMP180
  }

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("BMP180 initialized");
  delay(2000);  // Hiển thị thông báo trong 2 giây
}

void loop() {
  // Lấy giá trị áp suất
  bmp.getPressure(&pressure);

  // Hiển thị áp suất lên LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Press: ");
  lcd.setCursor(0, 1);
  lcd.print(pressure / 100);  // Áp suất tính bằng hPa
  lcd.print(" hPa   ");
  Serial.println(pressure / 100);
  delay(500);  // Cập nhật dữ liệu mỗi 0.5 giây
}
