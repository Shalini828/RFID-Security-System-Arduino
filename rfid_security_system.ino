#include <SPI.h>
#include <MFRC522.h>
#include <Wire.h>
#include "RTClib.h"
#include <Servo.h>

#define SS_PIN 10
#define RST_PIN 9
#define LED_PIN 3
#define SERVO_PIN 5

MFRC522 mfrc522(SS_PIN, RST_PIN);
RTC_DS3231 rtc;
Servo doorServo;

// Replace with your actual authorized UID
byte authorizedUID[4] = {0xDE, 0xAD, 0xBE, 0xEF};

void setup() {
  Serial.begin(9600);
  SPI.begin();
  Wire.begin();
  mfrc522.PCD_Init();
  rtc.begin();

  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);

  doorServo.attach(SERVO_PIN);
  doorServo.write(0); // Locked position

  Serial.println("RFID Smart Door Lock System Ready...");
}

void loop() {

  if (!mfrc522.PICC_IsNewCardPresent()) return;
  if (!mfrc522.PICC_ReadCardSerial()) return;

  DateTime now = rtc.now();
  bool accessGranted = true;

  for (byte i = 0; i < 4; i++) {
    if (mfrc522.uid.uidByte[i] != authorizedUID[i]) {
      accessGranted = false;
      break;
    }
  }

  Serial.print("Card UID: ");
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    Serial.print(mfrc522.uid.uidByte[i], HEX);
    Serial.print(" ");
  }
  Serial.println();

  Serial.print("Date & Time: ");
  Serial.print(now.day());
  Serial.print("/");
  Serial.print(now.month());
  Serial.print("/");
  Serial.print(now.year());
  Serial.print(" ");
  Serial.print(now.hour());
  Serial.print(":");
  Serial.print(now.minute());
  Serial.print(":");
  Serial.println(now.second());

  if (accessGranted) {
    Serial.println("Access Granted ✅");
    
    digitalWrite(LED_PIN, HIGH);

    doorServo.write(90);  // Unlock (rotate servo)
    delay(3000);          // Keep unlocked for 3 seconds
    doorServo.write(0);   // Lock again

    digitalWrite(LED_PIN, LOW);

  } else {
    Serial.println("Access Denied ❌");
  }

  Serial.println("--------------------------");
  mfrc522.PICC_HaltA();
}
