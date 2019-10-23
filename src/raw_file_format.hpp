#ifndef RAW_FILE_FORMAT_HPP
#define RAW_FILE_FORMAT_HPP

#include "output_file.hpp"

class RawFileFormat : public FormatFile {
public:

	RawFileFormat();
	virtual ~RawFileFormat();

    const std::string getFileName() const;
    void setFileName(std::string fileNameNew);

    const std::vector<uint8_t> getData() const;
    void getData(std::vector<uint8_t> dataNew);
};

#endif // RAW_FILE_FORMAT_HPP