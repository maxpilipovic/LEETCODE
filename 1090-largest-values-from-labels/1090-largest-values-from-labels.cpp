class Solution {
public:
        int largestValsFromLabels(std::vector<int>& values, std::vector<int>& labels, int num_wanted, int use_limit)
{
    auto zip = [](const std::vector<int>& a, const std::vector<int>& b)
    {
        std::vector<std::pair<int, int>> result;
        size_t size = std::min(a.size(), b.size());
        result.reserve(size);
        for (size_t i = 0; i < size; ++i) {
            result.emplace_back(a[i], b[i]);
        }
        return result;
    };

    auto pairs = zip(values, labels);

    // Sort by descending value
    std::sort(pairs.begin(), pairs.end(), [](const auto& a, const auto& b) {
        return a.first > b.first;
    });

    std::unordered_map<int, int> label_count;
    int total = 0;
    int picked = 0;

    for (const auto& [value, label] : pairs) {
        if (picked == num_wanted) break;
        if (label_count[label] < use_limit) {
            total += value;
            label_count[label]++;
            picked++;
        }
    }

    return total;
}
};