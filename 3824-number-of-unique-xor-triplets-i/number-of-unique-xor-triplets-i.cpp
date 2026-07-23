class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        const int n = nums.size();
        if (n == 1)
            return 1;
        else if (n == 2)
            return 2;
        int p = 0;
        for (int i = 0; i < 32; i++) {
            if (n & (1 << i))
                p = i+1;
        }
        return std::pow(2, p);
    }
};