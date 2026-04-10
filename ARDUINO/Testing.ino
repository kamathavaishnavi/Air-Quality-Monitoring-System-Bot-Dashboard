#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DHT.h>

// ---------------- OLED ----------------
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// ---------------- DHT11 ----------------
#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

// ---------------- MQ135 ----------------
#define GAS_PIN A0
int gasLevel = 0;
String quality = "Warming";

// ---------------- BUZZER ----------------
#define BUZZER_PIN 8

void setup() {
  Serial.begin(9600);

  dht.begin();
  pinMode(GAS_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  digitalWrite(BUZZER_PIN, LOW);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    while (true); // OLED error
  }

  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
}

void loop() {
  // -------- READ SENSORS --------
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();
  gasLevel = analogRead(GAS_PIN);

  if (isnan(humidity) || isnan(temperature)) {
    return;
  }

  // -------- GAS QUALITY LOGIC --------
  bool gasAlert = false;

  if (gasLevel < 151) {
    quality = "GOOD";
    gasAlert = false;
  } 
  else if (gasLevel >= 151 && gasLevel < 200) {
    quality = "POOR";
    gasAlert = true;
  } 
  else if (gasLevel >= 200 && gasLevel < 300) {
    quality = "VERY BAD";
    gasAlert = true;
  } 
  else {
    quality = "TOXIC";
    gasAlert = true;
  }

  // -------- BUZZER --------
  if (gasAlert) {
    digitalWrite(BUZZER_PIN, HIGH);
  } else {
    digitalWrite(BUZZER_PIN, LOW);
  }

  // -------- OLED DISPLAY --------
  display.clearDisplay();

  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println("Air Quality Monitor");

  display.setCursor(0, 14);
  display.print("Gas: ");
  display.println(gasLevel);

  display.setCursor(0, 24);
  display.print("Status: ");
  display.println(quality);

  display.setCursor(0, 38);
  display.print("Temp: ");
  display.print(temperature);
  display.println(" C");

  display.setCursor(0, 50);
  display.print("Hum: ");
  display.print(humidity);
  display.println(" %");

  display.display();

  // -------- SEND TO WEBSITE --------
  // Format: gas,temp,humidity
  Serial.print(gasLevel);
  Serial.print(",");
  Serial.print(temperature);
  Serial.print(",");
  Serial.print(humidity);
  Serial.println("#");

  delay(2000);
}
