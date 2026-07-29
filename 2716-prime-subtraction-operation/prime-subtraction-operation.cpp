class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        std::vector<bool> sieve(1001, true);
        sieve[1] = false;
        for (int i = 2; i <= std::sqrt(1001); i++) {
            if (sieve[i]) {
                for (int j = i*i; j <= 1001; j+=i)
                    sieve[j] = false;
            }
        }

        int curr = 1;
        const int n = nums.size();
        for (int i = 0; i < n; i) {
            int diff = nums[i]-curr;
            if (diff < 0)
                return false;
            if (sieve[diff] || diff == 0)
                i++;
            curr++;
        }
        return true;
    }
};