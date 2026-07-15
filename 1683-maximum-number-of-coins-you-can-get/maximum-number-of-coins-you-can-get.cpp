class Solution {
public:
    int maxCoins(vector<int>& piles) {
        std::sort(piles.begin(), piles.end(), std::greater<int>());
        const int n = piles.size();
        for (int i = 0; i < n; i+=2) 
            piles[i] = 0;
        for (int i = 0; i < n/3; i++)
            piles[n-i-1] = 0;
        return std::accumulate(piles.begin(), piles.end(), 0);
    }
};