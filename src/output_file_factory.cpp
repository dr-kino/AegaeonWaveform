#include <memory>
#include "output_file_factory.hpp"
#include "csv_file_format.hpp"
#include "raw_file_format.hpp"
#include "txt_file_format.hpp"

/* Constructor */
OutputFileFactory::OutputFileFactory() {
}

/* Destructor */
OutputFileFactory::~OutputFileFactory() {
}

/** 
 * 
 * \brief createFile - Method responsible for factor
 *
 * \param FILE_TYPE fileType
 *
 * \return std::unique_ptr<FormatFile>
 *
 */ 
std::unique_ptr<FormatFile> OutputFileFactory::createFile(FILE_TYPE fileType) {
	switch(fileType) {
		case CSV_TYPE:  return std::make_unique<CsvFileFormat>();
		case RAW_TYPE: 	return std::make_unique<RawFileFormat>();
		case TXT_TYPE:  return std::make_unique<TxtFileFormat>();
		default:		return std::make_unique<RawFileFormat>();
	}
}
