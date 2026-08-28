class Solution {
public:
    string reverseStr(string s, int k) {
        const int n = s.size();
        for (int i = 0; i < n; i += 2*k) {
            if (i+k >= n)
                k = n-i;
            std::reverse(s.begin()+i, s.begin()+i+k);
        }
        return s;
    }
};