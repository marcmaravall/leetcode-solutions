class Solution {
public:
    int digits(int x) {
        int res = 1;
        for (x; x; x/=10)
            res++;
        return res;
    }

    int findNumbers(vector<int>& nums) {
        int res = 0;
        for (int x : nums)
            res += digits(x)%2;
        return res;
    }
};