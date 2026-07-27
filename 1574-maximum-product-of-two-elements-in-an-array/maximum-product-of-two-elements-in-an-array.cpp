class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = 0;
        const int n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                res = std::max(res, (nums[i]-1) * (nums[j]-1));
            }
        }
        return res;
    }
};