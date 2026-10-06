class Solution {
public:
    int minAddToMakeValid(string s) {
        int res = 0, depth = 0;
        for (char c : s) {
            if (c == '(') {
                depth++;
            } else if (depth <= 0) {
                res++;
            } else { 
                depth--;
            }
        }
        res += depth;
        return res;
    }
};