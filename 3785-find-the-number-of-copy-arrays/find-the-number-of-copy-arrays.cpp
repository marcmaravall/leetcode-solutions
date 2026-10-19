class Solution {
public:
    int countArrays(vector<int>& original, vector<vector<int>>& bounds) {
        const int n = original.size();
        int left = bounds[0][0], right = bounds[0][1];
        for (int i = 1; i < n; i++) {
            const int diff = original[i]-original[i-1];
            const int u = bounds[i][0], v = bounds[i][1];
            left = std::max(left+diff, u);
            right = std::min(right+diff, v);
        }
        return std::max(right-left+1, 0);
    }
};