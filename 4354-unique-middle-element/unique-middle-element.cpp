class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        std::vector<int> freq(101, 0);
        const int n = nums.size();
        int mid = nums[n/2];
        for (int i = 0; i < n; i++) {
            freq[nums[i]]++;
            if (freq[mid] > 1)
                return false;
        }
        return true;
    }
};