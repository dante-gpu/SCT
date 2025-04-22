#include "vectorizer.h"
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

void Vectorizer::fit(const std::vector<std::vector<std::string>>& documents) {
    int word_index = 0;
    for (const auto& document : documents) {
        for (const auto& token : document) {
            if (vocabulary_.find(token) == vocabulary_.end()) {
                vocabulary_[token] = word_index++;
            }
        }
    }
}

std::vector<std::vector<float>> Vectorizer::transform(const std::vector<std::vector<std::string>>& documents) {
    std::vector<std::vector<float>> tf_vectors;
    for (const auto& document : documents) {
        std::vector<float> tf_vector(vocabulary_.size(), 0.0f);
        for (const auto& token : document) {
            if (vocabulary_.find(token) != vocabulary_.end()) {
                tf_vector[vocabulary_[token]]++;
            }
        }
        tf_vectors.push_back(tf_vector);
    }
    return tf_vectors;
}

std::unordered_map<std::string, int> Vectorizer::get_vocabulary() const {
    return vocabulary_;
}
