class Solution {
public:
    int maxProfit(vector<int>& prices) {
        const int n = prices.size();
        int res = 0;
        for (int i = 0; i < n-1; i++) {
            if (i < n-1 && prices[i] > prices[i+1])
                continue;
            int price = prices[i];
            while (i < n-1 && prices[i] <= prices[i+1])
                i++;
            if (i == n)
                break;
            res += prices[i]-price;
        }
        return res;
    }
};