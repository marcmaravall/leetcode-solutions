class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        std::vector<int> pos;
        const int n = nums.size();
        for (int x : nums) {
            if (x >= 0) {
                pos.push_back(x);
            }
        }
        if (pos.empty()) {
            return nums;
        }
        std::rotate(pos.begin(), pos.begin()+(k%pos.size()), pos.end());
        int index = 0;
        for (int& x : nums) {
            if (x >= 0) {
                x = pos[index++];
            }
        }
        return nums;
    }
};