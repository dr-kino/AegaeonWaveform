#include "output_file_factory.hpp"
#include "csv_file_format.hpp"
#include "raw_file_format.hpp"
#include "txt_file_fomart.hpp"

/** 
 * 
 * \brief createFile - Method responsible for factor
 *
 * \param FILE_TYPE fileType
 *
 * \return std::unique_ptr<FormatFile>
 *
 */ 
std::unique_ptr<FormatFile> FactoryFile::createFile(FILE_TYPE fileType) {
    switch(fileType) {
        case CSV_FILE:  return std::make_unique<CsvFile>();
        case RAW_FILE:  return std::make_unique<RawFile>();
        case TXT_FILE:  return std::make_unique<TxtFile>();
        default:        return std::make_unique<CsvFile>();
    }

}