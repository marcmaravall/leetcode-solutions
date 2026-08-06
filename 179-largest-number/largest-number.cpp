class Solution {
public:
    string largestNumber(vector<int>& nums) {
        const int n = nums.size();
        std::vector<std::string> str(n);
        for (int i = 0; i < n; i++)
            str[i] = std::to_string(nums[i]);
        std::sort(str.begin(), str.end(), [](auto& a, auto& b) {
            return a+b > b+a;
        });
        std::string res = "";
        bool allzero = true;
        for (auto& s : str) {
            if (s.size() > 1 || s[0] != '0')
                allzero = false;
            res += s;
        }
        if (allzero)
            return "0";
        return res;
    }
};