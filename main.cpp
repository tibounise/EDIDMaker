#include <stdio.h>
#include "chunks/HeaderInformation.cpp"
#include "chunks/BasicDisplayParameters.cpp"
#include "chunks/ChromaticityCoordinates.cpp"
#include "chunks/EtablishedTiming.cpp"

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

    ChromaticityCoordinates cc;
    cc.setRedValue(0.640,0.330);
    cc.setGreenValue(0.300,0.608);
    cc.setBlueValue(0.150,0.060);
    cc.setWhiteValue(0.313,0.329);
    cc.writeToFile(stream);

    EtablishedTiming et;
    et.set60Hz640x480Support(true);
    et.set60Hz800x600Support(true);
    et.set56Hz800x600Support(true);
    et.set60Hz1024x768Support(true);
    et.writeToFile(stream);

    fclose(stream);

    return 0;
}