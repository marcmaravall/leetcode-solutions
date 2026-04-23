class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        std::vector<int> res(n, 0);
        std::vector<int> l_ps(n);
        l_ps[0] = nums[0];
        for (int i = 1; i < n; i++) {
            l_ps[i] = l_ps[i-1] + nums[i];

            int left = nums[i]*i - l_ps[i-1];

            res[i] += left;
        }

        std::vector<int> r_ps(n);
        r_ps[n-1] = nums[n-1];
        for (int i = n-2; i >= 0; i--) {
            r_ps[i] = r_ps[i+1] + nums[i];

            int right = r_ps[i+1] - (nums[i] * (n-i-1));

            res[i] += right;
        }


        return res;
    }
};