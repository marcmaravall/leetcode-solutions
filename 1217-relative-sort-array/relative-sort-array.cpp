class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        std::vector<int> freq(1001, 0);
        for (int x : arr1)
            freq[x]++;
        
        std::vector<int> res;
        for (int x : arr2) {
            std::vector<int> v(freq[x], x);
            res.insert(res.end(), v.begin(), v.end());
            freq[x] = 0;
        }

        std::vector<int> end;
        for (int x : arr1) {
            if (freq[x] != 0) {
                end.push_back(x);
            }
        }
        std::sort(end.begin(), end.end());
        res.insert(res.end(), end.begin(), end.end());

        return res;
    }
};