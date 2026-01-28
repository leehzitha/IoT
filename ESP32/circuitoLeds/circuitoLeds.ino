#define botao 27
volatile int pulo = 1;
int comeco = 0;
int fim = 6;
int tempo = 0;
int flagBotao = 0;
hw_timer_t *timer = NULL;

int leds[6] = {23, 22, 21, 25, 33, 32};

void IRAM_ATTR rotation() {
  if (flagBotao != 1) {
    flagBotao = 1;
    tempo = 50;
  };
}

void onTimer(){ // configurado para 1ms
  if(flagBotao == 1) {
    if (tempo > 0) {
      tempo --;
    }
    else {
      flagBotao = 0;
      if (!digitalRead(botao)) {
        pulo = pulo *= -1;
        if (comeco == 0) {
          comeco = 5;
          fim = -1;
        }
        else {
          comeco = 0;
          fim = 6;
        }
      }
    }
  }
};

void setup() {
  for (int i = comeco; i < fim ; i ++){
    pinMode(leds[i], OUTPUT);
  };

  pinMode(botao, INPUT_PULLUP);

  attachInterrupt(
    digitalPinToInterrupt(botao), 
    rotation,
    FALLING );

  Serial.begin(9600);
  timer = timerBegin(1000000);
  timerAttachInterrupt(timer, &onTimer);
  timerAlarm(timer, 1000, true, 0);
}

void loop() {
  for (int i = comeco; i != fim; i += pulo){
    digitalWrite(leds[i], 1);
    delay(200);
    digitalWrite(leds[i], 0);
    Serial.print("Começo: ");
    Serial.println(comeco);
  }

}
