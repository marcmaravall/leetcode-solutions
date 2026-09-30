class Solution {
public:
    double calculateTax(vector<vector<int>>& brackets, int income) {
        double res = 0;
        int prev = 0;
        const int n = brackets.size();
        for(int i = 0; i < n; i++) {
            int curr = std::min(brackets[i][0], income);
            res += (curr-prev)*brackets[i][1]/100.0;
            if(brackets[i][0] >= income) 
                break;
            prev = brackets[i][0];
        }
        return res;
    }
};