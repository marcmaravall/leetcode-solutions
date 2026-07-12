class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        int zeros1 = 0;
        long long sum1 = 0;
        for (int n : nums1) {
            if (n == 0) {
                zeros1++;
                sum1++;
            } else
                sum1 += n;
        }
        int zeros2 = 0;
        long long sum2 = 0;
        for (int n : nums2) {
            if (n == 0) {
                zeros2++;
                sum2++;
            } else
                sum2 += n;
        }

        if (zeros1 == 0 && sum1 < sum2)
            return -1;
        else if (zeros2 == 0 && sum2 < sum1)
            return -1;

        return std::max(sum1, sum2);
    }
};