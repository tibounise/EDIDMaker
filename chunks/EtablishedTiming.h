class EtablishedTiming {
public:
    void set70Hz720x400Support(bool support);
    void set88Hz720x400Support(bool support);
    void set60Hz640x480Support(bool support);
    void set67Hz640x480Support(bool support);
    void set72Hz640x480Support(bool support);
    void set75Hz640x480Support(bool support);
    void set56Hz800x600Support(bool support);
    void set60Hz800x600Support(bool support);
    void set72Hz800x600Support(bool support);
    void set75Hz800x600Support(bool support);
    void set75Hz832x624Support(bool support);
    void set87Hz1024x768Support(bool support);
    void set60Hz1024x768Support(bool support);
    void set72Hz1024x768Support(bool support);
    void set75Hz1024x768Support(bool support);
    void set75Hz1280x1024Support(bool support);
    void set75Hz1152x870Support(bool support);
    void writeToFile(FILE *stream);
private:
    uint8_t modeBytes[3] = {0x00,0x00,0x00};
};