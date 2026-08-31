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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int minDistance = INT_MAX;
        int maxDistance = -1;
        
        int firstCritical = -1;
        int lastCritical = -1;

        int last = head->val;
        head = head->next;
        for (int i = 1; head->next; i++) {
            const int curr = head->val;
            const int next = head->next->val;
            bool critical = ((last < curr && curr > next) ||
                             (last > curr && curr < next));
            if (critical) {
                if (firstCritical == -1)
                    firstCritical = i;
                else {
                    minDistance = std::min(minDistance, i-lastCritical);
                    maxDistance = i-firstCritical;
                }
                lastCritical = i;
            }
            
            last = head->val;
            head = head->next;
        }

        if (minDistance == -1 || minDistance == INT_MAX)
            return { -1, -1 };
        return { minDistance, maxDistance };
    }
};