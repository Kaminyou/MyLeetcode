class TreeAncestor {
public:
    vector<vector<int>> hierarchyParents;
    TreeAncestor(int n, vector<int>& parent) {
        hierarchyParents.resize(n, vector<int>(20));
        for (int i = 0; i < n; ++i) hierarchyParents[i][0] = parent[i];
        for (int j = 1; j < 20; ++j) {
            for (int i = 0; i < n; ++i) {
                if (hierarchyParents[i][j - 1] == -1) hierarchyParents[i][j] = -1;
                else hierarchyParents[i][j] = hierarchyParents[hierarchyParents[i][j - 1]][j - 1];
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        for (int i = 0; i < 20; ++i) {
            if ((k >> i) & 1) {
                node = hierarchyParents[node][i];
                if (node == -1) return -1;
            }
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */