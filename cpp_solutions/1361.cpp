class Solution {
public:
    bool traverse(int node, vector<int>& leftChild, vector<int>& rightChild, vector<bool>& visited
) {
        if (node == -1) return true;
        if (visited[node]) return false;
        visited[node] = true;
        bool left = traverse(leftChild[node], leftChild, rightChild, visited);
        bool right = traverse(rightChild[node], leftChild, rightChild, visited);
        return left && right;
    }
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> parents(n, -1);
        for (int i = 0; i < n; ++i) {
            int child = leftChild[i];
            if (child != -1) {
                if (parents[child] != -1) return false;
                parents[child] = i;
            }
            child = rightChild[i];
            if (child != -1) {
                if (parents[child] != -1) return false;
                parents[child] = i;
            }
        }

        // find root
        int cnt = 0;
        int current = 0;
        while (parents[current] != -1) {
            current = parents[current];
            cnt++;
            if (cnt > 2 * n) return false;
        }

        // traverse
        vector<bool> visited(n, false);
        bool isTree = traverse(current, leftChild, rightChild, visited);
        int nodeCnt = 0;
        for (int i = 0; i < n; ++i) nodeCnt += visited[i];
        return isTree && (nodeCnt == n);
    }
};
