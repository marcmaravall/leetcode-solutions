class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int res = 0;
        for (const auto& op : operations) {
            res += (op[1] == '+') ? 1 : -1;
        }
        return res;
    }
};