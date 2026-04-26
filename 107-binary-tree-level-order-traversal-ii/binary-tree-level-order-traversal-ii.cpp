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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        std::vector<std::vector<int>> res;
        if (!root)
            return res;

        std::queue<TreeNode*> fQueue;
        fQueue.push(root);

        while (!fQueue.empty()) {
            int size = fQueue.size();
            std::vector<int> vec(size);
            for (int i = 0; i < size; i++) {
                TreeNode* node = fQueue.front();
                fQueue.pop();

                if (node->left)
                    fQueue.push(node->left);
                if (node->right)
                    fQueue.push(node->right);
                vec[i] = node->val;
            }
            res.push_back(vec);
        }

        std::reverse(res.begin(), res.end());
        return res;
    }
};