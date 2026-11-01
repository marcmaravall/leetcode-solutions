class Solution {
public:
    int minMoves(vector<int>& nums) {
        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        int min = *std::min_element(nums.begin(), nums.end());
        return sum-min*nums.size();
    }
};