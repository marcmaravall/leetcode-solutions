class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int mx = *std::max_element(nums.begin(), nums.end());
        int u = 1;
        while (u <= mx)
            u *= 2;
        const int n = nums.size();
        std::vector<bool> s(u);
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                s[nums[i]^nums[j]] = true;
            }
        }
        std::vector<bool> t(u);
        for (int i = 0; i < u; i++) {
            if (!s[i])
                continue;
            for (int x : nums) {
                t[x^i] = true;
            }
        }
        
        int res = std::count(t.begin(), t.end(), true);
        return res;
    }
};