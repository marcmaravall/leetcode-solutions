class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        std::vector<std::vector<int>> res;

        std::function<void(std::vector<int>&, int, int)> backtracking = [&](std::vector<int>& vec, int start, int sum) {
            if (sum == n && vec.size() == k) {
                res.push_back(vec);
                return;
            }
            else if (vec.size() >= k || sum > n) {
                return;
            }

            for (int i = start; i <= 9; i++) {
                vec.push_back(i);
                backtracking(vec, i + 1, sum + i);
                vec.pop_back();
            }
        };

        std::vector<int> a;
        backtracking(a, 1, 0);

        return res;
    }
};
