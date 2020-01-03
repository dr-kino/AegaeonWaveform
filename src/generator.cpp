#include <iostream>
#include "generator.hpp"
#include "xml_parser.hpp"

using namespace std;

void Generator::showSupportedGenerators(void)
{
    ParseSupportedTargets();
}

void Generator::compareSupportedGenerators(std::string generator)
{
    if ( FindAttribute(generator) == false )
        cout << "Generator not supported" << endl;
}
