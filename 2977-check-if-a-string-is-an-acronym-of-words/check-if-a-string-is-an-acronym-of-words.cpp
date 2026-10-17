class Solution {
public:
    bool isAcronym(vector<string>& words, string s) {
        const int n = words.size();
        if (s.size() != n)
            return false;
        for (int i = 0; i < n; i++) {
            if (words[i][0] != s[i])
                return false;
        }
        return true;
    }
};