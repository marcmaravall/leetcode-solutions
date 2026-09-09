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
private:
    int maxFreq = 0;
    std::unordered_map<int, int> freq;
    int dfs(TreeNode* root, std::vector<int>& vec) {
        if (!root)
            return 0;
        int left = dfs(root->left, vec);
        int right = dfs(root->right, vec);
        int sum = left+right+root->val;
        if (maxFreq < ++freq[sum]) {
            maxFreq = freq[sum];
            vec.clear();
            vec.push_back(sum);
        } else if (maxFreq == freq[sum]) {
            vec.push_back(sum);
        }
        return sum;
    }

public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        std::vector<int> res;
        dfs(root, res);
        return res;
    }
};