class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        std::sort(nums.begin(), nums.end());
        int res = 0;
        int last = INT_MIN;
        for (int x : nums) {
            int curr = std::max(last+1, x-k);
            if (curr <= x+k) {
                last = curr;
                res++;
            }
        }
        return res;
    }
};
