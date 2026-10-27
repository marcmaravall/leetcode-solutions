class Solution {
public:
    string stringHash(string s, int k) {
        const int n = s.size();
        std::string res(n/k, ' ');
        for (int i = 0; i < n; i += k) {
            int sum = 0;
            for (int j = 0; j < k; j++) {
                sum += s[i+j]-'a';
            }
            res[i/k] = (sum%26)+'a';
        }
        return res;
    }
};