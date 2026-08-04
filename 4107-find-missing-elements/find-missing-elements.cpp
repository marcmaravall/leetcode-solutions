class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        std::vector<int> res {};
        std::sort(nums.begin(), nums.end());
        int expected = nums[0];

        for (int i = 0; i < nums.size(); i++) {
            while (expected < nums[i]) {
                res.push_back(expected);
                expected++;
            }

            expected++;
        }

        return res;
    }
};