#ifndef AEGAEON_HPP
#define AEGAEON_HPP

#include <string>
#include <memory>

enum outputFile {
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
        static std::unique_ptr<AegaeonUnit> instance_;
        AegaeonUnit();
        AegaeonUnit(AegaeonUnit const&) = delete;
        void operator=(AegaeonUnit const&) = delete;

        Aegaeon_t Aegaeon_;
    public:
        // Setteres and Getteres for private variable "Aegaeon.type"
        void setType();
        unsigned char getType();
        // Setteres and Getteres for private variable "Aegaeon.waveformName"
        void setWaveformName();
        std::string getWaveformName();
        // Setteres and Getteres for private variable "Aegaeon.outputFileName"
        void setOutputFileName();
        std::string getOutputFileName();
};

#endif // AEGAEON_HPP