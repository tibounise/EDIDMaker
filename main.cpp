#include <stdio.h>
#include "chunks/HeaderInformation.cpp"
#include "chunks/BasicDisplayParameters.cpp"

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

    BasicDisplayParameters bdp;
    bdp.setInputType(true);
    bdp.setHorizontalImageSize(0x16);
    bdp.setVerticalImageSize(0x9);
    bdp.setGamma(2.59);
    bdp.setDPMSActiveOffSupport(true);
    bdp.setDisplayType(1);
    bdp.setPreferredTimingMode(true);
    bdp.writeToFile(stream);

    fclose(stream);

    return 0;
}