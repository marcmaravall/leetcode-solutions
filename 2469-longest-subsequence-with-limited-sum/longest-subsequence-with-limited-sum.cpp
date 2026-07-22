class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        const int n = nums.size();
        const int m = queries.size();
        std::sort(nums.begin(), nums.end());
        std::vector<int> res(m);
        for (int j = 0; j < m; j++) {
            int sum = 0;
            int i;
            for (i = 0; i < n; i++) {
                if (sum+nums[i] > queries[j])
                    break;
                sum += nums[i];
            }
            res[j] = i;
        }
        return res;
    }
};