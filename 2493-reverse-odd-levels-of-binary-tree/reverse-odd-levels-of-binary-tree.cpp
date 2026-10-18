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
    TreeNode* reverseOddLevels(TreeNode* root) {
        std::queue<TreeNode*> q;
        q.push(root);
        for (int level = 0; !q.empty(); level++) {
            int size = q.size();
            std::vector<TreeNode*> nodes(size);
            for (int i = 0; i < size; i++) {
                TreeNode* curr = q.front();
                q.pop();
                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
                nodes[i] = curr;
            }
            if (level % 2 == 1)
            for (int i = 0; i < size/2; i++) {
                std::swap(nodes[i]->val, nodes[size-i-1]->val);
            }
        }
        return root;
    }
};