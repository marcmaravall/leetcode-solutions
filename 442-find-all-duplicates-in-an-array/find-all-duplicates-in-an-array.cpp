class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        std::vector<int> res;
        for (int n : nums) {
            int index = abs(n)-1;
            if (nums[index] < 0) {
                res.push_back(abs(n));
            } else {
                nums[index] *= -1;
            }
        }
        return res;
    }
};