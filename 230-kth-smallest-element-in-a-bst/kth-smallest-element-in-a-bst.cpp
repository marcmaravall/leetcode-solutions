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
    std::vector<int> arr;

    void helper(TreeNode* root) {
        if (!root)
            return;
        arr.push_back(root->val);
        helper(root->left);
        helper(root->right);
    }

    int kthSmallest(TreeNode* root, int k) {
        helper(root);
        std::sort(arr.begin(), arr.end());
        return arr[k-1];
    }
};