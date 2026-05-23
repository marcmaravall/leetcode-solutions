class Solution {
public:
    bool checkString(string s) {
        int n = s.size();
        bool appearB = false;

        for (int i = 0; i < n; i++) {
            if (s[i] == 'a' && appearB) {
                return false;
            }
            else if (s[i] == 'b')
                appearB = true;
        }
        return true;
    }
};