class Solution {
public:
    string removeOuterParentheses(string s) {
        int depth = 0;
        std::string res = "";
        for (char c : s) {
            if ((c == '(' && depth++ != 0) ||
                (c == ')' && --depth != 0)) {
                    res += c;
            }
        }
        return res;
    }
};