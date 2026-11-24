class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        std::vector<int> res;
        while (label > 0) {
            res.push_back(label);
            label /= 2;
        }
        for (int i = res.size()-1; i >= 0; i--) {
            if (i % 2 == 1) {
                res[i] = 3*(1 << (res.size()-i-1))-res[i]-1;
            }
        }
        std::reverse(res.begin(), res.end());
        return res;
    }
};