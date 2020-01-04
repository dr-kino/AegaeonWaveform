#ifndef AEGAEON_TYPES_HPP
#define AEGAEON_TYPES_HPP

#include <string>
#include <iostream>
#include <libxml/xmlreader.h>

typedef struct Settings {
    bool rawFormat;
    bool csvFormat;
    bool txtFormat;
} Settings_t;

typedef struct Target {
    std::string brand;
    std::string series;
    std::string model;
    Settings_t Settings;
} Target_t;

typedef struct FormatRigolSeries1000z {
    int32_t Points;
    const char Fixed1 = 0x01;
    const char Fixed2 = 0x01;
    char OutputMode;
    char FileName[25];
    int64_t SampleOrPeriod;
    int32_t HighLevel;
    int32_t LowLevel;
    uint16_t WaveformCRC;
    uint16_t HeaderCRC;
    const char Fixed3 = 0x00;
    const char Fixed4 = 0x00;
    const char Fixed5 = 0x00;
    const char Fixed6 = 0x00;
    const uint32_t MaxDataLength = 1999944;
} FormatRigolSeries1000z_t;

typedef struct AlgorithmRigolSeries1000z {
    std::string name;
    std::string brand;
    std::string model;
    std::string series;
} AlgorithmRigolSeries1000z_t;

typedef struct ModelRigolSeriesDG1000z {
    FormatRigolSeries1000z_t Format;
    AlgorithmRigolSeries1000z_t Algorithm;
} ModelRigolSeriesDG1000z_t;
#endif // AEGAEON_TYPES_HPP
