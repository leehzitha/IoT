#include "time.h"
#include <WiFi.h>

const char* servidor = "pool.ntp.org";
const long fuso = -10800; //-3h . 3600
const int verao = 0;

const char* ssid = "lele";
const char* password = "20070318";

void WiFiEvent(WiFiEvent_t event) {
  switch(event) {
    case ARDUINO_EVENT_WIFI_STA_GOT_IP:
      Serial.println("conectadinho");
      break;
    case ARDUINO_EVENT_WIFI_STA_DISCONNECTED:
      Serial.println("desconectado");
      WiFi.reconnect();
      break;
  }
}

void setup() {
  Serial.begin(9600);
  configTime(fuso, verao, servidor);
  WiFi.onEvent(WiFiEvent);
  WiFi.begin(ssid, password);
  Serial.println("Iniciando conexão Wifi...");
}

void loop() {
  struct tm timeinfo;
  if (!getLocalTime(&timeinfo)) {
    Serial.println("sem hora");
    return;
  }
  Serial.println(&timeinfo);

}
