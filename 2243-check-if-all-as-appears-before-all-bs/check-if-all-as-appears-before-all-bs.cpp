class Solution {
public:
    bool checkString(string s) {
        bool b = false;
        for (char c : s) {
            if (b && c == 'a') {
                return false;
            }
            b |= c == 'b';
        }
        return true;
    }
};