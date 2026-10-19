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
    void helper(int& res, TreeNode* node, int parent, int grandparent) {
        if (!node) {
            return;
        }
        if (grandparent % 2 == 0) {
            res += node->val;
        }
        helper(res, node->left, node->val, parent);
        helper(res, node->right, node->val, parent);
    }

    int sumEvenGrandparent(TreeNode* root) {
        int res = 0;
        helper(res, root, 1, 1);
        return res;    
    }
};