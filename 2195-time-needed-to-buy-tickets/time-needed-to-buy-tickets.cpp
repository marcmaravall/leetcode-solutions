class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int res = 0;
        const int n = tickets.size();
        for (int i = 0; i < n; i++)
            res += std::min(tickets[k]-(i>k), tickets[i]);
        return res;
    }
};