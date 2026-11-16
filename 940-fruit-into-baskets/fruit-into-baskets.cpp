class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int left = 0, right = 0;
        const int n = fruits.size();
        std::unordered_map<int, int> freq;
        int different = 0;
        int res = 0;
        while (right < n) {
            if (right == left) {
                different += ++freq[fruits[right++]] == 1;
            } else if (different > 2) {
                different -= --freq[fruits[left++]] == 0;
            } else {
                different += ++freq[fruits[right++]] == 1;
            }
            if (different <= 2) {
                res = std::max(res, right-left);
            }
        }
        return res;
    }
};