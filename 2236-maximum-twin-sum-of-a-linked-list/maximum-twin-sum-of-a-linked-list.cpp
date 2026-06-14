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
class Solution {
public:
    int pairSum(ListNode* head) {
        std::vector<int> arr;
        for (; head; head = head->next) {
            arr.push_back(head->val);
        }

        int res = 0;
        const int n = arr.size();
        for (int i = 0; i < n/2; i++) {
            res = max(res, arr[i] + arr[n-i-1]);
        }
        
        return res;
    }
};