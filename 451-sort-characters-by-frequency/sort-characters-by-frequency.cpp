class Solution {
public:
    string frequencySort(string s) {
        std::vector<std::pair<char, int>> freq(127);
        for (char c : s) {
            freq[c].first = c;
            freq[c].second++;
        }
        const int n = s.size();
        std::sort(freq.begin(), freq.end(), [](auto& a, auto& b) {
            return a.second > b.second;
        });
        int i = 0;
        std::string res;
        res.resize(n);
        for (int j = 0; j < 127; j++) {
            for (int k = 0; k < freq[j].second; k++) {
                res[i++] = freq[j].first;
            }
        }
        return res;
    }
};