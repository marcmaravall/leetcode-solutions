class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int minIndex = 0;
        int maxIndex = 0;
        const int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] < nums[minIndex])
                minIndex = i;
            if (nums[i] > nums[maxIndex])
                maxIndex = i;
        }
        int greater = std::max(minIndex, maxIndex);
        int lower = std::min(minIndex, maxIndex);
        return std::min({
            greater + 1,
            n - lower,
            lower + 1 + n - greater
        });
    }
};