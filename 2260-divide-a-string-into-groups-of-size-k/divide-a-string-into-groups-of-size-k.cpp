class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        const int n = s.size();
        std::vector<std::string> res(n/k+(n%k != 0), std::string(k, ' '));
        for (int i = 0; i < n; i+=k) {
            for (int j = i; j < i+k && j < n; j++) {
                res[i/k][j-i] = s[j];
            }
        }
        auto& back = res.back();
        for (char& c : back) {
            if (c == ' ') c = fill;
        }
        return res;
    }
};