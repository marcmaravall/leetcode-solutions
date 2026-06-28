class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        std::sort(arr.begin(), arr.end());
        arr[0] = 1;
        
        int res = 1;
        const int n = arr.size();
        for (int i = 1; i < n; i++) {
            if (arr[i]-arr[i-1] > 1) 
                arr[i] = arr[i-1]+1;

            res = max(res, arr[i]);
        }

        return res;
    }
};