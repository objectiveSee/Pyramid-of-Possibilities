#ifndef __Accelerometer__
#define ____Accelerometer__

#include <stdint.h>
#include <stdlib.h>


// Set the scale below either 2, 4 or 8
const uint8_t SCALE_SHIFT = 1; // full-scale shift (1, 2, or 3) corresponding to 2, 4, or 8g
const uint8_t SCALE = 1 << SCALE_SHIFT;  // Sets full-scale range to +/-2, 4, or 8g. Used to calc real g values.
const int int1Pin = 11;  // These can be changed, 2 and 3 are the Arduinos ext int pins
const int int2Pin = 12;

void initializeAccelerometer();

void readAccelData(int16_t * destination);
void readAccelData(float * destination);
void MMA8452Standby();
void MMA8452Active();
void readRegisters(uint8_t addressToRead, int bytesToRead, uint8_t * dest);
uint8_t readRegister(uint8_t addressToRead);
void writeRegister(uint8_t addressToWrite, uint8_t dataToWrite);

#endif /* defined(__Accelerometer__) */