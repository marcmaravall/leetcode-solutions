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
class CBTInserter {
private:
    TreeNode* m_root = nullptr;

public:
    CBTInserter(TreeNode* root) {
        m_root = root;
    }
    
    int insert(int val) {
        std::queue<TreeNode*> q;
        q.push(m_root);

        while (!q.empty()) {
            size_t s = q.size();
            for (int i = 0; i < s; i++) {
                TreeNode* current = q.front();
                q.pop();

                if (!current->left) {
                    current->left = new TreeNode(val);
                    return current->val;
                } else q.push(current->left);
                                
                if (!current->right) {
                    current->right = new TreeNode(val);
                    return current->val;
                } else q.push(current->right);
            }
        }
        return -1;
    }
    
    TreeNode* get_root() {
        return m_root;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */