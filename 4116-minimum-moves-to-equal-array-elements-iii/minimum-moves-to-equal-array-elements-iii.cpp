class Solution {
public:
    int minMoves(vector<int>& nums) {
        int max = 0;
        int sum = 0;
        for (int x : nums) {
            max = std::max(max, x);
            sum += x;
        }
        return -(sum-(int)nums.size()*max);
    }
};