class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        while (k--) {
            auto min = std::min_element(nums.begin(), nums.end());
            *min *= multiplier;
        }
        return nums;
    }
};