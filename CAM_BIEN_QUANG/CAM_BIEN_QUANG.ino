// Khai báo chân kết nối
const int sensorPin = A0;  // Chân đọc giá trị từ cảm biến quang trở
const int ledPin = 13;      // Chân điều khiển đèn LED

// Đặt ngưỡng ánh sáng để bật/tắt đèn
const int threshold = 40;  // Ngưỡng độ sáng %

void setup() {
  // Khởi tạo chân LED làm OUTPUT
  pinMode(ledPin, OUTPUT);
  
  // Khởi tạo giao tiếp Serial để hiển thị giá trị
  Serial.begin(9600);
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

  // Điều khiển đèn LED theo ngưỡng cường độ sáng
  if (lightIntensity < threshold) {
    // Nếu ánh sáng yếu (giá trị cảm biến nhỏ hơn ngưỡng), bật đèn
    digitalWrite(ledPin, HIGH);
  } else {
    // Nếu ánh sáng đủ mạnh (giá trị cảm biến lớn hơn ngưỡng), tắt đèn
    digitalWrite(ledPin, LOW);
  }

  // Tạm dừng một chút trước khi lặp lại
  delay(100);
}
