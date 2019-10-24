#ifdef ESP32
#include <ThingerESP32.h>
#else
#include <ThingerESP8266.h>
#endif

#include <DHT.h>

#define USERNAME "username"
#define DEVICE_ID "ESP"
#define DEVICE_CREDENTIAL "Teste12345"

#define SSID "Curso_IoT"
#define SSID_PASSWORD "0123456789"

/* Configuraçao da conexao com o Thinger.io */
#ifdef ESP32
#define DHTPIN 4
ThingerESP32 thing(USERNAME, DEVICE_ID, DEVICE_CREDENTIAL);
#else
#define DHTPIN D4
ThingerESP8266 thing(USERNAME, DEVICE_ID, DEVICE_CREDENTIAL);
#endif

/* Configuraçao do sensor de temperatura e umidade.
   Pino, Modelo
*/
DHT dht(DHTPIN, DHT11);

void setup() {

  /* Inicia conexao com o thinger.io */   
  thing.add_wifi(SSID, SSID_PASSWORD);

  /* Inicia o funcionamento do sensor de temperatura e umidade. */
  dht.begin();  

  /* Envia a humidade */
  thing["Humidade"] >> outputValue(dht.readHumidity());

  /* Envia a temperatura */
  thing["Temperatura"] >> outputValue(dht.readTemperature());
}

void loop() {
  thing.handle();
}
