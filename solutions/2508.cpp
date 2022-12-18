class Solution {
public:
    bool isPossible(int n, vector<vector<int>>& edges) {
        vector<int> degrees(n, 0);
        vector<unordered_set<int>> hashEdges(n);
        for (auto& edge : edges) {
            degrees[edge[0] - 1]++;
            degrees[edge[1] - 1]++;
            hashEdges[edge[0] - 1].insert(edge[1] - 1);
            hashEdges[edge[1] - 1].insert(edge[0] - 1);
        }
        
        int cnt = 0;
        vector<int> collections;
        for (int i = 0; i < n; ++i) {
            if (degrees[i] & 1) {
                cnt++;
                collections.push_back(i);
            }
        }

        if (cnt == 0) return true;        
        else if (cnt == 2) {
            if (hashEdges[collections[0]].count(collections[1])) {
                for (int i = 0; i < n; ++i) {
                    if (i != collections[0] && i != collections[1]) {
                        if (!hashEdges[i].count(collections[0]) && !hashEdges[i].count(collections[1])) return true;
                    }
                }
                return false;
            }
            else return true;
        }
        
        else if (cnt == 4) {
            if (!hashEdges[collections[0]].count(collections[1]) && !hashEdges[collections[2]].count(collections[3])) return true;
            if (!hashEdges[collections[0]].count(collections[2]) && !hashEdges[collections[1]].count(collections[3])) return true;
            if (!hashEdges[collections[0]].count(collections[3]) && !hashEdges[collections[1]].count(collections[2])) return true;
            return false;
        }
        else return false;
    }
};
