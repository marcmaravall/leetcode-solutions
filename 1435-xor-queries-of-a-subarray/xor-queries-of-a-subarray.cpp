class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        const int n = arr.size();
        std::vector<int> prefix(n), suffix(n);
        prefix[0] = arr[0];
        for (int i = 1; i < n; i++) {
            prefix[i] = arr[i] ^ prefix[i-1];
        }
        suffix[n-1] = arr[n-1];
        for (int i = n-2; i >= 0; i--) {
            suffix[i] = arr[i] ^ suffix[i+1];
        }
        const int qSize = queries.size();
        std::vector<int> res(qSize);
        const int total = prefix[n-1];
        for (int i = 0; i < qSize; i++) {
            const int left = queries[i][0], right = queries[i][1];
            res[i] = total ^ prefix[right] ^ suffix[left];
        }
        return res;
    }
};