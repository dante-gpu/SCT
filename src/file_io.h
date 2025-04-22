#ifndef SCT_FILE_IO_H
#define SCT_FILE_IO_H

#include <string>
#include <vector>

std::vector<std::string> get_txt_files(const std::string& dir_path);
std::string read_file_content(const std::string& file_path);

#endif // SCT_FILE_IO_H
