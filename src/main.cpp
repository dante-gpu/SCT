#include <iostream>
#include <string>
#include <vector>
#include "cli_parser.h"
#include "file_io.h"
#include "text_proc.h"
#include "vectorizer.h"
#include "cuda_sim.h"
//#include "cuda_sim.h"
#include "utils.h"

int main(int argc, char** argv) {
    CliOptions options = parse_cli_args(argc, argv);

    std::vector<std::string> file_paths = get_txt_files(options.input_dir);
    std::vector<std::string> file_contents;
    for (const auto& file_path : file_paths) {
        file_contents.push_back(read_file_content(file_path));
    }

    std::vector<std::vector<std::string>> documents;
    for (const auto& content : file_contents) {
        std::string lowercase_content = to_lowercase(content);
        std::string no_punctuation_content = remove_punctuation(lowercase_content);
        documents.push_back(tokenize(no_punctuation_content));
    }

    Vectorizer vectorizer;
    vectorizer.fit(documents);
    std::vector<std::vector<float>> tf_vectors = vectorizer.transform(documents);

    std::vector<std::tuple<int, int, float>> similarity_results =
        calculate_similarity_cuda(tf_vectors, options.threshold);

    for (const auto& result : similarity_results) {
        int i = std::get<0>(result);
        int j = std::get<1>(result);
        float similarity = std::get<2>(result);
        std::cout << format_similarity_result(file_paths[i], file_paths[j], similarity) << std::endl;
    }

    return 0;
}
