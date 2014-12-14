class StandardTimingInformation {
public:
    void setXResolution(uint16_t resolution);
    void setFrequency(uint8_t frequency);
    void setRatio(uint8_t ratio);
    void writeToFile(FILE *stream);
private:
    uint8_t xResolution = 0;
    uint8_t ratioFreq = 0;
};