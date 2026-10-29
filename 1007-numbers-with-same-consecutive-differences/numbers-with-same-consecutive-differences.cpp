class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        std::vector<int> res = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        for (int i = 2; i <= n; i++) {
            std::vector<int> curr{};
            for (int x : res) {
                int y = x%10;
                if (y+k < 10)
                    curr.push_back(x*10+y+k);
                if (k > 0 && y-k >= 0)
                    curr.push_back(x*10+y-k);
            }
            res = curr;
        }
        return res;
    }
};