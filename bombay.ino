#include <Servo.h>
#include <SoftwareSerial.h>

SoftwareSerial XBee(10, 11); // RX, TX
Servo myservo;  // create servo object to control a servo
float pos = 10;    // variable to store the servo position

void openServo() {
  while (pos >= 10) {
    myservo.write(pos - 1.5);
    pos -= 1.5;
    delay(13);
  }
}

void closeServo() {
  while (pos <= 180) {
    myservo.write(pos + 1.5);
    pos += 1.5;
    delay(13);
  }
}

void setup() {
  // put your setup code here, to run once:
  myservo.attach(16);
  XBee.begin(9600);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (XBee.available()) {
    byte input = XBee.read();
    Serial.write(input);
    if (input == '0') {
      Serial.println("Opening");
      openServo();
    } else if(input == '1') {
      Serial.println("Closeing");
      closeServo();
    }
  }
}
