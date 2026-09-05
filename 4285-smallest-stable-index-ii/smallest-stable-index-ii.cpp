class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        const int n = nums.size();
        std::vector<int> minSuffix(n);
        std::vector<int> maxPrefix(n);
        maxPrefix[0] = nums[0];
        minSuffix[n-1] = nums[n-1];
        for (int i = 1; i < n; i++) {
            maxPrefix[i] = std::max(maxPrefix[i-1], nums[i]);
            minSuffix[n-i-1] = std::min(minSuffix[n-i], nums[n-i-1]);
        }
        for (int i = 0; i < n; i++) {
            int curr = maxPrefix[i]-minSuffix[i];
            if (curr <= k)
                return i;
        }
        return -1;
    }
};