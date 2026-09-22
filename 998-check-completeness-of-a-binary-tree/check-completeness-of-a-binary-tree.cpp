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
    bool isCompleteTree(TreeNode* root) {
        std::queue<TreeNode*> q;
        q.push(root);
        bool foundNull = false;
        while (!q.empty()) {
            int s = q.size();
            for (int i = 0; i < s; i++) {
                TreeNode* curr = q.front();
                q.pop();
                if (!curr) {
                    foundNull = true;
                    continue;
                }
                if (foundNull)
                    return false;
                q.push(curr->left);
                q.push(curr->right);
            }
        }
        return true;
    }
};