# Código de Exemplo para ESP32 - Monitor de Temperatura e Umidade com SHT41

Este diretório contém um código de exemplo para ser usado em um microcontrolador ESP32. O programa lê dados de um sensor de temperatura e umidade (Adafruit SHT41) e os envia para o backend da sua aplicação web via uma requisição HTTP POST.

## Pré-requisitos

### Hardware
- ESP32 (qualquer modelo)
- Sensor de Temperatura e Umidade Adafruit SHT41
- Jumpers para conexão

### Software (Escolha uma opção)

#### 1. PlatformIO com Visual Studio Code (Recomendado)
- [Visual Studio Code](https://code.visualstudio.com/)
- [Extensão PlatformIO IDE](https://platformio.org/install/ide?install=vscode)

Crie um novo projeto no PlatformIO e adicione as seguintes bibliotecas ao seu arquivo `platformio.ini`:
```ini
[env:esp32dev]
platform = espressif32
board = esp32dev
framework = arduino
lib_deps =
  adafruit/Adafruit SHT4x Library
  adafruit/Adafruit BusIO
  bblanchon/ArduinoJson
```

#### 2. Arduino IDE
- [Arduino IDE](https://www.arduino.cc/en/software)
- Instale o suporte para placas ESP32 na IDE do Arduino.
- Pelo Gerenciador de Bibliotecas, instale as seguintes bibliotecas:
  - `Adafruit SHT4x Library` by Adafruit
  - `Adafruit BusIO` by Adafruit
  - `ArduinoJson` by Benoit Blanchon

## Como Usar

1.  **Conecte o Hardware (I2C):**
    - Conecte o pino **Vin** ou **VCC** do sensor SHT41 ao pino **3.3V** do ESP32.
    - Conecte o pino **GND** do sensor SHT41 ao pino **GND** do ESP32.
    - Conecte o pino **SCL** (Serial Clock) do sensor ao pino **GPIO 22** do ESP32.
    - Conecte o pino **SDA** (Serial Data) do sensor ao pino **GPIO 21** do ESP32.

2.  **Configure o Código:**
    - Abra o arquivo `main.cpp`.
    - Altere as seguintes linhas com as suas informações:
      ```cpp
      // --- Configurações do Wi-Fi ---
      const char* WIFI_SSID = "SUA_REDE_WIFI";       // <<<<<<< COLOQUE O NOME DA SUA REDE
      const char* WIFI_PASSWORD = "SUA_SENHA_WIFI";  // <<<<<<< COLOQUE A SENHA DA SUA REDE

      // --- Configurações do Servidor ---
      // Use a URL fornecida pelo Firebase App Hosting ao fazer o deploy.
      const char* SERVER_URL = "URL_DO_SEU_APP/api/data"; // <<<<<<< COLOQUE A URL DO SEU APP
      ```

3.  **Compile e Envie:**
    - Conecte o ESP32 ao seu computador via USB.
    - Compile e envie o código usando o PlatformIO ou a IDE do Arduino.

4.  **Monitore:**
    - Abra o Monitor Serial para ver os logs de conexão, leituras do sensor e respostas do servidor. A taxa de transmissão (baud rate) é `115200`.

Agora, seu ESP32 estará enviando dados do sensor SHT41 para a sua aplicação a cada 30 segundos!
