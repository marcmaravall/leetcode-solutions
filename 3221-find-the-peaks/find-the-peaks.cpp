class Solution {
public:
    vector<int> findPeaks(vector<int>& mountain) {
        std::vector<int> res;
        const int n = mountain.size();
        for (int i = 1; i < n-1; i++) {
            if (mountain[i-1] < mountain[i] && mountain[i] > mountain[i+1]) {
                res.push_back(i);
            }
        }
        return res;
    }
};