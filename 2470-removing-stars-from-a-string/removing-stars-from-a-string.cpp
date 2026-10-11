class Solution {
public:
    string removeStars(string s) {
        int pos = 0;
        for (char c : s) {
            if (c == '*') {
                pos--;
            } else {
                s[pos++] = c;
            }
        }
        s.resize(pos);
        return s;
    }
};