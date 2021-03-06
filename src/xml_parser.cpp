#include "xml_parser.hpp"

using namespace std;

bool XmlParser::FindSupportedFormat(xmlNode *a_node, int *calls, std::string model, std::string type)
{
    xmlNode *cur_node = NULL;
    bool isThereAttribute = false;

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
                {
                    std::string sName(reinterpret_cast<char*>(value));
                    if ( model.compare(sName) == 0 )
                    {
                        // cout << "Model Compared: " << sName << endl;
                        cur_node = cur_node->children;
                        if ( xmlStrEqual(xmlCharStrdup("Settings"), cur_node->name) )
                        {
                            // cout << "Settings Founded" << endl;
                            xmlAttr *attribute2 = cur_node->properties;
                            while ( attribute2 )
                            {
                                xmlChar *value2 = xmlNodeListGetString(cur_node->doc, attribute2->children, 1);

                                if ( xmlStrEqual(xmlCharStrdup(type.c_str()), attribute2->name))
                                    if ( xmlStrEqual(xmlCharStrdup("yes"), value2 ) )
                                        // cout << "Type Supported: " << value2 << endl;
                                        return true;

                                xmlFree(value2);
                                attribute2 = attribute2->next;
                            }
                        }
                    }
                }

                xmlFree(value);
                attribute = attribute->next;
            }

            isThereAttribute = FindSupportedFormat(cur_node->children->children, calls, model, type);
        }
        else
        {
            isThereAttribute = FindSupportedFormat(cur_node->children, calls, model, type);
        }
    }

    return isThereAttribute;
}

bool XmlParser::verifySupportedFormat(std::string model, std::string type)
{
    bool formatIsSupported = false;

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

    if ( FindSupportedFormat(root_element, &calls, model, type) == true )
        formatIsSupported = true;

    /*free the document */
    xmlFreeDoc(doc);
    /*Clean up object */
    xmlCleanupParser();

    return formatIsSupported;
}

bool XmlParser::CompareAttribute(xmlNode *a_node, int *calls, std::string myAttribute)
{
    xmlNode *cur_node = NULL;
    bool isThereAttribute = false;

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
                {
                    std::string sName(reinterpret_cast<char*>(value));
                    if ( myAttribute.compare(sName) == 0 )
                        // printf ("Attribute founded: %s\n", value);
                        return true;
                }

                xmlFree(value);
                attribute = attribute->next;
            }

            isThereAttribute = CompareAttribute(cur_node->children->children, calls, myAttribute);
        }
        else
        {
            isThereAttribute = CompareAttribute(cur_node->children, calls, myAttribute);
        }
    }

    return isThereAttribute;
}

bool XmlParser::FindAttribute(std::string attribute)
{
    bool isThereAttribute = true;

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

    if ( CompareAttribute(root_element, &calls, attribute) == false )
        isThereAttribute = false;

    /*free the document */
    xmlFreeDoc(doc);
    /*Clean up object */
    xmlCleanupParser();

    return isThereAttribute;
}

void XmlParser::ParseTargetModelAttribute(xmlNode *a_node, int *calls)
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

void XmlParser::ParseSupportedTargets(void)
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
