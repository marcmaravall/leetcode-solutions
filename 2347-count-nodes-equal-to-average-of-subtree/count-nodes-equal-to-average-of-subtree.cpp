/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int res = 0;

    void count(TreeNode* root, int& elements, int& sum) {
        if (!root)
            return;
        
        int leftN = 0;
        int left = 0;
        count(root->left, leftN, left);
        int rightN = 0;
        int right = 0;
        count(root->right, rightN, right);
        elements++;
        elements += leftN + rightN;
        sum += root->val + right + left;
        if (sum / elements == root->val) {
            res++;
        }
        // std::cout << "sum: " << sum << " n: " << elements << "\n";
    }

    int averageOfSubtree(TreeNode* root) {
        int n = 0;
        int s = 0;
        count(root, n, s);
        return res;
    }
};