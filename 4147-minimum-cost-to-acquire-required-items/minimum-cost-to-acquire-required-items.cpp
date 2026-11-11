class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        if (costBoth >= cost1+cost2) {
            return cost1*static_cast<long long>(need1) + cost2*static_cast<long long>(need2);
        }
        int minNeed = std::min(need1, need2);
        long long res = 0;
        res += minNeed*static_cast<long long>(costBoth);
        if (need1 > need2) {
            res += std::min(cost1, costBoth)*static_cast<long long>(need1-need2);
        } else {
            res += std::min(cost2, costBoth)*static_cast<long long>(need2-need1);
        }
        return res;
    }
};