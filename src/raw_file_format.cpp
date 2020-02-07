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
    vector<uint16_t>data;

    cout << "Waveform File Name: " << fileName << endl;

    data = std::vector<uint16_t>((istream_iterator<char>(myFile)), istream_iterator<char>());

    for ( int i = 0; i < 8192; i++ )
    {
        uint16_t x;
        // x = data[(i*2)+1];// | (data[(i*2)+1] << 8);
        // printf("Value: %x\n", x);
        printf("Valeu: %x\n", data[i]);
    }

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
