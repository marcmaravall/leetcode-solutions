class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        std::unordered_map<int, int> freq;
        int res = 0;
        for (int x : nums) {
            res += freq[x-k]+freq[x+k];
            freq[x]++;
        }
        return res;
    }
};