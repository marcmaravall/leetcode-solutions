class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int res = 0;
        for (int x : nums)
            res += (int)std::log10(x) % 2 == 1;
        return res;
    }
};