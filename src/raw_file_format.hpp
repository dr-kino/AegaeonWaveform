#ifndef RAW_FILE_FORMAT_HPP
#define RAW_FILE_FORMAT_HPP

#include "output_file.hpp"
#include "aegaeon_types.hpp"

class RawFileFormat : public FormatFile {
    private:
    std::vector<uint8_t>_data;

    public:
    RawFileFormat();
    virtual ~RawFileFormat();

    bool readInputData(std::string fileName);

    void setFileName(std::string fileNameNew);
    const std::string getFileName() const;

    void setData(std::vector<uint8_t>dataNew);
    const std::vector<uint8_t>getData() const;
};
#endif // RAW_FILE_FORMAT_HPP
