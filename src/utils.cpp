#include "utils.h"
#include <iostream>
#include <sstream>
#include <iomanip>

std::string format_similarity_result(const std::string& file1, const std::string& file2, float similarity) {
    std::stringstream ss;
    ss << file1 << ", " << file2 << ", " << std::fixed << std::setprecision(2) << similarity;
    return ss.str();
}
