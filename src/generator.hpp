#ifndef GENERATOR_HPP
#define GENERATOR_HPP

#include <string>

class Generator {
    private:
    std::string currentModel_;
    std::string *generatorList_;
    size_t listSize;

    public:
    void getSupportedGenerators(std::string *list, size_t listSize);
};
#endif // GENERATOR_HPP
