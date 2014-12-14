#include <stdint.h>

class BasicDisplayParameters {
public:
    void setInputType(bool type);
    void setVESADFPCompatibility(bool compatible);
    void setWhiteAndSyncLevels(uint8_t levels);
    void setBlankToBlackSetupExpected(bool expected);
    void setCompositeSyncSupport(bool support);
    void setSeparateSyncSupport(bool support);
    void setSyncOnGreenSupport(bool support);
    void setVSyncSerrated(bool serrated);
    void setHorizontalImageSize(uint8_t size);
    void setVerticalImageSize(uint8_t size);
    void setGamma(float gamma_float);
    void setDPMSStandbySupport(bool support);
    void setDPMSSuspendSupport(bool support);
    void setDPMSActiveOffSupport(bool support);
    void setDisplayType(uint8_t type);
    void setUseSRGBColorSpace(bool srgb);
    void setPreferredTimingMode(bool timingmode);
    void setGTFSupport(bool support);
    int writeToFile(FILE *stream);
private:
    uint8_t inputParametersBitmap = 0;
    uint8_t supportedFeaturesBitmap = 0;
    uint8_t hImageSize = 0;
    uint8_t vImageSize = 0;
    uint8_t gamma = 0;
};