#include <GeneralAIO.h>

#include "latest_hash.h"

bool last_state = false;
unsigned long t_last_edge = 0; // ms
unsigned long trigger_wait_time = 1; // ms
unsigned long caf_mot_off_time = 0; // ms
unsigned long caf_wait_time = 5000; // ms

void setup() {
  Serial.begin(115200);
  setupChips();
  getADC().setADCChannel(0);
}

void loop() {
  if (getADC().readCurrentADCChannel() > 2.5) {
    caf_mot_off_time = millis();
    getDAC().setDACChannel(0, 0.0);

    while (millis() < caf_mot_off_time + caf_wait_time) {
      if (getADC().readCurrentADCChannel() > 2.5) {
        caf_mot_off_time = millis();
      }
    }
    return;
  }
  if (millis() > t_last_edge + trigger_wait_time) {
    last_state = !last_state;
    t_last_edge = millis();
  }

  if (last_state)
    getDAC().setDACChannel(0, 0.0);
  else
    getDAC().setDACChannel(0, 5.0);
}
