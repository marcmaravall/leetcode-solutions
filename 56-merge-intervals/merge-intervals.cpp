class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end());

        int n = intervals.size();
        std::vector<std::vector<int>> res;
        for (int i = 0; i < n; i++) {
            int start = intervals[i][0];
            if (i >= n-1) {
                res.push_back({start, intervals[i][1]});
                break;
            }

            int end = intervals[i][1];
            while (i < n-1 && end >= intervals[i+1][0]) {
                end = max(end, intervals[i+1][1]);
                i++;
            }

            res.push_back({start, end});
        }

        return res;
    }
};