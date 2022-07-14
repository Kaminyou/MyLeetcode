class DisjointSet {
private:
    vector<int> parent;
    vector<int> rank;
public:
    DisjointSet(int size) {
        parent.resize(size, 0);
        rank.resize(size, 0);
        for (int i = 0; i < size; ++i) parent[i] = i;
    }
    int find(int x) {
        if (x != parent[x]) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    void join(int x, int y) {
        int xP = find(x);
        int yP = find(y);
        if (xP == yP) return;
        if (rank[xP] > rank[yP]) {
            parent[yP] = xP;
        }
        else if (rank[xP] < rank[yP]) {
            parent[xP] = yP;
        }
        else {
            parent[yP] = xP;
            rank[xP]++;
        }
    }
    bool isConnected(int x, int y) {
        int xP = find(x);
        int yP = find(y);
        return xP == yP;
    }
};
class Solution {
public:
    static bool compare(const vector<int>& v1, const vector<int>& v2) {
        return v1[2] < v2[2];
    }
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        DisjointSet* disjointSet = new DisjointSet(n);
        sort(edgeList.begin(), edgeList.end(), compare);
        
        int querySize = queries.size();
        for (int i = 0; i < querySize; ++i) {
            queries[i].push_back(i);
        }
        sort(queries.begin(), queries.end(), compare);
        
        vector<bool> res(querySize, false);
        
        int edgeIdx = 0;
        for (int i = 0; i < querySize; ++i) {
            while (edgeIdx < edgeList.size() && edgeList[edgeIdx][2] < queries[i][2]) {
                disjointSet->join(edgeList[edgeIdx][0], edgeList[edgeIdx][1]);
                edgeIdx++;
            }
            int queryIdx = queries[i][3];
            bool ans = disjointSet->isConnected(queries[i][0], queries[i][1]);
            res[queryIdx] = ans;
        }
        return res;
    }
};