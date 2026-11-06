class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        int freq[201] = {};
        for (int x : nums) {
            freq[x+100]++;
        }
        std::sort(nums.begin(), nums.end(), [&](int a, int b) {
            if (freq[a+100] == freq[b+100]) {
                return a > b;
            }
            return freq[a+100] < freq[b+100];
        });
        return nums;
    }
};