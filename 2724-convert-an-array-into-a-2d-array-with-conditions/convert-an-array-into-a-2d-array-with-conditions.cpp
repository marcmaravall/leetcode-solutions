class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        const int n = nums.size();
        std::vector<int> freq(n+1);
        int maxFreq = 0;
        for (int x : nums)
            maxFreq = std::max(maxFreq, ++freq[x]);
        std::vector<std::vector<int>> res(maxFreq, std::vector<int>());
        for (int i = 0; i < maxFreq; i++) {
            for (int j = 1; j <= n; j++) {
                if (freq[j]-- > 0)
                    res[i].push_back(j);
            }
        }
        return res;
    }
};