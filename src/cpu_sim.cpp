#include <iostream>
#include <vector>
#include <tuple>
#include <cmath>
#include "cuda_sim.h" // Use the same header for CPU implementation

std::vector<std::tuple<int, int, float>> calculate_similarity_cpu(
    const std::vector<std::vector<float>>& tf_vectors,
    float threshold) {
    std::vector<std::tuple<int, int, float>> results;
    int num_docs = tf_vectors.size();

    for (int i = 0; i < num_docs; ++i) {
        for (int j = i + 1; j < num_docs; ++j) {
            float dot_product = 0.0f;
            float norm_i = 0.0f;
            float norm_j = 0.0f;
            int vec_size = tf_vectors[i].size();

            for (int k = 0; k < vec_size; ++k) {
                dot_product += tf_vectors[i][k] * tf_vectors[j][k];
                norm_i += tf_vectors[i][k] * tf_vectors[i][k];
                norm_j += tf_vectors[j][k] * tf_vectors[j][k];
            }

            norm_i = sqrtf(norm_i);
            norm_j = sqrtf(norm_j);

            float similarity = 0.0f;
            if (norm_i != 0.0f && norm_j != 0.0f) {
                similarity = dot_product / (norm_i * norm_j);
            }

            if (similarity >= threshold) {
                results.emplace_back(i, j, similarity);
            }
        }
    }

    return results;
}

std::vector<std::tuple<int, int, float>> calculate_similarity_cuda(
    const std::vector<std::vector<float>>& tf_vectors,
    float threshold) {
    // Redirect to CPU implementation
    return calculate_similarity_cpu(tf_vectors, threshold);
}
