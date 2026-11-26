class Solution {
public:
    int minSwaps(string s) {
        int open = 0, closed = 0;
        const int n = s.size();
        int res = 0;
        int i = 0;
        int right = n-1;
        for (char c : s) {
            if (c == '[') {
                open++;
            } else {
                if (closed+1 > open) {
                    for (right; s[right] != '['; right--) {}
                    std::swap(s[i], s[right]);
                    res++;
                    open++;
                } else {
                    closed++;
                }
            }
            i++;
        }
        return res;
    }
};