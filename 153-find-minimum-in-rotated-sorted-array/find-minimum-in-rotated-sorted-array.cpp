class Solution {
public:
    int findMin(vector<int>& nums) {
        int res = INT_MAX;
        std::for_each(nums.begin(), nums.end(), [&](int n) {
            res = min(n, res);
        });
        return res;
    }
};