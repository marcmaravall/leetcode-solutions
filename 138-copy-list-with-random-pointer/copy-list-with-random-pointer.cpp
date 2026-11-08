/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* start = head;
        std::unordered_map<Node*, Node*> map;
        while (head) {
            if (!map[head])
                map[head] = new Node(head->val);
            if (head->random && !map[head->random])
                map[head->random] = new Node(head->random->val);
            if (head->next && !map[head->next])
                map[head->next] = new Node(head->next->val);
            map[head]->next = map[head->next];
            map[head]->random = map[head->random];
            head = head->next;
        }
        return map[start];
    }
};