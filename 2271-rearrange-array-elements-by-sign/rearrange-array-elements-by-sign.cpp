class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        const int n = nums.size();
        std::vector<int> sign(n);
        int left = 0, right = n/2;
        for (int i = 0; i < n; i++) {
            if (nums[i] < 0)
                sign[left++] = nums[i];
            else
                sign[right++] = nums[i];
        }
        std::vector<int> res(n);
        for (int i = 0; i < n; i+=2) {
            res[i] = sign[i/2+n/2];
            res[i+1] = sign[i/2];
        }
        return res;
    }
};