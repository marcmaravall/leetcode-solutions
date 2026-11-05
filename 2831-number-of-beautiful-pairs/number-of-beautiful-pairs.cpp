class Solution {
public:
    int countBeautifulPairs(vector<int>& nums) {
        int res = 0;
        const int n = nums.size();
        auto first = [](int x) {
            int out = 0;
            while (x) {
                out = x%10;
                x /= 10;
            }
            return out;
        };
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                int a = nums[i], b = nums[j];
                res += (std::gcd(first(a), b%10) == 1);
            }
        }
        return res;
    }
};