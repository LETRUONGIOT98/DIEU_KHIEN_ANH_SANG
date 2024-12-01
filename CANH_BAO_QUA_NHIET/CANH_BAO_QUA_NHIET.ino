#define cambien A0 //Khai báo chân nhận cảm biến
#define led D6    //Khai báo chân điều khiển led
#define coi D7    //Khai báo chân điều khiển led
int gioihan = 50;
void setup() {
  pinMode(cambien, INPUT); //Set chân cảm biến quang là chân nhận tín hiệuu
  pinMode(led, OUTPUT);///Set chân led là chân điều khiển 
  pinMode(coi, OUTPUT);///Set chân led là chân điều khiển 
  Serial.begin(9600);
}

void loop() {
  int val = analogRead(cambien); //Đọc tín hiệu analog từ cảm biến
  int nhietdo = map(val, 430, 1020, 0, 100); // Chuyển đổi giá trị analog ngưỡng từ 450-1020 sáng pwm 255-0(8 bit)///Giá trị tối đa của analog 10 bit là 1024 nhưng chỉ chọn ngưỡng từi 0 đến 1020
  Serial.print("GIA TRI NHIET: ");
  Serial.println(nhietdo); //hiển thị giá trị analog đo được lên máy tính nếu cần
  if(nhietdo >= gioihan){ //Nếu nhiệt độ quá ngưỡng thfi còi kêu đèn nháy
    digitalWrite(coi, HIGH); //Còi kêu ở mức thấp
    digitalWrite(led, HIGH);
    delay(200);
    digitalWrite(coi, LOW);
    digitalWrite(led, LOW);
    delay(200);
  }
  else {//Nếu không thfi còi tắt đèn tắt
    digitalWrite(coi, LOW);
    digitalWrite(led, LOW);
  }
}
