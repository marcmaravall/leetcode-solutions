class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        std::vector<int> res;
        for (int n : nums) {
            std::vector<int>a;
            while (n > 9) {
                int d = n%10;
                a.push_back(d);
                n/=10;
            }
            a.push_back(n);
            std::reverse(a.begin(), a.end());
            res.insert(res.end(), a.begin(), a.end());
        }
        
        return res;
    }
};