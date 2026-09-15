class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        std::unordered_map<int, std::vector<int>> positions;
        const int n = nums.size();
        for (int i = 0; i < n; i++)
            positions[nums[i]].push_back(i);
        int res = 0;
        for (auto& [_, p] : positions) {
            const int size = p.size();
            if (size < 3)
                continue;
            int last = p[0];
            int eq = true;
            for (int i = 2; i < size; i++) {
                if (p[i]-p[i-1] != p[i-1]-last) {
                    eq = false;
                    break;
                }
                last = p[i-1];
            }
            res += eq;
        }
        return res;
    }
};