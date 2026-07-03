class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        std::unordered_map<int, int> freq;
        for (int n : arr) {
            int r = ((n % k) + k) % k;
            freq[r]++;
        }

        if (freq[0] % 2 != 0)
            return false;
        if (k % 2 == 0 && freq[k / 2] % 2 != 0)
            return false;

        for (int i = 1; i < (k + 1) / 2; i++) {
            if (freq[i] != freq[k - i])
                return false;
        }

        return true;
    }
};