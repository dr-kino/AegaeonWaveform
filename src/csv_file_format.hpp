#ifndef CSV_FILE_FORMAT_HPP
#define CSV_FILE_FORMAT_HPP

#include "output_file.hpp"

class CsvFileFormat : public FormatFile {
public:

	CsvFileFormat();
	virtual ~CsvFileFormat();

    const std::string getFileName() const;
    void setFileName(std::string fileNameNew);

    const std::vector<uint8_t> getData() const;
    void getData(std::vector<uint8_t> dataNew);
};

#endif // CSV_FILE_FORMAT_HPP