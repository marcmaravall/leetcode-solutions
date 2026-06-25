class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        int res = 0;
        for (int n : nums) {
            for (int i = n; i > 0; i/=10) {
                if (i % 10 == digit) 
                    res++;
            }
        }

        return res;
    }
};