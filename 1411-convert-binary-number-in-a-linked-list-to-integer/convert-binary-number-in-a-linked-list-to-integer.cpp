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
    int getDecimalValue(ListNode* head) {
        ListNode* buff;
        std::size_t s = 0;
        for (buff = head; buff; buff = buff->next)
            s++;
        int res = 0;
        for (int i = 0; head != nullptr; i++) {
            res += head->val << (s-i-1);
            head = head->next;
        }
        return res;
    }
};