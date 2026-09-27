class Solution {
public:
    int reverse(int n) {
        std::string str = std::to_string(n);
        std::reverse(str.begin(), str.end());
        return std::stoi(str);
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