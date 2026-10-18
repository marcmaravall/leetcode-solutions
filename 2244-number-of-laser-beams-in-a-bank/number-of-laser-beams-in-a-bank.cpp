class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        const int n = bank.size(), m = bank[0].size();
        int res = 0, last = 0;
        for (int i = n-1; i >= 0; i--) {
            int count = 0;
            for (int j = 0; j < m; j++) {
                count += bank[i][j] == '1';
            }
            res += count*last;
            if (count != 0) {
                last = count;
            }
        }
        return res;
    }
};