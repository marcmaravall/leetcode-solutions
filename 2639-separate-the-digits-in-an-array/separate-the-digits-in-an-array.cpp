class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        std::vector<int> res;
        for (int n : nums) {
            std::string str = std::to_string(n);
            for (char c : str)
                res.push_back(c-'0');
        }

        return res;
    }
};