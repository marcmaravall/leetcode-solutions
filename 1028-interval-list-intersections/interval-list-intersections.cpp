class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int i = 0, j = 0;
        const int n = firstList.size();
        const int m = secondList.size();
        std::vector<std::vector<int>> res;
        while (i < n && j < m) {
            int aStart = firstList[i][0];
            int aEnd = firstList[i][1];
            int bStart = secondList[j][0];
            int bEnd = secondList[j][1];
            if (aStart <= bEnd && bStart <= aEnd) {
                res.push_back({std::max(aStart, bStart), std::min(aEnd, bEnd)});
            }
            if (aEnd <= bEnd)
                i++;
            else j++;
        }
        return res;
    }
};