class Solution {
public:
    vector<string> generateValidStrings(int n, int k) {
        std::vector<std::string> res;
        std::function<void(std::string&, int)> backtracking = [&](std::string& str, int cost) {
            if (str.size() == n && cost <= k) {
                res.push_back(str);
            } else if (str.size() > n || cost > k)
                return;

            str += '0';
            backtracking(str, cost);
            str.pop_back();

            if (str.back() == '0') {
                str += '1';
                backtracking(str, cost + str.size()-1);
                str.pop_back();
            }
        };

        std::string s = "1";
        backtracking(s, 0);
        s = "0";
        backtracking(s, 0);

        return res;
    }
};