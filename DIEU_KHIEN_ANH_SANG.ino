#define cambien A0 //Khai báo chân nhận cảm biến
#define led D6     //Khai báo chân điều khiển led
void setup() {
  pinMode(cambien, INPUT); //Set chân cảm biến quang là chân nhận tín hiệuu
  pinMode(led, OUTPUT);///Set chân led là chân điều khiển 
  Serial.begin(9600);
}

void loop() {
  int dosang = analogRead(cambien); //Đọc tín hiệu analog từ cảm biến
  int pwm = map(dosang, 0, 1020, 255, 0); // Chuyển đổi giá trị analog ngưỡng từ 0-1020 sáng pwm 255-0(8 bit)///Giá trị tối đa của analog 10 bit là 1024 nhưng chỉ chọn ngưỡng từi 0 đến 1020
  Serial.print("GIA TRI ANALOG: ");
  Serial.println(dosang); //hiển thị giá trị analog đo được lên máy tính nếu cần
  analogWrite(led, pwm); // Điều khiển độ sáng led theo giá trị pwm đã nhận được ở trên
  Serial.print("GIA TRI PWM: ");
  Serial.println(pwm); //hiển thị giá trị analog đo được lên máy tính nếu cần
  delay(100);  //Chờ 1 thời gian trước khi bắt đầu lại
}
