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
class FindElements {
public:
    TreeNode* node;
    std::unordered_map<int, bool> freq;
    
    void recover(TreeNode* treeNode) {
        if (!treeNode)
            return;
        freq[treeNode->val] = true;
        if (treeNode->val != -1 && treeNode->left != nullptr) {
            treeNode->left->val = 2*treeNode->val + 1;
            recover(treeNode->left);
        }
        if (treeNode->val != -1 && treeNode->right != nullptr) {
            treeNode->right->val = 2*treeNode->val + 2;
            recover(treeNode->right);
        }
    }

    void contaminate(TreeNode* root) {
        if (!root)
            return;
        root->val = -1;
        contaminate(root->left);
        contaminate(root->right);
    }

    FindElements(TreeNode* root) {
        node = root;
        contaminate(root);
        node->val = 0;
        recover(root);
    }
    
    bool find(int target) {
        return freq[target];
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */