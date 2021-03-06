#include "csv_file_format.hpp"
#include <vector>
#include <string>

// ----------------------------------------------------------------------------
// CTOR
// ----------------------------------------------------------------------------
CsvFileFormat::CsvFileFormat()
{
}

// ----------------------------------------------------------------------------
// DTOR
// ----------------------------------------------------------------------------
CsvFileFormat::~CsvFileFormat()
{
}

// ----------------------------------------------------------------------------
// ReadInputData
// ----------------------------------------------------------------------------
bool CsvFileFormat::readInputData(std::string fileName)
{
    return true;
}

// ----------------------------------------------------------------------------
// setFileName
// ----------------------------------------------------------------------------
void CsvFileFormat::setFileName(std::string fileNameNew)
{
    _fileName = fileNameNew;
}

// ----------------------------------------------------------------------------
// getFileName
// ----------------------------------------------------------------------------
const std::string CsvFileFormat::getFileName() const
{
    return _fileName;
}

// ----------------------------------------------------------------------------
// setData
// ----------------------------------------------------------------------------
void CsvFileFormat::setData(std::vector<uint8_t>dataNew)
{
    _data = dataNew;
}

// ----------------------------------------------------------------------------
// getData
// ----------------------------------------------------------------------------
const std::vector<uint8_t>CsvFileFormat::getData() const
{
    return _data;
}
