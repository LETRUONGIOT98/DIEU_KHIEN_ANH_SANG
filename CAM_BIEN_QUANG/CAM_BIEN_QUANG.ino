#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Khai báo chân kết nối
const int sensorPin = A0;   // Chân đọc giá trị từ cảm biến quang trở
const int ledPin = 13;      // Chân điều khiển đèn LED

// Đặt ngưỡng ánh sáng để bật/tắt đèn
const int threshold = 40;   // Ngưỡng độ sáng %

LiquidCrystal_I2C lcd(0x27, 16, 2); // Địa chỉ I2C của LCD (thường là 0x27 hoặc 0x3F)

void setup() {
  // Khởi tạo chân LED làm OUTPUT
  pinMode(ledPin, OUTPUT);

  // Khởi tạo giao tiếp Serial để hiển thị giá trị
  Serial.begin(9600);

  // Khởi tạo LCD
  lcd.init();
  lcd.backlight(); // Bật đèn nền LCD
  lcd.clear();
  lcd.setCursor(0, 0); 
  lcd.clear();
}

void loop() {
  // Đọc giá trị từ cảm biến quang trở (giá trị từ 0 đến 1023)
  int sensorValue = analogRead(sensorPin);

  // Chuyển giá trị cảm biến sang tỷ lệ phần trăm (0-100%)
  float lightIntensity = map(sensorValue, 0, 1023, 100, 0);

  // Hiển thị giá trị cường độ sáng lên Serial Monitor
  Serial.print("Cường độ sáng: ");
  Serial.print(lightIntensity);
  Serial.println("%");

  // Hiển thị giá trị lên LCD
  lcd.setCursor(0, 0); // Dòng đầu tiên
  lcd.print("Do sang: ");
  lcd.print(lightIntensity, 0); // Hiển thị 1 chữ số thập phân
  lcd.print(" %");

  lcd.setCursor(0, 1); // Dòng thứ hai
  lcd.print("ADC: ");
  lcd.print(sensorValue);

  // Điều khiển đèn LED theo ngưỡng cường độ sáng
  if (lightIntensity < threshold) {
    // Nếu ánh sáng yếu (giá trị cảm biến nhỏ hơn ngưỡng), bật đèn
    digitalWrite(ledPin, HIGH);
  } else {
    // Nếu ánh sáng đủ mạnh (giá trị cảm biến lớn hơn ngưỡng), tắt đèn
    digitalWrite(ledPin, LOW);
  }

  // Tạm dừng một chút trước khi lặp lại
  delay(200);
}
