#include <WiFi.h>

#define green_led 33
#define red_led 32

const char* ssid = "lele";
const char* password = "20070318";
hw_timer_t *timer = NULL;
int tempo = 0;
int contador = 0;

bool connected = false;

void IRAM_ATTR led() {
  if (connected) {
    digitalWrite(green_led, !digitalRead(green_led));
    digitalWrite(red_led, LOW);
  }
  else {
    contador ++;
    if (contador == 5) {
      digitalWrite(green_led, LOW);
      digitalWrite(red_led, !digitalRead(red_led));
      contador = 0;
    }
  }
}

void WiFiEvent(WiFiEvent_t event) {
  switch(event) {
    case ARDUINO_EVENT_WIFI_STA_GOT_IP:  
      connected = true;
      Serial.println("conectadinho");
      break;
    case ARDUINO_EVENT_WIFI_STA_DISCONNECTED:
      connected = false;
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

  pinMode(green_led, OUTPUT);
  pinMode(red_led, OUTPUT);
  
  timer = timerBegin(1000000);
  timerAttachInterrupt(timer, &led);
  timerAlarm(timer, 100000, true, 0);
}

void loop() {
  

}