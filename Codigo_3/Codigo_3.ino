#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_BME280.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET     -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

Adafruit_BME280 bme;

#define BUTTON_BASE 12
#define BUTTON_TOP  4

float basePressure = 0.0;
float topPressure = 0.0;
float relativeAltitude = 0.0;
bool baseSet = false;
bool topSet = false;

void setup() {
  Serial.begin(115200);
  pinMode(BUTTON_BASE, INPUT_PULLUP);
  pinMode(BUTTON_TOP, INPUT_PULLUP);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("OLED não encontrada"));
    while (true);
  }

  if (!bme.begin(0x76)) {
    Serial.println(F("BME280 não encontrado"));
    while (true);
  }

  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
  display.setTextSize(1);
  display.setCursor(15, 0);
  display.println("BAROMETRIC");
  display.setCursor(20, 12);
  display.println("ALTIMETER");
  display.display();
  delay(2000);
}

void loop() {
  float temp = bme.readTemperature();
  float pres = bme.readPressure() / 100.0F; // hPa
  float hum = bme.readHumidity();
  float altSea = 44330.0 * (1.0 - pow(pres / 1013.25, 0.1903)); // Altitud nivel mar

  // RESET si ambos botones están presionados
  if (digitalRead(BUTTON_BASE) == LOW && digitalRead(BUTTON_TOP) == LOW) {
    basePressure = 0;
    topPressure = 0;
    relativeAltitude = 0;
    baseSet = false;
    topSet = false;

    display.clearDisplay();
    display.setCursor(0, 0);
    display.println("BAROMETRIC");
    display.setCursor(0, 16);
    display.println("ALTIMETER");
    display.setCursor(0, 40);
    display.println("RESET realizado");
    display.display();
    delay(1500);
  } 
  else if (digitalRead(BUTTON_BASE) == LOW && !baseSet) {
    basePressure = pres;
    baseSet = true;

    display.clearDisplay();
    display.setCursor(0, 0);
    display.println("Base marcada:");
    display.setCursor(0, 20);
    display.print(basePressure);
    display.println(" hPa");
    display.display();
    delay(1000);
  } 
  else if (digitalRead(BUTTON_TOP) == LOW && baseSet && !topSet) {
    topPressure = pres;
    topSet = true;
    relativeAltitude = 44330.0 * (1.0 - pow(topPressure / basePressure, 0.1903));

    display.clearDisplay();
    display.setCursor(0, 0);
    display.println("Cima marcada:");
    display.setCursor(0, 16);
    display.print(topPressure);
    display.println(" hPa");
    display.setCursor(0, 36);
    display.print("Altura: ");
    display.print(relativeAltitude, 1);
    display.println(" m");
    display.display();
    delay(2000);
  }

  // Vista en reposo: datos + altitud nivel mar
  if (!baseSet || !topSet) {
    display.clearDisplay();
    display.setCursor(0, 0);
    display.println(" BAROMETRIC");
    display.setCursor(0, 12);
    display.println("  ALTIMETER");

    display.setCursor(0, 26);
    display.print("Temp: ");
    display.print(temp, 1);
    display.println(" C");

    display.setCursor(0, 36);
    display.print("Hum:  ");
    display.print(hum, 1);
    display.println(" %");

    display.setCursor(0, 46);
    display.print("Pres: ");
    display.print(pres, 1);
    display.println(" hPa");

    display.setCursor(0, 56);
    display.print("Alt nivel mar: ");
    display.print(altSea, 0);
    display.println(" m");
    display.display();
  }

  delay(500);
}
