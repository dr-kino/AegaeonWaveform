#include "raw_file_format.hpp"
using namespace std;

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
    ifstream myFile(fileName, std::ios::binary);
    std::vector<uint16_t>data;

    cout << "Waveform File Name: " << fileName << endl;

    data = std::vector<uint16_t>((std::istreambuf_iterator<char>(myFile)), std::istreambuf_iterator<char>());

    for ( int i = 0; i < 500; i++ )
    {
        printf("Value: %u\n", data[i]);
    }

    std::cout << std::endl;

    myFile.close();

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
