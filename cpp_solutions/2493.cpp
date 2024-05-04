class Solution {
public:
    
    int normalBfs(int start, unordered_map<int, unordered_set<int>>& hashEdges, vector<bool> visited) {
        queue<int> q;
        q.push(start);
        visited[start] = true;

        int level = 0;
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; ++i) {
                int node = q.front();
                q.pop();
                for (auto& neighbor : hashEdges[node]) {
                    if (visited[neighbor]) continue;
                    q.push(neighbor);
                    visited[neighbor] = true;
                }
            }
            level++;
        }
        return level;
    }
    int checkConnectedBfs(int start, unordered_map<int, unordered_set<int>>& hashEdges, vector<bool>& visited) {
        vector<int> members;
        vector<bool> visitedCopy = visited;
        queue<int> q;
        q.push(start);
        members.push_back(start);
        visited[start] = true;

        int level = 0;
        while (!q.empty()) {
            int n = q.size();
            vector<int> collections;
            for (int i = 0; i < n; ++i) {
                int node = q.front();
                q.pop();
                for (auto& neighbor : hashEdges[node]) {
                    if (visited[neighbor]) continue;
                    collections.push_back(neighbor);
                    visited[neighbor] = true;
                }
            }
            // check if all nodes in the same level have any connection;
            int m = collections.size();

            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < i; ++j) {
                    if (hashEdges[collections[i]].count(collections[j])) return -1;
                }
            }
            for (int i = 0; i < m; ++i) {
                q.push(collections[i]);
                members.push_back(collections[i]);
            }
            level++;
        }
        for (auto& member : members) {
            level = max(level, normalBfs(member, hashEdges, visitedCopy));
        }
        return level;
    }
    int magnificentSets(int n, vector<vector<int>>& edges) {
        unordered_map<int, unordered_set<int>> hashEdges;

        for (auto& edge : edges) {
            hashEdges[edge[0] - 1].insert(edge[1] - 1);
            hashEdges[edge[1] - 1].insert(edge[0] - 1);
        }
        vector<bool> visited(n, false);
        int maxRes = 0;
        
        for (int node = 0; node < n; ++node) {
            if (visited[node]) continue;
            int result = checkConnectedBfs(node, hashEdges, visited);
            if (result == -1) return -1;
            
            maxRes += result;
        }
        return maxRes;
    }
};
