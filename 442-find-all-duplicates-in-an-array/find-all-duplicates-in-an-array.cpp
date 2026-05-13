class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        std::unordered_map<int, int> map;
        std::vector<int> res;
        for (int n : nums) {
            map[n]++;
            if (map[n] == 2)
                res.push_back(n);
        }
        return res;
    }
};