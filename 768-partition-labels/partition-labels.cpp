class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        std::vector<int> map(127, 0);
        for (int i = 0; i < n; i++) {
            map[s[i]] = i;
        }

        std::vector<int> res;
        int start = -1;
        int end = 0;

        for (int i = 0; i < n; i++) {
            end = max(end, map[s[i]]);
            if (end == i) {
                res.push_back(end-start);
                start = end;
            }
        }
        return res;
    }
};