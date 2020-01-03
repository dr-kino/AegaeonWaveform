#include "generator.hpp"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <libxml/HTMLparser.h>
#include <libxml/xmlmemory.h>
#include <libxml/tree.h>
#include <libxml/parser.h>

void Generator::getSupportedGenerators(std::string *list, size_t listSize)
{
    const char *filename = "../config/SupportedTargets.xml";
}
