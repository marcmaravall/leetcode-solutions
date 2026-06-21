class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        std::sort(costs.begin(), costs.end());
        int res = 0;

        for (int c : costs) {
            coins -= c;
            if (coins < 0)
                return res;
            res++;
        }

        return res;
    }
};