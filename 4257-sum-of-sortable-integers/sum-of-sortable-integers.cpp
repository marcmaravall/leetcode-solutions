class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        const int n = nums.size();
        int res = 0;
        std::vector<bool> has(std::sqrt(n)+1);
        auto check = [&](int k) -> bool {
            int last = INT_MIN;
            for (int i = 0; i < n; i += k) {
                int count = 0;
                int mn = nums[i], mx = nums[i];
                for (int j = 0; j < k; j++) {
                    int cur = i + j;
                    int nxt = i + (j+1) % k;
                    if (nums[cur] > nums[nxt]) {
                        if (++count > 1) {
                            return false;
                        }
                        mx = nums[cur];
                        mn = nums[nxt];
                    }
                }
                if (last > mn) {
                    return false;
                }
                last = mx;
            }
            return true;
        };
        for (int i = 1; i*i <= n; i++) {
            if (n % i != 0) {
                continue;
            }
            if (check(i)) {
                res += i;
            }
            int other = n/i;
            if (other != i && check(other)) {
                res += other;
            }
        }
        return res;
    }
};