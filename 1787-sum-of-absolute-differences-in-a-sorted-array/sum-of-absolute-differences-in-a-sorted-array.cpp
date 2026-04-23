class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        std::vector<int> l_ps(n);
        l_ps[0] = nums[0];
        for (int i = 1; i < n; i++) {
            l_ps[i] = l_ps[i-1] + nums[i];
        }

        std::vector<int> r_ps(n);
        r_ps[n-1] = nums[n-1];
        for (int i = n-2; i >= 0; i--) {
            r_ps[i] = r_ps[i+1] + nums[i];
        }

        std::vector<int> res(n);

        for (int i = 0; i < n; i++) {
            int left = (i > 0) ? nums[i]*i - l_ps[i-1] : 0;
            int right = (i < n-1) ? r_ps[i+1] - nums[i]*(n-1-i) : 0;

            res[i] = left + right;
        }

        return res;
    }
};