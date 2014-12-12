#include <stdio.h>
#include "chunks/HeaderInformation.cpp"

int main() {
    FILE *stream;
    stream = fopen("./edid.bin","wb");

    HeaderInformation hi;
    char text[] = "SAM";
    hi.setManufacturerId(text);
    hi.setManufacturerProductCode(0x423);
    hi.setSerialNumber(0);
    hi.setWeekOfManufacture(31);
    hi.setYearOfManufacture(18);
    hi.setEDIDVersion(1);
    hi.setEDIDRevision(3);
    hi.writeToFile(stream);

    fclose(stream);

    return 0;
}