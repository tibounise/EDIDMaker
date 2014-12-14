#include "BasicDisplayParameters.h"

void BasicDisplayParameters::setInputType(uint8_t type) {
    uint8_t bitmask = 0b01111111;
    this->inputParametersBitmap &= bitmask;

    // If it's a digital input
    if (type) {
        this->inputParametersBitmap ^= 0b10000000;

        // Set up a new bitmask to erase some bits which
        // sould be zeroed if it's a digital output
        bitmask = 0b10000001;
        this->inputParametersBitmap &= bitmask;
    }
    // If it's an analog input, do nothing (we've already bit 0 to 0)
}

void BasicDisplayParameters::setVESADFPTMDSCRGBCompatibility(uint8_t compatible) {
    uint8_t bitmask = 0b11111110;
    this->inputParametersBitmap &= bitmask;

    // Display compatible with VESA DFP 1.x TMDS CRGB,
    // 1 pixel per clock, up to 8 bits per color, MSB aligned
    if (compatible) {
        this->inputParametersBitmap ^= 0b00000001;
    }
}

void BasicDisplayParameters::setWhiteAndSyncLevels(uint8_t levels) {
    uint8_t bitmask = 0b10011111;
    this->inputParametersBitmap &= bitmask;

    switch (levels) {
    // +0.7/−0.3 V
    case 0:
        this->inputParametersBitmap ^= 0b00000000;
        break;
    // +0.714/−0.286 V
    case 1:
        this->inputParametersBitmap ^= 0b00100000;
        break;
    // +1.0/−0.4 V
    case 2:
        this->inputParametersBitmap ^= 0b01000000;
        break;
    // +0.7/0 V
    case 3:
        this->inputParametersBitmap ^= 0b01100000;
        break;
    }
}

void BasicDisplayParameters::setBlankToBlackSetupExpected(uint8_t expected) {
    uint8_t bitmask = 0b11101111;
    this->inputParametersBitmap &= bitmask;

    // Blank to black setup (pedestral) expected
    if (expected) {
        this->inputParametersBitmap ^= 0b00010000;
    }
}

void BasicDisplayParameters::setSeparateSyncSupported(uint8_t support) {
    uint8_t bitmask = 0b11110111;
    this->inputParametersBitmap &= bitmask;

    // Separate sync supported
    if (support) {
        this->inputParametersBitmap ^= 0b00001000;
    }
}

void BasicDisplayParameters::setCompositeSyncSupport(uint8_t support) {
    uint8_t bitmask = 0b11111011;
    this->inputParametersBitmap &= bitmask;

    // Composite sync supported
    if (support) {
        this->inputParametersBitmap ^= 0b00000100;
    }
}

void BasicDisplayParameters::setSyncOnGreenSupported(uint8_t support) {
    uint8_t bitmask = 0b11111101;
    this->inputParametersBitmap &= bitmask;

    // Sync on green supported
    if (support) {
        this->inputParametersBitmap ^= 0b00000010;
    }
}

void BasicDisplayParameters::setVSyncSerrated(uint8_t serrated) {
    
}

int BasicDisplayParameters::writeToFile(FILE *stream) {
    
}