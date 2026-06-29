class Solution {
public:
    vector<int> transformArray(vector<int>& nums) {
        for (int& n : nums) {
            n = n%2;
        }
        std::sort(nums.begin(), nums.end());
        return nums;
    }
};