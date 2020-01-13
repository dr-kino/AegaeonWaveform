#include "raw_file_format.hpp"

/// ----------------------------------------------------------------------------
// Constructor
// ----------------------------------------------------------------------------
RawFileFormat::RawFileFormat()
{
}

// ----------------------------------------------------------------------------
// Destructor
// ----------------------------------------------------------------------------
RawFileFormat::~RawFileFormat()
{
}

// ----------------------------------------------------------------------------
// ReadInputData
// ----------------------------------------------------------------------------
bool RawFileFormat::readInputData(std::string fileName)
{
    bool error = false;
    std::ifstream myFile;
    std::vector<uint16_t>data;

    std::cout << "Waveform File Name: " << fileName << std::endl;

    myFile.open(fileName);

    // myFile.read(&data, sizeof(uint16_t));


    return error;
}

// ----------------------------------------------------------------------------
// setFileName
// ----------------------------------------------------------------------------
void RawFileFormat::setFileName(std::string fileNameNew)
{
    _fileName = fileNameNew;
}

// ----------------------------------------------------------------------------
// getFileName
// ----------------------------------------------------------------------------
const std::string RawFileFormat::getFileName() const
{
    return _fileName;
}

// ----------------------------------------------------------------------------
// setData
// ----------------------------------------------------------------------------
void RawFileFormat::setData(std::vector<uint8_t>dataNew)
{
    _data = dataNew;
}

// ----------------------------------------------------------------------------
// getName
// ----------------------------------------------------------------------------
const std::vector<uint8_t>RawFileFormat::getData() const
{
    return _data;
}
