class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        const int n = nums.size();
        std::vector<int> res(n-k+1);
        for (int i = 0; i < n-k+1; i++) {
            int m = nums[i];
            for (int j = 1; j < k; j++) {
                if (nums[i+j-1]+1 != nums[i+j]) {
                    m = -1;
                    break;
                }
                m = nums[i+j];
            }
            res[i] = m;
        }
        return res;
    }
};