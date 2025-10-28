#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_SHT4x.h>

// OLED display resolution
constexpr uint8_t SCREEN_WIDTH = 128;
constexpr uint8_t SCREEN_HEIGHT = 64;

// Reset pin is not used with I2C OLED, but the constructor expects one
constexpr int8_t OLED_RESET_PIN = -1;

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET_PIN);
Adafruit_SHT4x sht41;

void setup() {
  Serial.begin(115200);
  while (!Serial) {
    delay(10);
  }

  // Ajuste os pinos abaixo caso utilize outra combinação SDA/SCL.
  Wire.begin(21, 22);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("Falha ao inicializar a tela OLED"));
    for (;;) {
      delay(10);
    }
  }
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.cp437(true); // Permite usar o símbolo de grau (°)
  display.setCursor(0, 0);
  display.println(F("Inicializando..."));
  display.display();

  if (!sht41.begin()) {
    Serial.println(F("Falha ao encontrar o sensor SHT41"));
    display.clearDisplay();
    display.setCursor(0, 0);
    display.println(F("SHT41 nao encontrado"));
    display.display();
    for (;;) {
      delay(10);
    }
  }

  // Opcional: configurar modo de precisão e aquecimento
  sht41.setPrecision(SHT4X_HIGH_PRECISION);
  sht41.setHeater(SHT4X_NO_HEATER);

  Serial.println(F("Sensor SHT41 inicializado"));
  display.clearDisplay();
  display.setCursor(0, 0);
  display.println(F("SHT41 pronto"));
  display.display();
  delay(1000);
}

void loop() {
  sensors_event_t humidityEvent, tempEvent;
  if (sht41.getEvent(&humidityEvent, &tempEvent) != 0) {
    Serial.println(F("Erro ao ler dados do SHT41"));
    display.clearDisplay();
    display.setCursor(0, 0);
    display.println(F("Erro de leitura"));
    display.display();
    delay(2000);
    return;
  }

  float temperature = tempEvent.temperature;
  float humidity = humidityEvent.relative_humidity;

  Serial.print(F("Temperatura: "));
  Serial.print(temperature, 2);
  Serial.println(F(" *C"));

  Serial.print(F("Humidade: "));
  Serial.print(humidity, 2);
  Serial.println(F(" %"));

  display.clearDisplay();
  display.setCursor(0, 0);
  display.setTextSize(1);
  display.println(F("Leitura SHT41"));
  display.drawLine(0, 10, SCREEN_WIDTH, 10, SSD1306_WHITE);
  display.setCursor(0, 16);
  display.setTextSize(2);
  display.print(temperature, 1);
  display.write((char)247); // símbolo de grau
  display.print(F("C"));

  display.setCursor(0, 40);
  display.setTextSize(2);
  display.print(humidity, 1);
  display.print(F(" %"));

  display.display();

  delay(2000);
}
