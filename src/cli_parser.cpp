#include "cli_parser.h"
#include <iostream>
#include <getopt.h>

CliOptions parse_cli_args(int argc, char** argv) {
    CliOptions options;
    options.input_dir = "."; // Default input directory
    options.threshold = 0.85f; // Default threshold
    options.output_file = "similarity_results.csv"; // Default output file

    int opt;
    while ((opt = getopt(argc, argv, "i:t:o:")) != -1) {
        switch (opt) {
            case 'i':
                options.input_dir = optarg;
                break;
            case 't':
                options.threshold = std::stof(optarg);
                break;
            case 'o':
                options.output_file = optarg;
                break;
            default:
                std::cerr << "Usage: sct -i <input_dir> -t <threshold> -o <output_file>" << std::endl;
                exit(1);
        }
    }

    return options;
}
