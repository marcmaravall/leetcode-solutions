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
class BSTIterator {
public:
    std::vector<TreeNode*> inorder;
    int index = 0;

    void dfs(TreeNode* root) {
        if (!root)
            return;
        if (!root->left && !root->right) {
            inorder.push_back(root);
            return;
        }
        
        dfs(root->left);
        inorder.push_back(root);
        dfs(root->right);
    }

    BSTIterator(TreeNode* root) {
        dfs(root);
    }
    
    int next() {
        return inorder[index++]->val;
    }
    
    bool hasNext() {
        return index < inorder.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */