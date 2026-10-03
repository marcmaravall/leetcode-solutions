class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        const int n = nums.size();
        std::unordered_map<int, int> freq;
        int distinct = 0;
        for (int x : nums) {
            if (freq[x]++ == 0)
                distinct++;
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            std::unordered_map<int, int> subfreq;
            int curr = 0;
            for (int j = i; j < n; j++) {
                if (subfreq[nums[j]]++ == 0)
                    curr++;
                if (curr == distinct)
                    res++;
            }
        }
        return res;
    }
};