class Solution {
public:
    int reverse(int x) {
        int out=0;
        while(x) {
            if(out > INT_MAX/10 || out < INT_MIN/10)
                return 0;
            out = out*10 + x%10;
            x /= 10;
        }
        return out;
    }


    int countDistinctIntegers(vector<int>& nums) {
        int res = 0;
        std::unordered_map<int, int> freq;
        for (int n : nums) {
            if (freq[n]++ == 0)
                res++;
            if (freq[reverse(n)]++ == 0)
                res++;
        }
        return res;
    }
};