#include <WiFi.h>

const char* ssid = "lele";
const char* password = "20070318";
hw_timer_t *timer = NULL;
int tempo = 0;

void IRAM_ATTR connected() {
  digitalWrite(2, HIGH);
  digitalWrite(4, LOW);
}

void IRAM_ATTR disconnected() {
  digitalWrite(4, HIGH);
  digitalWrite(2, LOW);
}

void WiFiEvent(WiFiEvent_t event) {
  switch(event) {
    case ARDUINO_EVENT_WIFI_STA_GOT_IP:  
      timer = timerBegin(2000000);
      timerAttachInterrupt(timer, &connected);
      timerAlarm(timer, 1000000, true, 0);
      Serial.println("conectadinho");
      break;
    case ARDUINO_EVENT_WIFI_STA_DISCONNECTED:
      digitalWrite(4, HIGH);
      digitalWrite(2, LOW);
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
  pinMode(2, OUTPUT);
  pinMode(4, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

}
