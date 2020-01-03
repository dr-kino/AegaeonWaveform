#include "xml_parser.hpp"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <libxml/HTMLparser.h>
#include <libxml/xmlmemory.h>
#include <libxml/tree.h>
#include <libxml/parser.h>

#include <libxml/xmlreader.h>

void ParseTargetModelAttribute(xmlNode *a_node, int *calls)
{
    xmlNode *cur_node = NULL;

    for ( cur_node = a_node; cur_node; cur_node = cur_node->next )
    {
        (*calls)++;
        if ( xmlStrEqual(xmlCharStrdup("Target"), cur_node->name))
        {
            // printf("node type: <%d>, name <%s>, content: <%s> \n", cur_node->children->type, cur_node->children->name, cur_node->children->content);
            xmlAttr *attribute = cur_node->properties;
            while ( attribute )
            {
                xmlChar *value = xmlNodeListGetString(cur_node->doc, attribute->children, 1);
                if ( xmlStrEqual(xmlCharStrdup("model"), attribute->name))
                    printf ("\tTarget Model: %s\n", value);

                xmlFree(value);
                attribute = attribute->next;
            }

            ParseTargetModelAttribute(cur_node->children->children, calls);
        }
        else
        {
            ParseTargetModelAttribute(cur_node->children, calls);
        }
    }
}

void ParseSupportedTargets(void)
{
    const char *filename = "../config/SupportedTargets.xml";

    xmlDoc *doc = NULL;
    xmlNode *root_element = NULL;

    /*parse the file and get the DOM */
    doc = xmlReadFile(filename, NULL, XML_PARSE_NOBLANKS);

    if ( doc == NULL )
        printf("error: could not parse file %s\n", filename);

    int calls = 0;
    /*Get the root element node */
    root_element = xmlDocGetRootElement(doc);
    printf("List of Supported Targets:\n");
    ParseTargetModelAttribute(root_element, &calls);

    /*free the document */
    xmlFreeDoc(doc);
    /*Clean up object */
    xmlCleanupParser();
}
