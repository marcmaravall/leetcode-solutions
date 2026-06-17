class Solution {
public:
    vector<int> concatWithReverse(vector<int>& nums) {
        std::vector<int> res;
        res.insert(res.end(), nums.begin(), nums.end());
        res.insert(res.end(), nums.rbegin(), nums.rend());
        return res;
    }
};