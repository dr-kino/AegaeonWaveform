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
#endif // AEGAEON_TYPES_HPP
