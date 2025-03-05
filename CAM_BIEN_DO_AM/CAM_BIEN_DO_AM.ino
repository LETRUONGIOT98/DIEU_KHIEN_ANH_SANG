#define cambien A0 //Khai báo chân nhận cảm biến
#define bom D6    //Khai báo chân điều khiển bơm
int gioihan = 60;
void setup() {
  pinMode(cambien, INPUT); //Set chân cảm biến quang là chân nhận tín hiệu
  pinMode(bom, OUTPUT);///Set chân led là chân điều khiển 
  Serial.begin(9600);
}

void loop() {
  int val = analogRead(cambien); //Đọc tín hiệu analog từ cảm biến
  int doam = map(val, 512, 1024, 100, 0); // Chuyển đổi giá trị analog ngưỡng từ 450-1024(8 bit) sang độ ẩm 0 -100%///Giá trị tối đa của analog 10 bit là 1024 nhưng chỉ chọn ngưỡng từi 0 đến 1020
  if(doam >= 100) doam = 100;
  Serial.print("GIA TRI DO AM: ");
  Serial.println(doam); //hiển thị giá trị analog đo được lên máy tính nếu cần
  
  if(doam <= gioihan){ //Nếu độ ẩm thấp hơn ngưỡng thì bơm chạy
    digitalWrite(bom, HIGH);
 
  }
  else {//Nếu không thì bơm tắt
    digitalWrite(bom, LOW);
  }
}
