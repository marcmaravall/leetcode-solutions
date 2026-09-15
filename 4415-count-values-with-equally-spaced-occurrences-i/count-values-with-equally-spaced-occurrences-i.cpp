class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        std::array<std::vector<int>, 101> positions;
        const int n = nums.size();
        for (int i = 0; i < n; i++)
            positions[nums[i]].push_back(i);
        int res = 0;
        for (auto& p : positions) {
            if (p.size() != 3)
                continue;
            res += (p[1]-p[0] == p[2]-p[1]);
        }
        return res;
    }
};