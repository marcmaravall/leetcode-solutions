/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    std::unordered_map<Node*, Node*> mp;

    Node* dfs(Node* current)
    {
        std::vector<Node*> neighbour;
        
        Node* clone = new Node(current->val);
        mp[current] = clone;

        for (auto it : current->neighbors) {
            if (mp.find(it) != mp.end())
                neighbour.push_back(mp[it]);
            else
                neighbour.push_back(dfs(it));
        }
        
        clone->neighbors = neighbour;
        return clone;
    }

    Node* cloneGraph(Node* node) {
        std::unordered_map<Node*, Node*> mp;
        if (!node)
            return NULL;
        
        if (node->neighbors.size() == 0) 
            return new Node(node->val);
        
        return dfs(node);
    }
};
