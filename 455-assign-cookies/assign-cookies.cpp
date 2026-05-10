class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        std::sort(g.begin(), g.end());
        std::sort(s.begin(), s.end());
    
        int res = 0;
        int j = 0;
        for (int i = 0; i < g.size() && j < s.size(); (void)0) {
            if (s[j] >= g[i]) {
                res++;
                i++;
            }
            j++;
        }

        return res;
    }
};