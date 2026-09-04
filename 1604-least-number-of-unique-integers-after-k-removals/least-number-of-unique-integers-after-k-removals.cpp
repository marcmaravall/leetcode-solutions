class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        std::unordered_map<int, int> freq;
        int unique = 0;
        for (int x : arr) {
            if (freq[x]++ == 0)
                unique++;
        }
        int res = unique;
        std::vector<int> freqs;
        for (auto [a, b] : freq)
            freqs.push_back(b);
        std::sort(freqs.begin(), freqs.end());
        for (int f : freqs) {
            k -= f;
            if (k < 0)
                break;
            res--;
        }
        return res;
    }
};