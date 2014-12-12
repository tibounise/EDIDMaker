#include <stdint.h>

class BasicDisplayParameters {
public:
    void setInputType(uint8_t type);
private:
    uint8_t inputParametersBitmap = 0;
};