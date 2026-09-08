struct ArrayHasher {
    size_t operator()(const std::array<int, 26>& a) const {
        size_t h = 0;
        for (auto e : a) {
            h ^= std::hash<int>{}(e) + 0x9e3779b9 + (h << 6) + (h >> 2);
        }
        return h;
    }
};

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<std::array<int, 26>, std::vector<std::string>, ArrayHasher> anagrams;
        for (auto& str : strs) {
            std::array<int, 26> freq = {0};
            for (char c : str)
                freq[c-'a']++;
            anagrams[freq].push_back(str);
        }
        std::vector<std::vector<std::string>> res;
        for (auto [letterFreq, vec] : anagrams)
            res.push_back(vec);
        return res;
    }
};