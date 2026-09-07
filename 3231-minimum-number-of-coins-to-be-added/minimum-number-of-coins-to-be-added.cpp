class Solution {
public:
    int minimumAddedCoins(vector<int>& coins, int target) {
        const int n = coins.size();
        std::sort(coins.begin(), coins.end());
        int max = 0;
        int res = 0;
        int index = 0;
        while (max < target) {
            if (index < n && coins[index] <= max+1)
                max += coins[index++];
            else {
                max += max++;
                res++;
            }
        }
        return res;
    }
};