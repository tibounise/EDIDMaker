#include <stdint.h>

class BasicDisplayParameters {
public:
    void setInputType(uint8_t type);
    void setCompositeSyncSupport(uint8_t support);
    void setSyncOnGreenSupported(uint8_t support)
    int writeToFile(FILE *stream);
private:
    uint8_t inputParametersBitmap = 0;
};