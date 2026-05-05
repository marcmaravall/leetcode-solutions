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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head)
            return nullptr;
        if (!head->next)
            return head;
        if (k <= 0)
            return head;
        
        ListNode* start = head;
        ListNode* end = head->next;
        ListNode* last = head;

        int size = 0;
        while (head->next) {
            size++;

            if (head->next && !head->next->next) {
                size++;
                last = head;
                end = head->next;
                break;
            }
            head = head->next;
        }

        if (k >= size) {
            k %= size;
            return rotateRight(start, k);
        }

        end->next = start;
        last->next = nullptr;

        return rotateRight(end, k-1);
    }
};