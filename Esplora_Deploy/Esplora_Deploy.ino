#include <Esplora.h>
#include <TFT.h>
#include <SPI.h>
#include <SD.h>
#include <Keyboard.h>

#define SD_CS    8

int width, height;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  EsploraTFT.begin();
  EsploraTFT.setTextSize(2);
  width = EsploraTFT.width();
  height = EsploraTFT.height();
  SD.begin(SD_CS);
  menu_init();
}

void loop() {
  // put your main code here, to run repeatedly:
  menu_loop();
}

