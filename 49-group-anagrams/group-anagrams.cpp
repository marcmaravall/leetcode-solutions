class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<std::string, std::vector<std::string>> anagrams;
        for (auto& str : strs) {
            std::string sorted = str;
            std::sort(sorted.begin(), sorted.end());
            anagrams[sorted].push_back(str);
        }
        std::vector<std::vector<std::string>> res;
        for (auto [letterFreq, vec] : anagrams)
            res.push_back(vec);
        return res;
    }
};