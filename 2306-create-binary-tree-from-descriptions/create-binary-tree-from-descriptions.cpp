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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        struct Entry {
            TreeNode* node = nullptr;
            bool hasParent = false;
        };

        std::unordered_map<int, Entry> nodes;
        for (auto& description : descriptions) {
            const int parent = description[0];
            const int child = description[1];
            const bool left = description[2];

            if (nodes[child].node == nullptr) {
                nodes[child].node = new TreeNode(child);
            }
            if (nodes[parent].node == nullptr) {
                nodes[parent].node = new TreeNode(parent);
            }
            nodes[child].hasParent = true;
            
            if (left) nodes[parent].node->left = nodes[child].node;
            else nodes[parent].node->right = nodes[child].node;
        }

        for (auto& entry : nodes) {
            if (!entry.second.hasParent)
                return entry.second.node;
        }
        return nullptr;
    }
};