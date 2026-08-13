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
    vector<double> averageOfLevels(TreeNode* root) {
        std::vector<double> res;
        std::queue<TreeNode*> q;
        q.push(root);
        for (int i = 0; !q.empty(); i++) {
            size_t s = q.size();
            double n = 0.0;
            for (int j = 0; j < s; j++) {
                TreeNode* curr = q.front();
                n += curr->val;
                q.pop();
                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
            }
            res.push_back(n/static_cast<double>(s));
        }
        return res;
    }
};