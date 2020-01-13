#ifndef OUTPUT_FILE_HPP
#define OUTPUT_FILE_HPP

#include <iostream>
#include <vector>
#include <string>

class FormatFile
{
    public:
    virtual ~FormatFile()
    {
    }

    virtual bool readInputData(std::string fileName) = 0;
    virtual void setFileName(std::string fileNameNew) = 0;
    virtual const std::string getFileName() const = 0;
    virtual void setData(std::vector<uint8_t>dataNew) = 0;
    virtual const std::vector<uint8_t>getData() const = 0;

    protected:
    std::string _fileName;
    std::vector<uint8_t>_data;
};
#endif // OUTPUT_FILE_HPP
