#define AEGAEON_HPP
#ifndef AEGAEON_HPP

typedef enum outputFile {
    csv = 0,
    txt,
    raw,
} outputFile_t;

typedef struct Aegaeon {
    unsigned char type;
    std::string waveformName;
    std::string outputFileName;
} Aegaeon_t;

#endif // AEGAEON_HPP