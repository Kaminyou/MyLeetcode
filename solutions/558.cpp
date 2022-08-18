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
    // both are leave ->  or
    // only one is leaf
    //   -> true => just leaf one
    //   -> false => return not leaf one
    // both are not leave => get each nodes
    Node* dfs(Node* quadTree1, Node* quadTree2) {
        if (quadTree1->isLeaf && quadTree2->isLeaf) {
            bool res = quadTree1->val | quadTree2->val;
            return new Node(res, true);
        }
        if (quadTree1->isLeaf) {
            if (quadTree1->val == true) return quadTree1;
            else return quadTree2;
        }
        if (quadTree2->isLeaf) {
            if (quadTree2->val == true) return quadTree2;
            else return quadTree1;
        }
        Node* tl = dfs(quadTree1->topLeft, quadTree2->topLeft);
        Node* tr = dfs(quadTree1->topRight, quadTree2->topRight);
        Node* bl = dfs(quadTree1->bottomLeft, quadTree2->bottomLeft);
        Node* br = dfs(quadTree1->bottomRight, quadTree2->bottomRight);
        if (tl->isLeaf && tr->isLeaf && bl->isLeaf && br->isLeaf && tl->val && tr->val && bl->val && br->val) return new Node(true, true);
        return new Node(false, false, tl, tr, bl, br);
    }
    Node* intersect(Node* quadTree1, Node* quadTree2) {
        return dfs(quadTree1, quadTree2);
    }
};