
#ifndef OUTPUT_FILE_FACTORY_HPP
#define OUTPUT_FILE_FACTORY_HPP

#include <memory>
#include <output_file.hpp>

/**
 * \class OutputFileFactory
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
class OutputFileFactory
{
public:
    /* Enumerator */
    enum FILE_TYPE {CSV_TYPE, RAW_TYPE, TXT_TYPE};

    OutputFileFactory();
    virtual ~OutputFileFactory();
    
    static std::unique_ptr<FormatFile> createFile(FILE_TYPE fileType);

};
/* Constructor */
OutputFileFactory::OutputFileFactory(){ }

/* Destructor */
OutputFileFactory::~OutputFileFactory(){ }

#endif // OUTPUT_FILE_FACTORY_HPP