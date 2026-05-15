class Solution {
public:
    int findMin(vector<int>& nums) {
        int res = INT_MAX;
        for (int n : nums)
            res = min(res, n);
        return res;
    }
};