/**
 * @file aegaeon.cpp
 *
 * @brief Main module, responsible to handle information exchange with user
 *
 * @ingroup Aegaeon
 *
 * @author Rafael Cavalcanti
 * Contact: doctorkinoo@gmail.com
 *
 */
#include "aegaeon.hpp"
#include "generator.hpp"
#include "xml_parser.hpp"
#include "output_file_factory.hpp"
#include <boost/program_options.hpp>
#include <iostream>
#include <iterator>
#include <memory>

namespace po = boost::program_options;
using namespace std;

std::unique_ptr<AegaeonUnit>AegaeonUnit::instance_;

// Constructor
AegaeonUnit::AegaeonUnit()
{
}
// Destructor
AegaeonUnit::~AegaeonUnit()
{
}
// Singleton Method
AegaeonUnit&AegaeonUnit::getInstance(void)
{
    if ( nullptr == instance_ )
        instance_.reset(new AegaeonUnit());

    return *(instance_.get());
}
// Setteres and Getteres for private variable "Aegaeon.type"
void AegaeonUnit::setType(unsigned char type)
{
    Aegaeon_.type = type;
}
unsigned char AegaeonUnit::getType(void)
{
    return Aegaeon_.type;
}
// Setteres and Getteres for private variable "Aegaeon.waveformName"
void AegaeonUnit::setWaveformName(std::string waveformName)
{
    Aegaeon_.waveformName = waveformName;
}
std::string AegaeonUnit::getWaveformName(void)
{
    return Aegaeon_.waveformName;
}
// Setteres and Getteres for private variable "Aegaeon.outputFileName"
void AegaeonUnit::setOutputFileName(std::string outputFileName)
{
    Aegaeon_.outputFileName = outputFileName;
}
std::string AegaeonUnit::getOutputFileName(void)
{
    return Aegaeon_.outputFileName;
}

int main(int ac, char *av[])
{
    bool isThereAllArgs = true;
    Generator AegaeonGenerator;

    try
    {
        po::options_description desc("Allowed options");
        desc.add_options()
            ("help", "produce help message")
            ("type", po::value<string>(), "set output type format")
            ("waveform", po::value<string>(), "file name for input waveform")
            ("filename", po::value<string>(), "file name for function generator")
            ("generator", po::value<string>(), "set generator model")
            ("list", "list all supported function generator")
        ;

        po::variables_map vm;
        po::store(po::parse_command_line(ac, av, desc), vm);
        po::notify(vm);

        if ( vm.count("help") )
        {
            cout << desc << "\n";
            return 0;
        }

        if ( vm.count("list"))
        {
            AegaeonGenerator.showSupportedGenerators();
            return 0;
        }

        /* Handler for type option */
        if ( vm.count("type"))
        {
            // cout << "Type was set to " << vm["type"].as<string>() << ".\n";
            if ( vm["type"].as<string>().compare("csv") == 0 )
            {
                AegaeonUnit::getInstance().setType(csv);
            }
            else if ( vm["type"].as<string>().compare("raw") == 0 )
            {
                AegaeonUnit::getInstance().setType(raw);
            }
            else if ( vm["type"].as<string>().compare("txt") == 0 )
            {
                AegaeonUnit::getInstance().setType(txt);
            }
            else
            {
                cout << "The output file format is not supported" << endl;
                isThereAllArgs = false;
            }
        }
        else
        {
            cout << "Type was not set.\n";
            isThereAllArgs = false;
        }

        /* Handler for waveform option */
        if ( vm.count("waveform"))
        {
            // cout << "Waveform was set to " << vm["waveform"].as<string>() << ".\n";
            if ( access(vm["waveform"].as<string>().c_str(), F_OK) == -1 )
            {
                cout << "Failure to open waveform file" << endl;
                isThereAllArgs = false;
            }
            else
            {
                AegaeonUnit::getInstance().setWaveformName(vm["waveform"].as<string>());
            }
        }
        else
        {
            cout << "Waveform was not set.\n";
            isThereAllArgs = false;
        }

        /* Handler for filename option */
        if ( vm.count("filename"))
        {
            // cout << "Output file: " << vm["filename"].as<string>() << "\n";
            AegaeonUnit::getInstance().setOutputFileName(vm["filename"].as<string>());
        }
        else
        {
            cout << "No outputfile file specified\n";
            isThereAllArgs = false;
        }

        /* Handler for generator option */
        if ( vm.count("generator"))
        {
            isThereAllArgs = AegaeonGenerator.compareSupportedGenerators(vm["generator"].as<string>());
        }
        else
        {
            cout << "No generator model specified\n";
            isThereAllArgs = false;
        }

        /* Command execution */
        if ( isThereAllArgs == true )
            cout << "Executing operation..." << endl;

        /* Verify if the target suppots the output file format */
        if ( AegaeonGenerator.verifySupportedFormat(vm["generator"].as<string>(), vm["type"].as<string>()) == true )
        {
            std::unique_ptr<FormatFile>CsvFile = OutputFileFactory::createFile(OutputFileFactory::CSV_TYPE);
            std::unique_ptr<FormatFile>RawFile = OutputFileFactory::createFile(OutputFileFactory::RAW_TYPE);
            std::unique_ptr<FormatFile>TxtFile = OutputFileFactory::createFile(OutputFileFactory::TXT_TYPE);
            /* Executes the command */
            switch ( AegaeonUnit::getInstance().getType())
            {
            case csv:
                CsvFile->setFileName(vm["filename"].as<string>());
                break;
            case raw:
                // Set file name
                RawFile->setFileName(vm["filename"].as<string>());
                // Read the waveform
                RawFile->readInputData(vm["waveform"].as<string>());
                // Make the output file

                break;
            case txt:
                TxtFile->setFileName(vm["filename"].as<string>());
                break;
            default:
                break;
            }
        }
        else
        {
            cout << "Format type not supported" << endl;
        }
    }
    catch ( exception &e )
    {
        cerr << "error: " << e.what() << "\n";
        return 1;
    }
    catch ( ... )
    {
        cerr << "Exception of unknown type!\n";
    }

    return 0;
}
