#ifndef TXT_FILE_FORMAT_HPP
#define TXT_FILE_FORMAT_HPP

#include "output_file.hpp"
#include "aegaeon_types.hpp"

class TxtFileFormat : public FormatFile {
    public:

    TxtFileFormat();
    virtual ~TxtFileFormat();

    const std::string getFileName() const;
    void setFileName(std::string fileNameNew);

    const std::vector<uint8_t>getData() const;
    void setData(std::vector<uint8_t>dataNew);
};
#endif // TXT_FILE_FORMAT_HPP
