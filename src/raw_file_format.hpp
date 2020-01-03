#ifndef RAW_FILE_FORMAT_HPP
#define RAW_FILE_FORMAT_HPP

#include "output_file.hpp"

class RawFileFormat : public FormatFile {
    public:

    RawFileFormat();
    virtual ~RawFileFormat();

    void setFileName(std::string fileNameNew);
    const std::string getFileName() const;
    void setData(std::vector<uint8_t>dataNew);
    const std::vector<uint8_t>getData() const;
};
#endif // RAW_FILE_FORMAT_HPP
