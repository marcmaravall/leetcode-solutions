class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        const int n = s.size();
        std::vector<std::string> res;
        for (int i = 0; i < n; i+=k) {
            std::string curr{};
            for (int j = i; j < i+k && j < n; j++) {
                curr += s[j];
            }
            res.push_back(curr);
        }
        const int diff = k-res[res.size()-1].size();
        std::cout << diff;
        for (int i = 0; i < diff; i++)
            res[res.size()-1] += fill;
        return res;
    }
};