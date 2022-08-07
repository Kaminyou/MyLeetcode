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
    Node* constructRecursieve(vector<vector<int>>& grid, int x1, int x2, int y1, int y2) {
        if (x1 == x2) {
            int value = (grid[x1][y1] == 1) ? true : false;
            return new Node(value, true, nullptr, nullptr, nullptr, nullptr);
        }
        int midX = (x1 + x2) / 2;
        int midY = (y1 + y2) / 2;
        Node* topLeft = constructRecursieve(grid, x1, midX, y1, midY);
        Node* topRight = constructRecursieve(grid, x1, midX, midY + 1, y2);
        Node* bottomLeft = constructRecursieve(grid, midX + 1, x2, y1, midY);
        Node* bottomRight = constructRecursieve(grid, midX + 1, x2, midY + 1, y2);
        if (topLeft->isLeaf && topRight->isLeaf && bottomLeft->isLeaf && bottomRight->isLeaf &&
           topLeft->val == topRight->val && topLeft->val == bottomLeft->val && topLeft->val == bottomRight->val) {
            return new Node(topLeft->val, true, nullptr, nullptr, nullptr, nullptr);
        }
        return new Node(1, false, topLeft, topRight, bottomLeft, bottomRight);
    }
    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        return constructRecursieve(grid, 0, n - 1, 0, n - 1);
    }
};