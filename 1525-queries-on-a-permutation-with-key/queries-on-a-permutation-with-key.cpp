class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        std::vector<int> perm(m);
        for (int i = 1; i <= m; i++) {
            perm[i-1] = i;
        }
        int n = queries.size();
        std::vector<int> res(n);
        for (int i = 0; i < n; i++) {
            int j = 0;
            for (j; j < m; j++) {
                if (queries[i] == perm[j]) {
                    break;
                }
            }
            std::rotate(perm.begin(), perm.begin()+j, perm.begin()+j+1);
            res[i] = j;
        }
        return res;
    }
};