class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        std::vector<int> arr;
        for (auto& vec : matrix) {
            arr.insert(arr.end(), vec.begin(), vec.end());
        }
        std::sort(arr.begin(), arr.end());
        return arr[k-1];
    }
};