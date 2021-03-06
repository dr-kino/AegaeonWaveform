#ifndef GENERATOR_HPP
#define GENERATOR_HPP

#include <string>

class Generator {
    private:
    std::string currentModel_;
    std::string *generatorList_;
    size_t listSize;

    public:
    bool verifySupportedFormat(std::string model, std::string type);
    void showSupportedGenerators(void);
    bool compareSupportedGenerators(std::string generator);
};
#endif // GENERATOR_HPP
