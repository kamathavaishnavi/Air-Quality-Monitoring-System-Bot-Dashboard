**Air Quality Monitoring System**

**📌 Overview**

This project is a low-cost IoT-based Air Quality Monitoring System designed to monitor indoor environmental conditions in real time. It detects harmful gases, temperature, and humidity, and provides alerts to ensure a safe and healthy environment.


**🎯 Features**

* ✅ Detects harmful gases using MQ135 gas sensor
* ✅ Measures temperature and humidity using DHT11 sensor
* ✅ Displays real-time data on OLED display
* ✅ Live monitoring through web dashboard
* ✅ Instant alert using buzzer for poor air quality
* ✅ Real-time notifications using Telegram Bot


**🛠️ Technologies Used**

* Arduino Uno
* MQ135 Gas Sensor
* DHT11 Sensor
* OLED Display (I2C)
* Node.js
* HTML, CSS, JavaScript
* Web Serial Communication
* Telegram Bot API


**⚙️ Setup Instructions**

🔹 1. Hardware Setup

* Connect components to **Arduino Uno**:

  * MQ135 → Analog Pin (A0)
  * DHT11 → Digital Pin
  * OLED → I2C (SDA, SCL)
  * Buzzer → Digital Pin
* Ensure proper power supply and wiring


**🔹 2. Arduino Setup**

1. Install Arduino IDE
2. Install required libraries:

   * DHT sensor library
   * Adafruit SSD1306 (OLED)
   * Adafruit GFX
3. Open Arduino code
4. Select board: **Arduino Uno**
5. Select correct COM Port
6. Click **Upload**


**🔹 3. Node.js Setup (Backend)**

1. Install Node.js
2. Open project folder in terminal
3. Install dependencies:
npm install
4. Run server:
node server.js

## 🔹 4. Web Dashboard Setup

1. Open the web project folder
2. Open `index.html` in browser (Chrome recommended)
3. Click **Connect Arduino**
4. Select correct serial port



**🔹 5. Telegram Bot Setup**

1. Create bot using **BotFather**
2. Get **Bot Token**
3. Get your **Chat ID**
4. Add token & chat ID in your code
5. Run the system → alerts will be sent


**🔹 6. Running the Project**

* Power ON Arduino
* Start Node.js server
* Open web dashboard
* Monitor real-time data
* Trigger alert by increasing gas concentration (demo)


**⚙️ System Working**

1. MQ135 sensor detects gas levels in the environment
2. DHT11 measures temperature and humidity
3. Arduino Uno processes the sensor data
4. Data is displayed on OLED screen
5. Data is sent to web dashboard for real-time monitoring
6. If gas level exceeds threshold:

   * Buzzer is activated
   * Telegram alert is sent to user


**📊 Applications**

* Indoor air quality monitoring (homes, classrooms, offices)
* Laboratories and industrial safety
* Smart IoT-based environmental monitoring systems


**🚀 Future Scope**

* Integration with Wi-Fi modules (ESP8266/ESP32)
* Cloud storage and data analytics
* Mobile application development
* AI-based air quality prediction
* Outdoor air quality monitoring


**👩‍💻 Author**

**A Vaishnavi Kamath**
Student Project – IoT Based Air Quality Monitoring System


**📢 Note**

This project is developed for educational purposes to demonstrate real-time environmental monitoring using IoT concepts.
