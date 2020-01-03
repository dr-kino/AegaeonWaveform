#include <iostream>
#include "generator.hpp"
#include "xml_parser.hpp"

using namespace std;

void Generator::showSupportedGenerators(void)
{
    ParseSupportedTargets();
}

bool Generator::compareSupportedGenerators(std::string generator)
{
    bool generatorIsSupported = true;

    if ( FindAttribute(generator) == false )
    {
        cout << "Generator not supported" << endl;
        generatorIsSupported = false;
    }

    return generatorIsSupported;
}
