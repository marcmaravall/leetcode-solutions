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
    ListNode* insertionSortList(ListNode* head) {
        std::vector<int> vec;
        ListNode* res = head;
        while (head) {
            vec.push_back(head->val);
            head = head->next;
        }
        std::sort(vec.begin(), vec.end());
        head = res;
        for (int i = 0; i < vec.size(); i++) {
            head->val = vec[i];
            head = head->next;
        }
        return res;
    }
};