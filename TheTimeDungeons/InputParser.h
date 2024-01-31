#ifndef INPUTPARSER_H
#define INPUTPARSER_H

#include <string>
#include <vector>

class InputParser {
public:
    InputParser();
    std::vector<std::string> parseInput(const std::string& input);

private:
    std::vector<std::string> tokenize(const std::string& input);
};

#endif // INPUTPARSER_H
