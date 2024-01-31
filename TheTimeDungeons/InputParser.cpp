#include "InputParser.h"
#include <sstream>

InputParser::InputParser() {}

std::vector<std::string> InputParser::parseInput(const std::string& input) {
    return tokenize(input);
}

std::vector<std::string> InputParser::tokenize(const std::string& input) {
    std::stringstream stream(input);
    std::string token;
    std::vector<std::string> tokens;

    while (getline(stream, token, ' ')) {
        tokens.push_back(token);
    }

    return tokens;
}
