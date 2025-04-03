#include "ClimateControlLib.h"

ClimateControl climateSystem;

void setup() {
    climateSystem.initSystem();
}

void loop() {
    climateSystem.processLoop();
}
