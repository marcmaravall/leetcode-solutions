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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        struct ListNodeSort {
            bool operator()(ListNode* l, ListNode* r) const { return l->val < r->val; }
        };

        std::priority_queue<ListNode*, std::vector<ListNode*>, ListNodeSort> pqueue;
        for (auto* node : lists) {
            while (node) {
                pqueue.push(node);
                node = node->next;
            }
        }
        
        if (pqueue.empty())
            return nullptr;
        ListNode* last = pqueue.top();
        last->next = nullptr;
        pqueue.pop();
        while (!pqueue.empty()) {
            ListNode* curr = pqueue.top();
            pqueue.pop();
            curr->next = last;
            last = curr;
        }

        return last;
    }
};