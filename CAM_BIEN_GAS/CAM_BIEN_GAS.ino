#define cambien D7 //Khai báo chân nhận cảm biến
#define quat_coi D6    //Khai báo chân điều khiển quat_coi 
void setup() {
  pinMode(cambien, INPUT_PULLUP); //Set chân cảm biến  là chân nhận tín hiệuu
  pinMode(quat_coi, OUTPUT);///Set chân quat_coi là chân điều khiển 
  Serial.begin(9600);
}

void loop() {

  if(digitalRead(cambien) == 0){ //Nếu có khí gas còi kêu quạt bật
    digitalWrite(quat_coi, HIGH);
  }
  else {//Nếu không thì còi tắt quạt tắt
    digitalWrite(quat_coi, LOW);
  }
}
