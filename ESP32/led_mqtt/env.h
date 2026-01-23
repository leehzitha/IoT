#ifndef ENV_H
#define ENV_H

#define WIFI_SSID "BTIA_SON5CT"
#define WIFI_PASS "IUVr4qSh8kQe"
#define BLUE 27
#define GREEN 26 
#define RED 25                                                            //led que já vem soldado na esp32 

const char* mqtt_server = "broker.hivemq.com";
const char* mqtt_client_id = "ESP32_leleca"; 

const char* topico_led = "dta/leleca/led";
const char* topico_status = "dta/leleca/status";
const int   mqtt_port = 1883;


#endif