#include "utils.h"
#include <iostream>
#include <sstream>
#include <iomanip>

#include "utils.h"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <algorithm>

std::string format_similarity_result(const std::string& file1, const std::string& file2, float similarity) {
    std::string f1 = file1;
    std::string f2 = file2;
    if (f1 > f2) {
        std::swap(f1, f2);
    }
    std::stringstream ss;
    ss << f1 << ", " << f2 << ", " << std::fixed << std::setprecision(2) << similarity;
    return ss.str();
}
