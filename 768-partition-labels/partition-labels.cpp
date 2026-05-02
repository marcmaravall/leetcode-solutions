class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        std::vector<int> lastIndex(127, 0);

        for (int i = 0; i < n; i++) {
            lastIndex[s[i]] = i;
        }

        std::vector<int> res = {};
        int start = -1;
        int end = 0;
        for (int i = 0; i < n; i++) {
            char c = s[i];
            end = max(end, lastIndex[c]);
            if (end == i) {
                res.push_back(end-start);
                start = end;
            }
        }

        return res;
    }
};