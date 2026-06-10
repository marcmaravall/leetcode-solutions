class Solution {
public:
    vector<int> diStringMatch(string s) {
        std::vector<int> res;
        int left = 0;
        int right = s.size();
        
        for (char c : s) {
            if (c == 'I') {
                res.push_back(left);
                left++;
            } else {
                res.push_back(right);
                right--;
            }
        }

        res.push_back(right);

        return res;
    }
};