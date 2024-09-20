#include <EEPROM.h>

#define BTN1     2
#define BTN2     3
#define LED1     9
#define LED2     10
#define LED3     11
#define BAUDRATE 9600
#define CELDA    0
#define TIME     1000
#define TIMESEP  1000
#define MINTIME  0
#define MAXTIME  10

uint8_t curado = EEPROM.read(CELDA)
volatile unsigned long lasttime= 0;
volatile unsigned long debounceDelay= 50;
volatile bool BTN1ON= false;
volatile bool BTN2ON= false;
 
void setup() {
pinMode(BTN1, INPUT_PULLUP);
pinMode(BTN2, INPUT_PULLUP);
pinMode(LED1, OUTPUT);
pinMode(BTN2, OUTPUT);
pinMode(BTN3, OUTPUT);
attachInterrupt(digitalPinToInterrupt(BTN1), aumentar, RISING);
attachInterrupt(digitalPinToInterrupt(BTN1), disminuir, RISING);
Serial.begin(BAUDRATE);
}

void loop() {
if (BTN1ON == true && BTN2ON == false){
  if (curado < MAXTIME){
    curado++;
    Serial.print("Tiempo de curado: ");
    Serial.print(curado);
    Serial.println(".");
    EEPROM.write(CELDA, curado);
  }
  BTN1ON = false;
}
delay (TIMESEP);
if (BTN2ON == true && BTN1ON == false){
  if (curado > MINTIME){
    curado--;
    Serial.print("Tiempo de curado: ");
    Serial.print(curado);
    Serial.println(".");
    EEPROM.write(CELDA, curado);
  }
  BTN2ON = false;
}
if (BTN2ON == true && BTN1ON == true){
  if (curado > MINTIME ) && (curado < MAXTIME){
    curado=1;
    Serial.print("Tiempo de curado: ");
    Serial.print(curado);
    Serial.println(".");
    EEPROM.write(CELDA, curado);
  }
  BTN1ON = false;
  BTN2ON = false;
}

void aumentar() {
  if (millis() - lasttime > debounceDelay) {
    pinMas = true;
    lasttime = millis();
  }
}
void disminuir() {
  if (millis() - lasttime > debounceDelay) {
    pinMenos = true;
    lasttime=millis();
  }
}