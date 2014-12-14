#include "StandardTimingInformation.h"

void StandardTimingInformation::setXResolution(uint16_t resolution) {
    this->xResolution = (char)((resolution/8)-31);
}

void StandardTimingInformation::setFrequency(uint8_t frequency) {
    this->ratioFreq &= 0b11000000;

    this->ratioFreq ^= ((frequency - 60) & 0b111111);
}

void StandardTimingInformation::setRatio(uint8_t ratio) {
    this->ratioFreq &= 0b00111111;

    switch (ratio) {
    // 16:10
    case 0:
        this->ratioFreq ^= 0b00000000;
        break;

    // 4:3
    case 1:
        this->ratioFreq ^= 0b01000000;
        break;

    // 5:4
    case 2:
        this->ratioFreq ^= 0b10000000;
        break;

    // 16:9
    case 3:
        this->ratioFreq ^= 0b11000000;
        break;
    }
}

void StandardTimingInformation::writeToFile(FILE *stream) {
    fputc(this->xResolution,stream);
    fputc(this->ratioFreq,stream);
}