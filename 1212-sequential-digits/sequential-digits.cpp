class Solution {
public:
    inline static int q[45];
    inline static bool init = []() {
        int n = 0;
        for (int i = 1; i < 10; i++) {
            q[n++] = i;
        }

        for (int i = 0; i < n; i++) {
            int d = q[i] % 10;
            if (d < 9)
                q[n++] = q[i]*10 + d+1;
        }
        return false;
    }();

    vector<int> sequentialDigits(int low, int high) {
        std::vector<int> res;
        for (int n : q) {
            if (n >= low && n <= high) {
                res.push_back(n);
            }
        }
        return res;
    }
};