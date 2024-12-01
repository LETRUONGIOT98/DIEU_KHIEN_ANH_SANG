#define cambien D6 //Khai báo chân nhận cảm biến
#define coi D7    //Khai báo chân điều khiển qcoi
void setup() {
  pinMode(cambien, INPUT_PULLUP); //Set chân cảm biến là chân nhận tín hiệuu
  pinMode(coi, OUTPUT);///Set chân coi là chân điều khiển 
  Serial.begin(9600);
}

void loop() {

  if(digitalRead(cambien) == 0){ //Nếu phát hiện lửa còi kêu
    digitalWrite(coi, HIGH);
  }
  else {//Nếu không thì còi tắt quạt tắt
    digitalWrite(coi, LOW);
  }
}
