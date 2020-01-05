#ifndef XML_PARSER_HPP
#define XML_PARSER_HPP

#include <string>
#include <iostream>
#include <libxml/xmlreader.h>
#include "aegaeon_types.hpp"

class XmlParser
{
    private:
    Target_t _Target;
    bool CompareAttribute(xmlNode *a_node, int *calls, std::string myAttribute);
    void ParseTargetModelAttribute(xmlNode *a_node, int *calls);
    public:
    bool verifySupportedFormat(std::string type);
    bool FindAttribute(std::string attribute);
    void ParseSupportedTargets(void);
};
#endif // XML_PARSER_HPP
