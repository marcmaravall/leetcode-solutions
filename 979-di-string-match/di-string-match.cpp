class Solution {
public:
    vector<int> diStringMatch(string s) {
        std::vector<int> res {};
        int i = 0;
        int j = s.size();

        for (char c : s) {
            if (c == 'I') {
                res.push_back(i);
                i++;
            } else {
                res.push_back(j);
                j--;
            }
        }
        
        res.push_back(j);
        return res;
    }
};