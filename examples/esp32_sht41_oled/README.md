# ESP32 + SHT41 + OLED 0.96" (SSD1306)

Exemplo de código Arduino para ler temperatura e humidade do sensor **SHT41** e exibir os valores em um display **OLED SSD1306 0,96"** utilizando um **ESP32**.

## Ligações sugeridas (I2C)

| ESP32 | SHT41 | OLED SSD1306 |
|-------|-------|--------------|
| 3V3   | VCC   | VCC          |
| GND   | GND   | GND          |
| GPIO21 (SDA) | SDA | SDA |
| GPIO22 (SCL) | SCL | SCL |

> Ajuste os pinos `Wire.begin(SDA, SCL)` no código caso utilize outras portas I2C.

## Dependências

Instale as bibliotecas pela IDE Arduino:

- [Adafruit SHT4x Library](https://github.com/adafruit/Adafruit_SHT4X)
- [Adafruit SSD1306](https://github.com/adafruit/Adafruit_SSD1306)
- [Adafruit GFX Library](https://github.com/adafruit/Adafruit-GFX-Library)

## Como usar

1. Copie a pasta `esp32_sht41_oled` para dentro da pasta de `sketches` da Arduino IDE ou abra diretamente o arquivo `.ino` pela IDE.
2. Conecte o ESP32 ao computador e selecione a placa correta na IDE.
3. Compile e envie o código.
4. Abra o **Serial Monitor** a 115200 bps para acompanhar as leituras.

O display mostrará a temperatura (°C) e a humidade relativa (%) atualizadas a cada 2 segundos.
