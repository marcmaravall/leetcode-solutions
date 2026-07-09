class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        std::vector<int> groups(n);
        int g = 0;
        for (int i = 0; i < n; i++) {
            groups[i] = g;
            if (i < n-1 && nums[i+1]-nums[i] > maxDiff)
                g++;
        }

        const int m = queries.size();
        std::vector<bool> res(m);
        for (int i = 0; i < m; i++) {
            res[i] = groups[queries[i][0]] == groups[queries[i][1]];
        }
        return res;
    }
};