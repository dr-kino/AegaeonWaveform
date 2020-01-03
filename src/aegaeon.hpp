#ifndef AEGAEON_HPP
#define AEGAEON_HPP

#include <string>
#include <memory>

enum outputFile
{
    csv = 0,
    txt,
    raw
};

typedef enum outputFile outputFile_t;

typedef struct Aegaeon {
    unsigned char type;
    std::string waveformName;
    std::string outputFileName;
} Aegaeon_t;

class AegaeonUnit {
    private:
    static std::unique_ptr<AegaeonUnit>instance_;
    AegaeonUnit();
    AegaeonUnit(AegaeonUnit const&) = delete;
    void operator=(AegaeonUnit const&) = delete;

    Aegaeon_t Aegaeon_;

    public:
    ~AegaeonUnit();
    static AegaeonUnit&getInstance(void);

    // Setteres and Getteres for private variable "Aegaeon.type"
    void setType(unsigned char type);
    unsigned char getType(void);
    // Setteres and Getteres for private variable "Aegaeon.waveformName"
    void setWaveformName(std::string waveformName);
    std::string getWaveformName(void);
    // Setteres and Getteres for private variable "Aegaeon.outputFileName"
    void setOutputFileName(std::string outputFileName);
    std::string getOutputFileName(void);
};
#endif // AEGAEON_HPP
