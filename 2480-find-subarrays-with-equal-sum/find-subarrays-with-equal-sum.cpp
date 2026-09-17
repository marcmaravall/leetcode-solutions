class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        const int n = nums.size();
        std::unordered_map<int, bool> contains;
        for (int i = 0; i < n-1; i++) {
            int sum = nums[i]+nums[i+1];
            if (contains[sum])
                return true;
            contains[sum] = true;
        }
        return false;
    }
};