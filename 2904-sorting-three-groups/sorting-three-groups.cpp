class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        const int n = nums.size();
        int res = n;
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                int cur = 0;
                for (int k = 0; k < n; k++) {
                    if (k < i) {
                        cur += nums[k] != 1;
                    } else if (k < j) {
                        cur += nums[k] != 2;
                    } else {
                        cur += nums[k] != 3;
                    }
                }
                res = std::min(res, cur);
            }
        }
        return res;
    }
};