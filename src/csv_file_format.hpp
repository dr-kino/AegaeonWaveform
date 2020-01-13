#ifndef CSV_FILE_FORMAT_HPP
#define CSV_FILE_FORMAT_HPP

#include "output_file.hpp"
#include "aegaeon_types.hpp"

class CsvFileFormat : public FormatFile {
    private:
    std::vector<uint8_t>_data;

    public:
    CsvFileFormat();
    virtual ~CsvFileFormat();

    bool readInputData(std::string fileName);

    const std::string getFileName() const;
    void setFileName(std::string fileNameNew);

    const std::vector<uint8_t>getData() const;
    void setData(std::vector<uint8_t>dataNew);
};
#endif // CSV_FILE_FORMAT_HPP
