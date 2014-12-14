#include "BasicDisplayParameters.h"

void BasicDisplayParameters::setInputType(bool type) {
    uint8_t bitmask = 0b01111111;
    this->inputParametersBitmap &= bitmask;

    // Digital input
    if (type) {
        this->inputParametersBitmap ^= 0b10000000;

        // Set up a new bitmask so that we erase someof the bits which
        // sould be zeroed if it's a digital output
        bitmask = 0b10000001;
        this->inputParametersBitmap &= bitmask;
    }
    // If it's an analog input, do nothing (we've already bit 0 to 0)
}

void BasicDisplayParameters::setVESADFPCompatibility(bool compatible) {
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

void BasicDisplayParameters::setBlankToBlackSetupExpected(bool expected) {
    uint8_t bitmask = 0b11101111;
    this->inputParametersBitmap &= bitmask;

    // Blank to black setup (pedestral) expected
    if (expected) {
        this->inputParametersBitmap ^= 0b00010000;
    }
}

void BasicDisplayParameters::setSeparateSyncSupport(bool support) {
    uint8_t bitmask = 0b11110111;
    this->inputParametersBitmap &= bitmask;

    // Separate sync supported
    if (support) {
        this->inputParametersBitmap ^= 0b00001000;
    }
}

void BasicDisplayParameters::setCompositeSyncSupport(bool support) {
    uint8_t bitmask = 0b11111011;
    this->inputParametersBitmap &= bitmask;

    // Composite sync supported
    if (support) {
        this->inputParametersBitmap ^= 0b00000100;
    }
}

void BasicDisplayParameters::setSyncOnGreenSupport(bool support) {
    uint8_t bitmask = 0b11111101;
    this->inputParametersBitmap &= bitmask;

    // Sync on green supported
    if (support) {
        this->inputParametersBitmap ^= 0b00000010;
    }
}

void BasicDisplayParameters::setVSyncSerrated(bool serrated) {
    uint8_t bitmask = 0b11111110;
    this->inputParametersBitmap &= bitmask;

    // Serrated if composite or sync on green
    if (serrated) {
        this->inputParametersBitmap ^= 0b00000001;
    }
}

void BasicDisplayParameters::setHorizontalImageSize(uint8_t size) {
    this->hImageSize = size;
}

void BasicDisplayParameters::setVerticalImageSize(uint8_t size) {
    this->vImageSize = size;
}

void BasicDisplayParameters::setGamma(float gamma_float) {
    this->gamma = (uint8_t)((gamma_float*100)-100);
}

void BasicDisplayParameters::setDPMSStandbySupport(bool support) {
    uint8_t bitmask = 0b01111111;
    this->supportedFeaturesBitmap &= bitmask;

    // DPMS standby supported
    if (support) {
        this->supportedFeaturesBitmap ^= 0b10000000;
    }
}

void BasicDisplayParameters::setDPMSSuspendSupport(bool support) {
    uint8_t bitmask = 0b10111111;
    this->supportedFeaturesBitmap &= bitmask;

    // DPMS suspend supported
    if (support) {
        this->supportedFeaturesBitmap ^= 0b01000000;
    }
}

void BasicDisplayParameters::setDPMSActiveOffSupport(bool support) {
    uint8_t bitmask = 0b11011111;
    this->supportedFeaturesBitmap &= bitmask;

    // DPMS active-off supported
    if (support) {
        this->supportedFeaturesBitmap ^= 0b00100000;
    }
}

void BasicDisplayParameters::setDisplayType(uint8_t type) {
    uint8_t bitmask = 0b11100111;
    this->supportedFeaturesBitmap &= bitmask;

    switch (type) {
    // Digital display : RGB 4:4:4, analog display : monochrome or grayscale
    case 0:
        this->supportedFeaturesBitmap ^= 0b00000000;
        break;

    // Digital display : RGB 4:4:4 + YCrCb 4:4:4, analog display : RGB color
    case 1:
        this->supportedFeaturesBitmap ^= 0b00001000;
        break;

    // Digital display : RGB 4:4:4 + YCrCb 4:2:2, analog display : non-RGB color
    case 2:
        this->supportedFeaturesBitmap ^= 0b00010000;
        break;

    // Digital display : RGB 4:4:4 + YCrCb 4:4:4 + YCrCb 4:2:2, analog display : undefined
    case 3:
        this->supportedFeaturesBitmap ^= 0b00011000;
        break;
    }
}

void BasicDisplayParameters::setUseSRGBColorSpace(bool srgb) {
    uint8_t bitmask = 0b11111011;
    this->supportedFeaturesBitmap &= bitmask;

    if (srgb) {
        this->supportedFeaturesBitmap ^= 0b00000100;
    }
}

void BasicDisplayParameters::setPreferredTimingMode(bool timingmode) {
    uint8_t bitmask = 0b11111101;
    this->supportedFeaturesBitmap &= bitmask;

    // Preferred timing mode specified in descriptor block 1
    if (timingmode) {
        this->supportedFeaturesBitmap ^= 0b00000010;
    }
}

void BasicDisplayParameters::setGTFSupport(bool support) {
    uint8_t bitmask = 0b11111110;
    this->supportedFeaturesBitmap &= bitmask;

    // GTF supported
    if (support) {
        this->supportedFeaturesBitmap ^= 0b00000001;
    }
}

int BasicDisplayParameters::writeToFile(FILE *stream) {
    fputc(this->inputParametersBitmap,stream);
    fputc(this->hImageSize,stream);
    fputc(this->vImageSize,stream);
    fputc(this->gamma,stream);
    fputc(this->supportedFeaturesBitmap,stream);

    return 0;
}