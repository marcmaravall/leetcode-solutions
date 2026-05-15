class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        std::vector<std::vector<int>> res;
        
        int size = candidates.size();

        std::function<void(std::vector<int>&, int, int)> backtracking = [&](std::vector<int>& vec, int index, int sum) {
            if (sum == target) {
                res.push_back(vec);
                return;
            } else if (sum > target) {
                return;
            }

            int start = index+1;
            for (int i = start; i < size; i++) {
                if (i > start && candidates[i-1] == candidates[i])
                    continue;
                
                vec.push_back(candidates[i]);
                backtracking(vec, i, sum + candidates[i]);
                vec.pop_back();
            }
        };

        std::vector<int> vec;
        backtracking(vec, -1, 0);

        return res;
    }
};