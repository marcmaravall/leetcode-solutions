/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        std::vector<std::vector<int>> res(m, std::vector<int>(n, INT_MIN));
        int i = 0, j = 0;
        int iInc = 0, jInc = 1;
        for (int val = 1; val <= n*m; val++) {
            if (jInc == 1 && (j == n-1 || res[i][j+1] != INT_MIN)) {
                iInc = 1, jInc = 0;
            } else if (iInc == 1 && (i == m-1 || res[i+1][j] != INT_MIN)) {
                iInc = 0, jInc = -1;
            } else if (jInc == -1 && (j == 0 || res[i][j-1] != INT_MIN)) {
                iInc = -1, jInc = 0;
            } else if (iInc == -1 && (i == 0 || res[i-1][j] != INT_MIN)) {
                iInc = 0, jInc = 1;
            }
            if (head) {
                res[i][j] = head->val;
                head = head->next;
            } else {
                res[i][j] = -1;
            }
            i += iInc, j += jInc;
        }      
        return res;
    }
};