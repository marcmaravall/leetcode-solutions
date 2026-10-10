class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        const int n = nums1.size();
        std::vector<int> diff(n);
        for (int i = 0; i < n; i++) {
            diff[i] = std::abs(nums1[i]-nums2[i]);
        }
        std::sort(diff.rbegin(), diff.rend());
        long long k = (long long)k1 + k2;
        diff.push_back(0);
        bool stopped = false;
        for (int i = 0; i < n; i++) {
            long long cost = (long long)(i + 1) * (diff[i] - diff[i + 1]);
            if (k >= cost) {
                k -= cost;
                continue;
            }
            long long q = k / (i + 1);
            long long r = k % (i + 1);
            long long level = diff[i] - q;
            for (int j = 0; j <= i; j++) {
                diff[j] = level - (j < r ? 1 : 0);
            }
            stopped = true;
            break;
        }
        if (!stopped)
            return 0;
        long long res = 0;
        for (int i = 0; i < n; i++) {
            res += (long long)diff[i] * diff[i];
        }
        return res;
    }
};