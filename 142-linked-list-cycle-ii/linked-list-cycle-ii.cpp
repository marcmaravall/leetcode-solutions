/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        std::unordered_map<ListNode*, bool> map;
        while (head && head->next) {
            map[head] = true;
            head = head->next;
            if (map[head])
                return head;
        }

        return nullptr;
    }
};