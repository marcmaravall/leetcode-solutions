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
    
    void recover(TreeNode* treeNode) {
        if (!treeNode)
            return;
        if (treeNode->val != -1 && treeNode->left != nullptr)
            treeNode->left->val = 2*treeNode->val + 1;
        if (treeNode->val != -1 && treeNode->right != nullptr)
            treeNode->right->val = 2*treeNode->val + 2;

        recover(treeNode->left);
        recover(treeNode->right);
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

    bool findHelper(TreeNode* root, int target) {
        if (!root)
            return false;
        if (root->val == target)
            return true;
        return findHelper(root->left, target) || findHelper(root->right, target);
    }
    
    bool find(int target) {
        return findHelper(node, target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */