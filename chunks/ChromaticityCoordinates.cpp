#include "ChromaticityCoordinates.h"

void ChromaticityCoordinates::setRedValue(float red_x, float red_y) {
    uint16_t red_x_int = red_x * 1024;
    uint16_t red_y_int = red_y * 1024;

    // Erasing current red bits
    this->coordinates[0] &= 0b00001111;
    this->coordinates[2] = 0x00;
    this->coordinates[3] = 0x00;

    // Setting up the 2 lsb
    this->coordinates[0] ^= (red_x_int & 0b11) << 6;
    this->coordinates[0] ^= (red_y_int & 0b11) << 4;

    // Setting up the MSB
    this->coordinates[2] = ((red_x_int >> 2) & 0xFF);
    this->coordinates[3] = ((red_y_int >> 2) & 0xFF);
}

void ChromaticityCoordinates::setGreenValue(float green_x, float green_y) {
    uint16_t green_x_int = green_x * 1024;
    uint16_t green_y_int = green_y * 1024;

    // Erasing current green bits
    this->coordinates[0] &= 0b11110000;
    this->coordinates[4] = 0x00;
    this->coordinates[5] = 0x00;

    // Setting up the 2 lsb
    this->coordinates[0] ^= ((green_x_int & 0b11) << 2) | (green_y_int & 0b11);

    // Setting up the MSB
    this->coordinates[4] = ((green_x_int >> 2) & 0xFF);
    this->coordinates[5] = ((green_y_int >> 2) & 0xFF);
}

void ChromaticityCoordinates::setBlueValue(float blue_x, float blue_y) {
    uint16_t blue_x_int = blue_x * 1024;
    uint16_t blue_y_int = blue_y * 1024;

    // Erasing current blue bits
    this->coordinates[1] &= 0b00001111;
    this->coordinates[6] = 0x00;
    this->coordinates[7] = 0x00;

    // Setting up the 2 lsb
    this->coordinates[1] ^= ((blue_x_int & 0b11) << 2) | (blue_y_int & 0b11);
    this->coordinates[6] = ((blue_x_int >> 2) & 0xFF);
    this->coordinates[7] = ((blue_y_int >> 2) & 0xFF);
}

void ChromaticityCoordinates::setWhiteValue(float white_x, float white_y) {
    uint16_t white_x_int = white_x * 1024;
    uint16_t white_y_int = white_y * 1024;

    // Erasing current white bits
    this->coordinates[1] &= 0b11110000;
    this->coordinates[8] = 0x00;
    this->coordinates[9] = 0x00;

    // Setting up the 2 lsb
    this->coordinates[1] ^= ((white_x_int & 0b11) << 6) | ((white_y_int & 0b11) << 4);
    this->coordinates[8] = ((white_x_int >> 2) & 0xFF);
    this->coordinates[9] = ((white_y_int >> 2) & 0xFF);
}

int ChromaticityCoordinates::writeToFile(FILE *stream) {
    return fwrite(this->coordinates,sizeof(uint8_t),sizeof(this->coordinates),stream);
}