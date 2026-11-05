class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int res = 0;
        const int n = arr1.size(), m = arr2.size();
        for (int i = 0; i < n; i++) {
            bool b = true;
            for (int j = 0; j < m; j++) {
                if (std::abs(arr1[i]-arr2[j]) <= d) {
                    b = false;
                    break;
                }
            }
            res += b;
        }
        return res;
    }
};