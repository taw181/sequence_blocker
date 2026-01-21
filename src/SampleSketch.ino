#include <GeneralADCDAC.h>

#include "latest_hash.h"

void setup()
{
  Serial.begin(115200);

  setupChips();
};

void loop()
{
  static auto t_last_output = millis();

  auto reading1 = getADC().setAndReadADC(0);
  getDAC().setDACChannel(0, reading1);

  auto reading2 = getADC().setAndReadADC(1);
  getDAC().setDACChannel(1, reading2);

  if (millis() - t_last_output > 1000)
  {
    Serial.print("General ADC/DAC Demo v");
    Serial.println(LATEST_HASH);

    Serial.print("Channel 0: ");
    Serial.println(reading1, 6);
    Serial.print("Channel 1: ");
    Serial.println(reading2, 6);
    t_last_output = millis();
  }
}
