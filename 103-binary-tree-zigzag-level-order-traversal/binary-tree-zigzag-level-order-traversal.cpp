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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        std::vector<std::vector<int>> res;
        if (!root)
            return res;
        std::queue<TreeNode*> fQueue;
        fQueue.push(root);
        int depth = 1;

        while (!fQueue.empty()) {
            int size = fQueue.size();
            std::vector<int> vec(size);
            for (int i = 0; i < size; i++) {
                TreeNode* node = fQueue.front();
                fQueue.pop();
                if (node->right)
                    fQueue.push(node->right);
                if (node->left)
                    fQueue.push(node->left);
                vec[i] = node->val;
            }

            depth++;
            if (depth % 2 == 0)
                std::reverse(vec.begin(), vec.end());
            res.push_back(vec);
        }

        return res;
    }
};