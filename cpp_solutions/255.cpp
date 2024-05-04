class Solution {
public:
    int index = 0;
    bool verify(vector<int>& preorder, int minBound, int maxBound) {
        if (index == preorder.size() || preorder[index] > maxBound) return true;
        int mid = preorder[index];
        index++;
        return (mid > minBound) && verify(preorder, minBound, mid) && verify(preorder, mid, maxBound);
    }
    bool verifyPreorder(vector<int>& preorder) {
        return verify(preorder, INT_MIN, INT_MAX);
    }
};