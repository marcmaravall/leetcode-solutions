class Solution {
public:
    vector<string> createGrid(int m, int n) {
        std::vector<std::string> res(m, std::string(n, '#'));

        for(int i = 0; i < n; i++) {
            res[0][i] = '.';
        }

        for(int j=0;j<m;j++){
            res[j][n-1] = '.';
        }

        return res;
    }
};