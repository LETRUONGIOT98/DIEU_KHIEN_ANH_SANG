#define PIR 2  /// Chân kết nối với PIR
#define LDR 4  /// Chân kết nối với LDR
#define led 3  // Chân kết nối với led
#include <Wire.h>
#include "RTClib.h"
RTC_DS3231 rtc;
#include <Servo.h>
int khunggioMinHour = 18; // Giờ bắt đầu khung giờ kiểm soát ánh sáng
int khunggioMinMinute = 30; // Phút bắt đầu khung giờ kiểm soát ánh sáng
int khunggioMaxHour = 22; // Giờ kết thúc khung giờ kiểm soát ánh sáng
int khunggioMaxMinute = 40; // Phút kết thúc khung giờ kiểm soát ánh sáng


void setup() {
  pinMode(LDR, INPUT);  // Set chân kết nối LDR là chân nhận tín hiệu
  pinMode(PIR, INPUT);  // Set chân kết nối PIR là chân nhận tín hiệu
  pinMode(led, OUTPUT); // Set chân kết nối led là chân xuất tín hiệu
  Serial.begin(9600);   // Khởi động giao tiếp với máy tính tốc độ baud là 9600
  if (! rtc.begin()) {  // Kiểm tra xem RTC có hoạt động hay không
    Serial.println("Couldn't find RTC"); // Thông báo nếu không tìm thấy RTC
    while (1); // Dừng chương trình nếu không tìm thấy RTC
  }

  if (rtc.lostPower()) { // Kiểm tra xem RTC có bị mất nguồn hay không
    Serial.println("RTC SET TIME!"); // Thông báo rằng RTC cần được đặt lại thời gian
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__))); // Đặt lại thời gian cho RTC bằng thời gian hiện tại khi biên dịch
  }
}
bool isWithinTimeFrame(DateTime now) {
  // Tạo thời gian bắt đầu và kết thúc bằng cách sử dụng giờ và phút
  DateTime startTime(now.year(), now.month(), now.day(), khunggioMinHour, khunggioMinMinute, 0);
  DateTime endTime(now.year(), now.month(), now.day(), khunggioMaxHour, khunggioMaxMinute, 0);

  // Kiểm tra nếu thời gian hiện tại nằm trong khung giờ
  return (now >= startTime && now <= endTime);
}
void loop() {
  DateTime now = rtc.now(); // Lấy thời gian hiện tại từ RTC
  Serial.println("Current Date & Time: "); // In ngày giờ hiện tại lên Serial Monitor
  Serial.print(now.year(), DEC); // In năm hiện tại
  Serial.print('/');
  Serial.print(now.month(), DEC); // In tháng hiện tại
  Serial.print('/');
  Serial.print(now.day(), DEC); // In ngày hiện tại
  Serial.print(" ---- ");
  Serial.print(now.hour(), DEC); // In giờ hiện tại
  Serial.print(':');
  Serial.print(now.minute(), DEC); // In phút hiện tại
  Serial.print(':');
  Serial.print(now.second(), DEC); // In giây hiện tại
  Serial.println();
  
  // Điều kiện kiểm tra và điều khiển LED
  if ((digitalRead(PIR) == 0 && digitalRead(LDR) == 0)|| !isWithinTimeFrame(now)) {  // Nếu không có chuyển động và trời không sáng hoặc trời sáng và khác khung giờ
    Serial.println("TROI DANG SANG VA KHONG CO CHUYEN DONG");  // In trạng thái lên Serial monitor máy tính 
    analogWrite(led, 0); // Độ sáng 0% của 255 khi không có chuyển động và trời sáng
  } 
  else if (digitalRead(PIR) == 0 && digitalRead(LDR) == 1 && isWithinTimeFrame(now)) {  // Nếu không có chuyển động và trời tối trong khung giờ
    Serial.println("TROI DANG TOI VA KHONG CO CHUYEN DONG");  // In trạng thái lên Serial monitor máy tính 
    analogWrite(led, 76); // Độ sáng ~30% của 255 khi không có chuyển động và trời đang tối
  } 
  else if (digitalRead(PIR) == 1 && digitalRead(LDR) == 1 && isWithinTimeFrame(now)) { //  // Nếu có chuyển động và trời tối trong khung giờ
    Serial.println("TROI DANG TOI VA CO CHUYEN DONG");  // In trạng thái lên Serial monitor máy tính 
    analogWrite(led, 255); // Độ sáng 100% của 255 khi có chuyển động và trời đang tối
  } 
  else if ((digitalRead(PIR) == 1 && digitalRead(LDR) == 0) || !isWithinTimeFrame(now)) { // Nếu có chuyển động hoặc trời sáng và khác khung giờ
    Serial.println("TROI DANG SANG VA CO CHUYEN DONG");  // In trạng thái lên Serial monitor máy tính 
    analogWrite(led, 0); // Độ sáng 0% của 255 khi có chuyển động và trời sáng
  }
  delay(100); // Đợi 100ms trước khi lặp lại
}
