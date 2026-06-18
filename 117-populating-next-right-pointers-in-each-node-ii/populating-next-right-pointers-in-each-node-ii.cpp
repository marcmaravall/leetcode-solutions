/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (!root)
            return root;
        
        std::queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            size_t size = q.size();
            Node* last = nullptr;
            for (int i = 0; i < size; i++) {
                Node* current = q.front();
                if (last)
                    last->next = current;
                last = current;

                if (current->left)
                    q.push(current->left); 
                if (current->right)
                    q.push(current->right);
                q.pop();
            }
        }

        return root;
    }
};