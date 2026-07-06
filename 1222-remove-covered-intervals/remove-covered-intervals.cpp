class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        std::ranges::sort(intervals, {}, [](auto& x) {
            return std::pair(x[0], -x[1]);
        });

        int res = 0, r = 0;
        for (auto& x : intervals) {
            if (x[1] > r)
                res++;
            r = std::max(r, x[1]);
        }
        return res;
    }
};