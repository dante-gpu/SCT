#include "cuda_sim.h"
#include <iostream>
#include <vector>
#include <tuple>
#include <cmath>

__global__ void calculate_cosine_similarity_kernel(
    const float* vec_i, const float* vec_j, float* result, int vec_size) {
    int idx = blockIdx.x * blockDim.x + threadIdx.x;
    if (idx >= vec_size) return;

    float dot_product = 0.0f;
    float norm_i = 0.0f;
    float norm_j = 0.0f;

    for (int k = 0; k < vec_size; ++k) {
        dot_product += vec_i[k] * vec_j[k];
        norm_i += vec_i[k] * vec_i[k];
        norm_j += vec_j[k] * vec_j[k];
    }

    norm_i = sqrtf(norm_i);
    norm_j = sqrtf(norm_j);

    if (norm_i == 0.0f || norm_j == 0.0f) {
        *result = 0.0f;
    } else {
        *result = dot_product / (norm_i * norm_j);
    }
}

std::vector<std::tuple<int, int, float>> calculate_similarity_cuda(
    const std::vector<std::vector<float>>& tf_vectors,
    float threshold) {
    std::vector<std::tuple<int, int, float>> results;
    int num_docs = tf_vectors.size();

    for (int i = 0; i < num_docs; ++i) {
        for (int j = i + 1; j < num_docs; ++j) {
            int vec_size = tf_vectors[i].size();

            float* dev_vec_i;
            float* dev_vec_j;
            float* dev_result;

            cudaMalloc((void**)&dev_vec_i, vec_size * sizeof(float));
            cudaMalloc((void**)&dev_vec_j, vec_size * sizeof(float));
            cudaMalloc((void**)&dev_result, sizeof(float));

            cudaMemcpy(dev_vec_i, tf_vectors[i].data(), vec_size * sizeof(float), cudaMemcpyHostToDevice);
            cudaMemcpy(dev_vec_j, tf_vectors[j].data(), vec_size * sizeof(float), cudaMemcpyHostToDevice);

            calculate_cosine_similarity_kernel<<<1, 1>>>(dev_vec_i, dev_vec_j, dev_result, vec_size);

            float similarity;
            cudaMemcpy(&similarity, dev_result, sizeof(float), cudaMemcpyDeviceToHost);

            cudaFree(dev_vec_i);
            cudaFree(dev_vec_j);
            cudaFree(dev_result);

            if (similarity >= threshold) {
                results.emplace_back(i, j, similarity);
            }
        }
    }

    return results;
}
