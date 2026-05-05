class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        std::vector<int> res;
        int n = order.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < friends.size(); j++) {
                if (friends[j] == order[i]) {
                    res.push_back(order[i]);
                }
            }
        }
        return res;
    }
};