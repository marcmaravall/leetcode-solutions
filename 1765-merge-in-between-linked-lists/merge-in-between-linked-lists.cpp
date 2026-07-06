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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* res = list1;
        ListNode* a_min1 = list1;
        for (int i = 0; i < a-1; i++) {
            a_min1 = a_min1->next;
        }
        ListNode* b_plus1 = a_min1->next;
        for (int i = a; i <= b; i++) {
            b_plus1 = b_plus1->next;
        }
        a_min1->next = list2;
        while (list2->next) {
            list2 = list2->next;
        }
        list2->next = b_plus1;
        return res;
    }
};