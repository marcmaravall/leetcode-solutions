class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        std::map<int, int> freq;
        int unique = 0;
        for (int x : arr) {
            if (freq[x]++ == 0) {
                unique++;
            }
        }
        std::vector<std::pair<int, int>> sorted(freq.begin(), freq.end());
        std::sort(sorted.begin(), sorted.end(), [](auto& a, auto& b) { 
            return a.second < b.second;
        });
        int res = unique;
        for (auto [a, b] : sorted) {
            k -= b;
            if (k < 0)
                break;
            res--;
        }
        return res;
    }
};