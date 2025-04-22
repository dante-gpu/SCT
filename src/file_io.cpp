#include "file_io.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <__filesystem/filesystem>
namespace fs = std::__fs::filesystem;

std::vector<std::string> get_txt_files(const std::string& dir_path) {
    std::vector<std::string> file_paths;
    for (const auto& entry : fs::directory_iterator(dir_path)) {
        if (entry.is_regular_file() && entry.path().extension() == ".txt") {
            file_paths.push_back(entry.path().string());
        }
    }
    return file_paths;
}


std::string read_file_content(const std::string& file_path) {
    std::ifstream file(file_path);
    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}
