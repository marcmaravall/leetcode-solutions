class Solution {
public:
    string getEncryptedString(string s, int k) {
        const int n = s.size();
        std::string res;
        res.resize(n);
        for (int i = 0; i < n; i++) {
            res[i] = s[(i+k)%n];
        }
        return res;
    }
};