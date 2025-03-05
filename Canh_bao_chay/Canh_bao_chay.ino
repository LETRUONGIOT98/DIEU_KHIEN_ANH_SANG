#define cambien 2   //Chân kết nối với càm biến lửa là chân 2 arduino
#define led  3 //Chân kết nối với đèn led là chân 3
#define coi 4 // chân kết nối với còi là chân 4
void setup() {
  Serial.begin(9600);  //Set tốc độ giao tiếp với máy tính
  pinMode(cambien, INPUT_PULLUP);///////Set chân nối với cảm biến là chân nhận tín hiệu
  pinMode(led, OUTPUT);// set chân led là chân điều khiển
  pinMode(coi, OUTPUT);// set chân coi là chân điều khiển
}

void loop() {
  if(digitalRead(cambien) == 0){
    Serial.println("PHAT HIEN CO CHAY");
    digitalWrite(coi, HIGH);
    digitalWrite(led, HIGH);
    delay(100);
    digitalWrite(coi, LOW);
    digitalWrite(led, LOW);
    delay(50);
  }
  else Serial.println("BINH THUONG");
}
