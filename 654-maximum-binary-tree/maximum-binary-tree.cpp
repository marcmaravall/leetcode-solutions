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
    TreeNode* helper(const std::vector<int>& nums, int left, int right) {
        if (left > right) {
            return nullptr;
        }
        if (left == right) {
            return new TreeNode(nums[left]);
        }
        int maxIndex = left;
        for (int i = left; i <= right; i++) {
            if (nums[i] > nums[maxIndex])
                maxIndex = i;
        }
        TreeNode* l = helper(nums, left, maxIndex-1);
        TreeNode* r = helper(nums, maxIndex+1, right);
        return new TreeNode(nums[maxIndex], l, r);
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return helper(nums, 0, nums.size()-1);
    }
};