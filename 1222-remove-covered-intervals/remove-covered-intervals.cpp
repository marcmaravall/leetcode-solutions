class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        std::ranges::sort(intervals, {}, [](auto& x) {
            return pair{x[0], -x[1]};
        });
        
        int res = 0, r = 0;
        for (auto& interval : intervals) {
            if (interval[1] > r)
                res++;
            r = std::max(r, interval[1]);
        }
        return res;
    }
};