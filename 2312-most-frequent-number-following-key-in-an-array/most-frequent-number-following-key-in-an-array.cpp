class Solution {
public:
    int mostFrequent(vector<int>& nums, int key) {
        const int n = nums.size();
        int freq[1001] = {};
        int maxFreq = 0;
        int res = 0;
        for (int i = 0; i < n-1; i++) {
            if (nums[i] == key) {
                int target = nums[i+1];
                if (maxFreq < ++freq[target]) {
                    maxFreq = freq[target];
                    res = target;
                }
            }
        }
        return res;
    }
};