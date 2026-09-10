class Solution {
public:
    bool distinct(const std::array<int, 101>& freq) {
        for (int f : freq)
            if (f > 1)
                return false;
        return true;
    }

    int minimumOperations(vector<int>& nums) {
        std::array<int, 101> freq = {0};
        for (int x : nums)
            freq[x]++;
        const int n = nums.size();
        int index = 0;
        int res = 0;
        for (res; !distinct(freq); res++) {
            for (int i = index; i < std::min(n-1, index+3); i++)
                freq[nums[i]]--;
            index += 3;
        }
        return res;
    }
};