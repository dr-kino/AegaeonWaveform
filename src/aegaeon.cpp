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
#include <boost/program_options.hpp>
#include <iostream>
#include <iterator>
#include <memory>

namespace po = boost::program_options;
using namespace std;

std::unique_ptr<AegaeonUnit> AegaeonUnit::instance_;

// Constructor
AegaeonUnit::AegaeonUnit() {

}
// Destructor
AegaeonUnit::~AegaeonUnit() {

}
// Singleton Method
AegaeonUnit& AegaeonUnit::getInstance(void)
{
    if(nullptr == instance_)
    {
        instance_.reset(new AegaeonUnit());
    }
    return *(instance_.get());
}
// Setteres and Getteres for private variable "Aegaeon.type"
void AegaeonUnit::setType(unsigned char type) {

}
unsigned char AegaeonUnit::getType(void) {

}
// Setteres and Getteres for private variable "Aegaeon.waveformName"
void AegaeonUnit::setWaveformName(std::string waveformName) {

}
std::string AegaeonUnit::getWaveformName(void) {

}
// Setteres and Getteres for private variable "Aegaeon.outputFileName"
void AegaeonUnit::setOutputFileName(std::string outputFileName) {

}
std::string AegaeonUnit::getOutputFileName(void) {

}

int main(int ac, char* av[])
{
    bool isThereAllArgs = true;
    outputFile_t outputFile;

    try {

        po::options_description desc("Allowed options");
        desc.add_options()
        ("help", "produce help message")
        ("type", po::value<string>(), "set output type format")
        ("waveform", po::value<string>(), "file name for input waveform")
        ("fileout", po::value<string>(), "file name for function generator")
        ;

        po::variables_map vm;        
        po::store(po::parse_command_line(ac, av, desc), vm);
        po::notify(vm);    

        if (vm.count("help")) {
            cout << desc << "\n";
            return 0;
        }

        if (vm.count("type")) {
            cout << "Type was set to " << vm["type"].as<string>() << ".\n";
            if(vm["type"].as<string>().compare("csv") == 0) {
                outputFile = csv;
            } else if (vm["type"].as<string>().compare("txt") == 0) {
                outputFile = txt;
            } else if (vm["type"].as<string>().compare("raw") == 0) {
                outputFile = raw;
            } else {
                cout << "The output file format is not supported" << endl;
                isThereAllArgs = false;
            }

        } else {
            cout << "Type was not set.\n";
            isThereAllArgs = false;
        }

        if (vm.count("waveform")) {
            cout << "Waveform was set to " << vm["waveform"].as<string>() << ".\n";
            if (access(vm["waveform"].as<string>().c_str(), F_OK) == -1) {
                cout << "Failure to open waveform file" << endl;
                isThereAllArgs = false;
            }
        } else {
            cout << "Waveform was not set.\n";
            isThereAllArgs = false;
        }

        if (vm.count("fileout")) {
            cout << "Output file: " << vm["fileout"].as<string>() << "\n";
        } else {
            cout << "No outputfile file specified\n";
            isThereAllArgs = false;
        }

        if (isThereAllArgs == true) {
            cout << "Executing operation" << endl;

        }

    }
    catch(exception& e) {
        cerr << "error: " << e.what() << "\n";
        return 1;
    }
    catch(...) {
        cerr << "Exception of unknown type!\n";
    }

    return 0;
}