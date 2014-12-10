#include "HeaderInformation.h"

void HeaderInformation::setManufacturerId(char *id) {
    // Clear it !
    this->manufacturer_id[0] = 0x00;
    this->manufacturer_id[1] = 0x00;

    // Checking we're not out of bounds
    if (id[0] < 'A' || id[0] > 'Z' || id[1] < 'A' || id[1] > 'Z' || id[2] < 'A' || id[2] > 'Z') {
        return;
    }

    // Convert from ASCII to a number. A = 1, Z = 26
    id[0] = id[0] - 'A' + 1;
    id[1] = id[1] - 'A' + 1;
    id[2] = id[2] - 'A' + 1;

    // Binary monkeys will add this to manufacturer_id array
    this->manufacturer_id[0] ^= (id[0] << 2);
    this->manufacturer_id[0] ^= (id[1] >> 3);
    this->manufacturer_id[1] ^= (id[1] << 6);
    this->manufacturer_id[1] ^= id[2];
}

void HeaderInformation::setManufacturerProductCode(unsigned short product_code) {
    this->manufacturer_product_code = product_code;
}

void HeaderInformation::setSerialNumber(unsigned long number) {
    this->serial_number = number;
}

void HeaderInformation::setWeekOfManufacture(unsigned char week) {
    this->week_of_manufacture = week;
}

void HeaderInformation::setYearOfManufacture(unsigned char year) {
    this->year_of_manufacture = year;
}

unsigned char* HeaderInformation::getChunkAsBinary() {
    return this->manufacturer_id;
}