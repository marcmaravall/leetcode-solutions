class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        const int n = seq.size();
        std::vector<int> res(n);
        int a = 0, b = 0;
        for (int i = 0; i < n; i++) {
            res[i] = seq[i] == '(' ? a > b : a <= b;
            if (seq[i] == '(') {
                if (a > b) {
                    b++;
                } else {
                    a++;
                }
            }
            else if (a > b) {
                a--;
            } else {
                b--;
            }
        }
        return res;
    }
};