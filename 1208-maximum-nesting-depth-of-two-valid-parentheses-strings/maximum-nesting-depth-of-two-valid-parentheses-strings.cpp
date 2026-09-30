class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        const int n = seq.size();
        std::vector<int> res(n);
        int a = 0, b = 0;
        for (int i = 0; i < n; i++) {
            if (seq[i] == '(') {
                if (a > b) {
                    b++;
                    res[i] = 0;
                } else {
                    a++;
                    res[i] = 1;
                }
                continue;
            }
            if (a > b) {
                a--;
                res[i] = 1;
            } else {
                b--;
                res[i] = 0;
            }
        }
        return res;
    }
};