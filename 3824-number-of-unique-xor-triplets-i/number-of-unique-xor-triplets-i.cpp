class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        const int n = nums.size();
        if (n == 1)
            return 1;
        else if (n == 2)
            return 2;
        int res = 0;
        for (int i = 0; i < 32; i++) {
            if (n & (1 << i))
                res = i+1;
        }
        res = std::pow(2, res);
        return res;
    }
};