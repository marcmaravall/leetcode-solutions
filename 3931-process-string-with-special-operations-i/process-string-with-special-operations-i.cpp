class Solution {
public:
    string processStr(string s) {
        std::string res = "";
        for (char c : s) {
            if (c == '*') {
                if (res.size() >= 1) res.pop_back();
            } else if (c == '#') {
                res += res;
            } else if (c == '%') {
                std::reverse(res.begin(), res.end());
            } else
                res += c;

        }
        return res;
    }
};