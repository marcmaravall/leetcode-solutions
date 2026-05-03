class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end(), [](std::vector<int>& a, std::vector<int>& b) {
            return a[0] < b[0];
        });

        int n = intervals.size();
        std::vector<std::vector<int>> res;
        for (int i = 0; i < n; i++) {
            int start = intervals[i][0];
            if (i >= n-1) {
                res.push_back({start, intervals[i][1]});
                break;
            }

            int j = i;
            int end = intervals[i][1];
            bool merged = false;
            while (i < n-1 && end >= intervals[i+1][0]) {
                end = max(end, intervals[i+1][1]);
                i++;
                merged = true;
            }

            res.push_back({start, merged ? end : intervals[j][1]});
        }

        return res;
    }
};