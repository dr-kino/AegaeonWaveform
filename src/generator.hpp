#ifndef GENERATOR_HPP
#define GENERATOR_HPP

#include <string>

class Generator {
    private:
    std::string currentModel_;
    std::string *generatorList_;
    size_t listSize;

    public:
    void showSupportedGenerators(void);
    void compareSupportedGenerators(std::string generator);
};
#endif // GENERATOR_HPP
