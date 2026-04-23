// this is not O(1) in memory btw

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        std::unordered_map<int, int> freq(n);
        for (int n : nums) {
            freq[n]++;
        }

        for (int i = 1; i < INT_MAX; i++) {
            if (freq[i] == 0)
                return i;
        }
        return 0;
    }
};