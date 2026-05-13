class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        std::unordered_map<int, int> map;
        std::vector<int> res;
        for (int n : nums) {
            int i = abs(n) - 1;
            if (nums[i] < 0) {
                res.push_back(abs(n));
            } else {
                nums[i] = -nums[i];
            }
        }
        return res;
    }
};