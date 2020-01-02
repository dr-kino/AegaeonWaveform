#ifndef AEGAEON_HPP
#define AEGAEON_HPP

#include <string>

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

    private:
        Aegaeon_t _Aegaeon;
};

#endif // AEGAEON_HPP