class HeaderInformation {
public:
    void setManufacturerId(char *id);
    void setManufacturerProductCode(unsigned short product_code);
    void setSerialNumber(unsigned long number);
    void setWeekOfManufacture(unsigned char week);
    void setYearOfManufacture(unsigned char year);
    void setEDIDVersion(unsigned char version);
    void setEDIDRevision(unsigned char revision);
    int writeToFile(FILE *stream);
private:
    unsigned char header[8] = {0x00,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x00};
    unsigned char manufacturer_id[2] = {0x00,0x00};
    unsigned short manufacturer_product_code = 0;
    unsigned long serial_number = 0;
    unsigned char week_of_manufacture;
    unsigned char year_of_manufacture;
    unsigned char edid_version;
    unsigned char edid_revision;
};