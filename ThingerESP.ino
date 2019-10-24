#include <ThingerESP32.h>
#include <DHT.h>

#define USERNAME "crmoratelli"
#define DEVICE_ID "ESP32"
#define DEVICE_CREDENTIAL "Teste12345"

#define SSID "Curso_IoT"
#define SSID_PASSWORD "0123456789"

/* Configuraçao da conexao com o Thinger.io */
ThingerESP32 thing(USERNAME, DEVICE_ID, DEVICE_CREDENTIAL);

/* Configuraçao do sensor de temperatura e umidade.
   Pino, Modelo
*/
DHT dht(4, DHT11);

void setup() {
  /* Inicia conexao com o thinger.io */   
  thing.add_wifi(SSID, SSID_PASSWORD);

  /* Inicia o funcionamento do sensor de temperatura e umidade. */
  dht.begin();  

  /* Envia a humidade */
  thing["Humidade"] >> outputValue(dht.readTemperature());

  /* Envia a temperatura */
  thing["Temperatura"] >> outputValue(dht.readHumidity());
}

void loop() {
  thing.handle();
}
