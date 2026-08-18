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
    void dfs(TreeNode* root, int target, bool& remove) {
        if (!root)
            return;

        TreeNode* left = root->left;
        TreeNode* right = root->right;
        if (left && left->val == target && !left->left && !left->right) {
            root->left = nullptr;
            remove = true;
        }
        if (right && right->val == target && !right->left && !right->right) {
            root->right = nullptr;
            remove = true;   
        }
        dfs(left, target, remove);
        dfs(right, target, remove);
    }

    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        bool remove = false;
        do {
            remove = false;
            dfs(root, target, remove);
            if (!root->left && !root->right && root->val == target)
                return nullptr;
        } while (remove);
        return root;
    }
};