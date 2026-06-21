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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        std::vector<long long> sums;
        std::queue<TreeNode*> q;
        q.push(root);

        for (int level = 0; !q.empty(); level++) {
            size_t s = q.size();
            long long current = 0;
            for (int i = 0; i < s; i++) {
                TreeNode* node = q.front();
                q.pop();
                current += node->val;
                
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            sums.push_back(current);
        }

        if (k-1 >= sums.size()) return -1;
        
        std::sort(sums.rbegin(), sums.rend());
        return sums[k-1];
    }
};