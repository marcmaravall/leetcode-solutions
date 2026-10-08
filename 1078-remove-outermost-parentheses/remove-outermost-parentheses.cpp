class Solution {
public:
    string removeOuterParentheses(string s) {
        std::string res = "";
        int depth = 0;
        for (char c : s) {
            if (c == '(') {
                if (depth++ != 0)
                    res += c;
            } else {
                if (--depth != 0)
                    res += c;
            }
        }
        return res;
    }
};