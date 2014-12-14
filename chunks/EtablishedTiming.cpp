#include "EtablishedTiming.h"

void EtablishedTiming::set70Hz720x400Support(bool support) {
    this->modeBytes[0] &= 0b01111111;

    if (support) {
        this->modeBytes[0] ^= 0b10000000;
    }
}

void EtablishedTiming::set88Hz720x400Support(bool support) {
    this->modeBytes[0] &= 0b10111111;

    if (support) {
        this->modeBytes[0] ^= 0b01000000;
    }
}

void EtablishedTiming::set60Hz640x480Support(bool support) {
    this->modeBytes[0] &= 0b11011111;

    if (support) {
        this->modeBytes[0] ^= 0b00100000;
    }
}

void EtablishedTiming::set67Hz640x480Support(bool support) {
    this->modeBytes[0] &= 0b11101111;

    if (support) {
        this->modeBytes[0] ^= 0b00010000;
    }
}

void EtablishedTiming::set72Hz640x480Support(bool support) {
    this->modeBytes[0] &= 0b11110111;

    if (support) {
        this->modeBytes[0] ^= 0b00001000;
    }
}

void EtablishedTiming::set75Hz640x480Support(bool support) {
    this->modeBytes[0] &= 0b11111011;

    if (support) {
        this->modeBytes[0] ^= 0b00000100;
    }
}

void EtablishedTiming::set56Hz800x600Support(bool support) {
    this->modeBytes[0] &= 0b11111101;

    if (support) {
        this->modeBytes[0] ^= 0b00000010;
    }
}

void EtablishedTiming::set60Hz800x600Support(bool support) {
    this->modeBytes[0] &= 0b11111110;

    if (support) {
        this->modeBytes[0] ^= 0b00000001;
    }
}

void EtablishedTiming::set72Hz800x600Support(bool support) {
    this->modeBytes[1] &= 0b01111111;

    if (support) {
        this->modeBytes[1] ^= 0b10000000;
    }
}

void EtablishedTiming::set75Hz800x600Support(bool support) {
    this->modeBytes[1] &= 0b10111111;

    if (support) {
        this->modeBytes[1] ^= 0b01000000;
    }
}

void EtablishedTiming::set75Hz832x624Support(bool support) {
    this->modeBytes[1] &= 0b11011111;

    if (support) {
        this->modeBytes[1] ^= 0b00100000;
    }
}

void EtablishedTiming::set87Hz1024x768Support(bool support) {
    this->modeBytes[1] &= 0b11101111;

    if (support) {
        this->modeBytes[1] ^= 0b00010000;
    }
}

void EtablishedTiming::set60Hz1024x768Support(bool support) {
    this->modeBytes[1] &= 0b11110111;

    if (support) {
        this->modeBytes[1] ^= 0b00001000;
    }
}

void EtablishedTiming::set72Hz1024x768Support(bool support) {
    this->modeBytes[1] &= 0b11111011;

    if (support) {
        this->modeBytes[1] ^= 0b00000100;
    }
}

void EtablishedTiming::set75Hz1024x768Support(bool support) {
    this->modeBytes[1] &= 0b11111101;

    if (support) {
        this->modeBytes[1] ^= 0b00000010;
    }
}

void EtablishedTiming::set75Hz1280x1024Support(bool support) {
    this->modeBytes[1] &= 0b11111110;

    if (support) {
        this->modeBytes[1] ^= 0b00000001;
    }
}

void EtablishedTiming::set75Hz1152x870Support(bool support) {
    this->modeBytes[2] &= 0b01111111;

    if (support) {
        this->modeBytes[2] ^= 0b10000000;
    }   
}

void EtablishedTiming::writeToFile(FILE *stream) {
    fwrite(this->modeBytes,sizeof(uint8_t),sizeof(this->modeBytes),stream);
}