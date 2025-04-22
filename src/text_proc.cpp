#include "text_proc.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

std::string to_lowercase(const std::string& text) {
    std::string result = text;
    std::transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

std::string remove_punctuation(const std::string& text) {
    std::string result = "";
    for (char c : text) {
        if (!ispunct(c)) {
            result += c;
        } else {
            result += ' '; // Replace punctuation with space
        }
    }
    return result;
}

std::vector<std::string> tokenize(const std::string& text) {
    std::vector<std::string> tokens;
    std::stringstream ss(text);
    std::string token;
    while (ss >> token) {
        tokens.push_back(token);
    }
    return tokens;
}
