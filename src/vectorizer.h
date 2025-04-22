#ifndef SCT_VECTORIZER_H
#define SCT_VECTORIZER_H

#include <string>
#include <vector>
#include <unordered_map>

class Vectorizer {
public:
    void fit(const std::vector<std::vector<std::string>>& documents);
    std::vector<std::vector<float>> transform(const std::vector<std::vector<std::string>>& documents);
    std::unordered_map<std::string, int> get_vocabulary() const;

private:
    std::unordered_map<std::string, int> vocabulary_;
};

#endif // SCT_VECTORIZER_H
