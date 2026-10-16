class Solution {
public:
    int minOperations(vector<int>& nums) {
        std::unordered_map<int, int> freq;
        for (int x : nums) {
            freq[x]++;
        }
        int res = 0;
        for (auto [val, f] : freq) {
            if (f == 1)
                return -1;
            int mod3 = f % 3;
            if (mod3 == 0)
                res += f/3;
            else
                res += f/3+1;
        }
        return res;
    }
};