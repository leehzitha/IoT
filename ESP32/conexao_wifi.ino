#include <WiFi.h>

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
  WiFi.onEvent(WiFiEvent);
  WiFi.begin(ssid, password);
  Serial.println("Iniciando conexão Wifi...");

}

void loop() {
  // put your main code here, to run repeatedly:

}
