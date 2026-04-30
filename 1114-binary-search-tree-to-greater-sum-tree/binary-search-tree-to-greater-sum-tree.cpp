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
    std::vector<int> arr {};

    void helper(TreeNode* root) {
        if (!root)
            return;
        arr.push_back(root->val);
        helper(root->left);
        helper(root->right);
    }

    void toGst(TreeNode* root) {
        if (!root)
            return;
        int c = 0;
        for (int n : arr) {
            if (n > root->val)
                c += n;
        }
        root->val += c;
        toGst(root->left);
        toGst(root->right);
    }

    TreeNode* bstToGst(TreeNode* root) {
        helper(root);
        toGst(root);
        return root;
    }
};