#include <stdio.h>
#include "chunks/HeaderInformation.cpp"

int main() {
    HeaderInformation hi;
    char text[] = "AEO";
    hi.setManufacturerId(text);
    printf("%2s",hi.getChunkAsBinary());

    return 0;
}