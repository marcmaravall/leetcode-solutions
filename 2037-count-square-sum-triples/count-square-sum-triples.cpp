class Solution {
public:
    int countTriples(int n) {
        int res = 0;
        for (int a = 1; a <= n; a++) {
            for (int b = 1; b <= n; b++) {
                int m = a*a+b*b;
                int c = std::sqrt(m);
                if (c <= n && c*c == m) {
                    res++;
                }
            }
        }
        return res;
    }
};