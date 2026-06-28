class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int res = 1;
        std::sort(arr.begin(), arr.end());
        const int n = arr.size();
        arr[0] = 1;
        for (int i = 1; i < n; i++) {
            if (arr[i]-arr[i-1] > 1) {
                arr[i] = arr[i-1]+1;
            }
            res = max(res, arr[i]);
        }

        return res;
    }
};