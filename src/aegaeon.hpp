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

#endif // AEGAEON_HPP