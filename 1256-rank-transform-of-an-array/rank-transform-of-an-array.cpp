class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        std::vector<int> res = arr;
        std::sort(arr.begin(), arr.end());
        arr.erase(std::unique(arr.begin(), arr.end()), arr.end());
        const int n = res.size();
        for (int i = 0; i < n; i++) {
            res[i] = std::lower_bound(arr.begin(), arr.end(), res[i]) - arr.begin() + 1;
        }
        return res;
    }
};