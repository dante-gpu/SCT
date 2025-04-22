#ifndef SCT_CUDA_SIM_H
#define SCT_CUDA_SIM_H

#include <vector>

std::vector<std::tuple<int, int, float>> calculate_similarity_cuda(
    const std::vector<std::vector<float>>& tf_vectors,
    float threshold);

#endif // SCT_CUDA_SIM_H
