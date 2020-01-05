#include <iostream>
#include "generator.hpp"
#include "xml_parser.hpp"

using namespace std;

bool Generator::verifySupportedFormat(std::string type)
{
    XmlParser XmlParserGen;
    return XmlParserGen.verifySupportedFormat(type);
}

void Generator::showSupportedGenerators(void)
{
    XmlParser XmlParserGen;
    XmlParserGen.ParseSupportedTargets();
}

bool Generator::compareSupportedGenerators(std::string generator)
{
    bool generatorIsSupported = true;
    XmlParser XmlParserGen;

    if ( XmlParserGen.FindAttribute(generator) == false )
    {
        cout << "Generator not supported" << endl;
        generatorIsSupported = false;
    }

    return generatorIsSupported;
}
