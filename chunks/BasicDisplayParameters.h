#include <stdint.h>

class BasicDisplayParameters {
public:
    void setInputType(bool type);
    void setVESADFPCompatibility(uint8_t compatible);
    void setWhiteAndSyncLevels(uint8_t levels);
    void setBlankToBlackSetupExpected(uint8_t expected);
    void setCompositeSyncSupport(uint8_t support);
    void setSeparateSyncSupport(uint8_t support);
    void setSyncOnGreenSupport(uint8_t support);
    void setVSyncSerrated(uint8_t serrated);
    void setHorizontalImageSize(uint8_t size);
    void setVerticalImageSize(uint8_t size);
    void setGamma(float gamma_float);
    void setDPMSStandbySupport(uint8_t support);
    void setDPMSSuspendSupport(uint8_t support);
    void setDPMSActiveOffSupport(uint8_t support);
    void setDisplayType(uint8_t type);
    void setUseSRGBColorSpace(uint8_t srgb);
    void setPreferredTimingMode(uint8_t timingmode);
    void setGTFSupport(uint8_t support);
    int writeToFile(FILE *stream);
private:
    uint8_t inputParametersBitmap = 0;
    uint8_t supportedFeaturesBitmap = 0;
    uint8_t hImageSize = 0;
    uint8_t vImageSize = 0;
    uint8_t gamma = 0;
};