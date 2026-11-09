class Solution {
public:
    int minOperations(vector<int>& nums) {
        return std::equal(nums.begin()+1, nums.end(), nums.begin()) ? 0 : 1;
    }
};