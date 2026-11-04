class Solution {
public:
    std::string backspace(const std::string& str) {
        const int n = str.size();
        std::string res(n, ' ');
        int cursor = 0;
        for (int i = 0; i < n; i++) {
            if (str[i] != '#') {
                res[cursor++] = str[i];
            } else if (--cursor <= 0) {
                cursor = 0;
            }
        }
        res.resize(cursor);
        return res;
    }

    bool backspaceCompare(string s, string t) {
        std::string a = backspace(s), b = backspace(t);
        return a == b;
    }
};