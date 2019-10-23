#ifndef OUTPUT_FILE_HPP
#define OUTPUT_FILE_HPP

#include <iostream>
#include <vector>

/**
 * \class FormatFile
 *
 * \ingroup OutputFileFactory
 * (Note, this needs exactly one \defgroup somewhere)
 *
 * \brief Provide an example
 *
 * This class is meant as an example.  It is not useful by itself
 * rather its usefulness is only a function of how much it helps
 * the reader.  It is in a sense defined by the person who reads it
 * and otherwise does not exist in any real form. 
 *
 * \note Attempts at zen rarely work.
 *
 * \author $Author: dr-kino $
 *
 * \version $Revision: 1.0 $
 *
 * \date $Date: 2019/10/20 14:16:20 $
 *
 * Contact: doctorkinoo@gmail.com
 *
 * Created on: Sun Apr 13 18:16:20 2019
 *
 * $Id: doxygen-howto.html,v 1.0 2019/10/20 18:16:20 dr-kino Exp $
 *
 */
class FormatFile
{
public:
    virtual ~FormatFile() {}

    virtual const std::string getFileName() const = 0;
    virtual void setFileName(std::string fileNameNew) = 0;

    virtual const std::vector<uint8_t> getData() const = 0;
    virtual void setData(std::vector<uint8_t> dataNew) = 0;
        
protected:
        std::string _fileName;
        std::vector<uint8_t> _data;
};

#endif // OUTPUT_FILE_HPP