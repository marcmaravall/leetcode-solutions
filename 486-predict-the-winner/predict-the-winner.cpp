class Solution {
public:
    // true if p1
    bool canWin(int p1, int p2, int left, int right, bool turn, std::vector<int>& nums) {
        if (right < left)
            return p1 >= p2;
        if (turn) {
            return canWin(p1+nums[left], p2, left+1, right, false, nums) || 
                   canWin(p1+nums[right], p2, left, right-1, false, nums);
        } else {
            return canWin(p1, p2+nums[left], left+1, right, true, nums) &&
                   canWin(p1, p2+nums[right], left, right-1, true, nums);
        }
    }

    bool predictTheWinner(vector<int>& nums) {
        return canWin(0, 0, 0, nums.size()-1, true, nums);
    }
};