class Solution {
public:
    int partitionString(string s) {
        std::vector<int> last(127, -1);
        int res = 1;

        const int n = s.size();
        for (int i = 0; i < n; i++) {
            if (last[s[i]] != -1) {
                res++;
                for (int& c : last)
                    c = -1;
            } 
            
            last[s[i]] = i;
        }

        return res;
    }
};