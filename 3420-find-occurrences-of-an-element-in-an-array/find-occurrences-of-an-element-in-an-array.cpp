class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        const int n = nums.size();
        std::vector<int> occurrences;
        for (int i = 0; i < n; i++) {
            if (nums[i] == x)
                occurrences.push_back(i);
        }
        const int m = queries.size();
        std::vector<int> res(m);
        for (int i = 0; i < m; i++) {
            if (queries[i] > occurrences.size())
                res[i] = -1;
            else res[i] = occurrences[queries[i]-1];
        }
        return res;
    }
};