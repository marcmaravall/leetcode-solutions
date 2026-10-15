class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int res = 0;
        const int n = nums.size();
        for (int i = 0; i < n; i++) {
            std::array<int, 101> freq {};
            int distinct = 0;
            for (int j = i; j < n; j++) {
                if (freq[nums[j]]++ == 0)
                    distinct++;
                res += distinct*distinct;
            }
        }
        return res;
    }
};