#ifndef SCT_CLI_PARSER_H
#define SCT_CLI_PARSER_H

#include <string>

struct CliOptions {
    std::string input_dir;
    float threshold;
    std::string output_file;
};

CliOptions parse_cli_args(int argc, char** argv);

#endif // SCT_CLI_PARSER_H
