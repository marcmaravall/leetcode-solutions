class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        std::unordered_map<std::string_view, int> freq;
        int maxFreq = 0;
        for (const auto& word : words) {
            maxFreq = std::max(maxFreq, ++freq[word]);
        }
        std::vector<std::string> res;
        for (auto [str, f] : freq) {
            res.emplace_back(str);
        }
        std::sort(res.begin(), res.end(), [&](const auto& a, const auto& b) {
            if (freq[a] != freq[b]) {
                return freq[a] > freq[b];
            }
            return a < b;
        });
        res.resize(k);
        return res;
    }
};