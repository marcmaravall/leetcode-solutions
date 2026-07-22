class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        const int n = nums.size();
        const int m = queries.size();
        std::sort(nums.begin(), nums.end());
        for (int i = 1; i < n; i++){
            nums[i] += nums[i-1];
        }
        std::vector<int> res(m);
        for (int i = 0; i < m; i++) {
            res[i] = std::upper_bound(nums.begin(), nums.end(), queries[i])-nums.begin();;
        }
        return res;
    }
};