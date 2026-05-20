class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        std::vector<int> C(n, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                for (int k = 0; k <= i; k++) {
                    if (A[j] == B[k]) 
                        C[i]++;
                }
            }
        }
        return C;
    }
};