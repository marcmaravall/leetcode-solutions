class Solution {
public:
    bool canBeValid(string s, string locked) {
        int min = 0, max = 0;
        const int n = s.size();
        for (int i = 0; i < n; i++) {
            if (locked[i] == '0')
                min--, max++;
            else if (s[i] == '(')
                min++, max++;
            else 
                min--, max--;
            if (max < 0)
                return false;
            if (min == -1)
                min = 1;
        }
        return min == 0;
    }
};