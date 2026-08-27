/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* construct(std::vector<std::vector<int>>& grid, int r, int c, int size) {
        if (size == 1)
            return new Node(grid[r][c], true);
        int quadSize = size/2;
        Node* topLeft = construct(grid, r, c, quadSize);
        Node* topRight = construct(grid, r, c+quadSize, quadSize);
        Node* bottomLeft = construct(grid, r+quadSize, c, quadSize);
        Node* bottomRight = construct(grid, r+quadSize, c+quadSize, quadSize);
        bool allLeafs = topLeft->isLeaf && topRight->isLeaf && bottomLeft->isLeaf && bottomRight->isLeaf;
        int sum = topLeft->val + topRight->val + bottomLeft->val + bottomRight->val;
        if (allLeafs && sum % 4 == 0) {
            return new Node(sum==4, true);
        }
        return new Node(false, false, topLeft, topRight, bottomLeft, bottomRight);
    }

    Node* construct(vector<vector<int>>& grid) {
        if (grid.empty())
            return nullptr;
        return construct(grid, 0, 0, grid.size());
    }
};