class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        const int n = groupSizes.size();
        std::vector<std::vector<int>> res;
        for (int i = 0; i < n; i++) {
            const int current = groupSizes[i];
            std::vector<int> arr {};
            for (int j = i; arr.size() < current && j < n; j++) {
                if (groupSizes[j] == current) {
                    arr.push_back(j);
                    groupSizes[j] = -1;
                }
            }
            if (arr.size() == current)
                res.push_back(arr);
        }
        return res;
    }
};