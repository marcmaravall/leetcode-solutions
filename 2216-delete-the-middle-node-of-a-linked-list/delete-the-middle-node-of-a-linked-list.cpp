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
    ListNode* deleteMiddle(ListNode* head) {
        if (!head || !head->next)
            return nullptr;
        
        int length = 0;
        for (ListNode* node = head; node; node = node->next) {
            length++;
        }

        ListNode* res = head;
        ListNode* last = nullptr;
        for (int i = 0; i < length/2; i++) {
            last = head;
            head = head->next;
        }

        last->next = head->next;

        return res;
    }
};