class ChromaticityCoordinates {
public:
    void setRedValue(float red_x, float red_y);
    void setGreenValue(float green_x, float green_y);
    void setBlueValue(float blue_x, float blue_y);
    void setWhiteValue(float white_x, float white_y);
    int writeToFile(FILE *stream);
private:
    uint8_t coordinates[10] = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
};