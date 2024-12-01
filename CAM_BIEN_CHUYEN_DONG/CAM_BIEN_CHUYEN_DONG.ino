#define cambien 2 //Khai báo chân nhận cảm biến
#define den A4    //Khai báo chân điều khiển qden
void setup() {
  pinMode(cambien, INPUT_PULLUP); //Set chân cảm biến là chân nhận tín hiệuu
  pinMode(den, OUTPUT);///Set chân den là chân điều khiển 
  Serial.begin(9600);
}

void loop() {

  if(digitalRead(cambien) == 1){ //Nếu phát hiện chuyển động thfi đèn sáng
    digitalWrite(den, HIGH);
  }
  else {//Nếu không thì đèn tắt
    digitalWrite(den, LOW);
  }
}
