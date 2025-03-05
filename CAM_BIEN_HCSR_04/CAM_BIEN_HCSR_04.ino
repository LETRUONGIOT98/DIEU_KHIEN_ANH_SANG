// Khai báo chân kết nối
#define TRIG_PIN 3
#define ECHO_PIN 2
#define RELAY_PIN 4

// Khoảng cách thiết lập (cm)
const int setDistance = 40;

void setup() {
  // Khởi tạo các chân
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(RELAY_PIN, OUTPUT);
  
  // Khởi tạo relay tắt ban đầu
  digitalWrite(RELAY_PIN, LOW);

  // Khởi tạo Serial Monitor
  Serial.begin(9600);
  Serial.println("HCSR04 Distance Sensor");
  Serial.print("Set Distance: ");
  Serial.print(setDistance);
  Serial.println(" cm");
}

void loop() {
  // Đo khoảng cách
  long duration;
  float distance;

  // Gửi tín hiệu Trigger
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Nhận tín hiệu Echo
  duration = pulseIn(ECHO_PIN, HIGH);
  distance = duration * 0.034 / 2; // Tính khoảng cách (cm)

  // Kiểm tra điều kiện bật/tắt relay
  if (distance < setDistance) {
    digitalWrite(RELAY_PIN, HIGH); // Bật relay
  } else {
    digitalWrite(RELAY_PIN, LOW); // Tắt relay
  }

  // In khoảng cách ra Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Đợi một chút trước khi đo lại
  delay(500);
}
