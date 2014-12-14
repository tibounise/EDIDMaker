class EtablishedTiming {
public:
    writeToFile(FILE *stream);
private:
    uint8_t modeBytes[3] = {0x00,0x00,0x00};
};