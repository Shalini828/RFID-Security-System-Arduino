# 🔐 RFID-Based Smart Security System using Arduino UNO

## 📌 Project Overview
This project is an RFID-based smart security system developed using Arduino UNO, MFRC522 RFID module, and DS3231 RTC module.

The system verifies authorized RFID cards and logs the access time using a Real-Time Clock (RTC). An LED indicator provides visual feedback for successful authentication.

---

## 🛠 Hardware Components Used

- Arduino UNO  
- MFRC522 RFID Module  
- DS3231 RTC Module  
- LED (with 220Ω resistor)  
- Breadboard  
- Jumper Wires  

---

## ⚙ System Working

1. When an RFID card is scanned:
   - The system reads the card UID.
2. The UID is compared with a pre-defined authorized UID.
3. If matched:
   - Access is granted.
   - LED turns ON.
   - Current date & time is displayed in Serial Monitor.
4. If not matched:
   - Access is denied.
   - Access attempt is still logged with timestamp.

---

## 🔌 Pin Configuration

### RFID RC522 → Arduino UNO

| RFID Pin | Arduino Pin |
|-----------|-------------|
| SDA       | D10 |
| SCK       | D13 |
| MOSI      | D11 |
| MISO      | D12 |
| RST       | D9 |
| 3.3V      | 3.3V |
| GND       | GND |

### RTC DS3231 → Arduino UNO

| RTC Pin | Arduino Pin |
|----------|-------------|
| SDA      | A4 |
| SCL      | A5 |
| VCC      | 5V |
| GND      | GND |

### LED

D3 → 220Ω resistor → LED (+)  
LED (-) → GND  

---

## 🔧 Hardware Setup

![Hardware Setup](hardware-setup.jpg)

---

## 💻 Software & Libraries Used

- Arduino IDE  
- MFRC522 Library  
- RTClib (Adafruit)  
- SPI Library  
- Wire Library  

---

## 📊 Project Status

This project was built and tested as part of an academic submission.  
The system was verified during implementation and successfully demonstrated RFID authentication with real-time logging.

---

## 🚀 Future Improvements

- Add Servo motor for door lock mechanism  
- Add buzzer alert system  
- Store logs in EEPROM or SD card  
- Web dashboard integration (IoT-based system)  

---

## 👩‍💻 Author

Shalini Kumari
