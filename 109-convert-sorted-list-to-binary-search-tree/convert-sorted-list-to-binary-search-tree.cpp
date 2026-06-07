/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        std::vector<int> arr;
        while (head) {
            arr.push_back(head->val);
            head = head->next;
        }   
        return sortedArrayToBST(arr);
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.size() == 0)
            return nullptr;
        return toTree(nums, 0, nums.size()-1);
    }

    TreeNode* toTree(std::vector<int>& nums, int start, int end) {
        if (start > end)
            return nullptr;
        
        int mid = (start+end)/2;

        TreeNode* out = new TreeNode(nums[mid]);
        out->left =  toTree(nums, start, mid-1);
        out->right = toTree(nums, mid+1, end);
        return out;
    }
};