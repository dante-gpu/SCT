#ifndef SCT_TEXT_PROC_H
#define SCT_TEXT_PROC_H

#include <string>
#include <vector>

std::string to_lowercase(const std::string& text);
std::string remove_punctuation(const std::string& text);
std::vector<std::string> tokenize(const std::string& text);

#endif // SCT_TEXT_PROC_H
