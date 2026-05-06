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
    vector<int> largestValues(TreeNode* root) {
        if (!root)
            return {};

        std::vector<int> res;
        std::queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            int s = q.size();
            int m = INT_MIN;
            for (int i = 0; i < s; i++) {
                TreeNode* front = q.front();
                m = max(front->val, m);
                if (front->left)
                    q.push(front->left);
                if (front->right)
                    q.push(front->right);
                q.pop();
            }
            res.push_back(m);
        }
        
        return res;
    }
};