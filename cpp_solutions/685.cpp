class DisjointSet {
private:
    vector<int> parent;
    vector<int> rank;
public:
    DisjointSet(int n) {
        parent.resize(n, 0);
        for (int i = 0; i < n; ++i) parent[i] = i;
        rank.resize(n, 0);
    }
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    bool join(int x, int y) {
        int pX = find(x);
        int pY = find(y);
        if (pX == pY) return false;
        if (rank[pX] > rank[pY]) {
            parent[pY] = pX;
        }
        else if (rank[pX] < rank[pY]) {
            parent[pX] = pY;
        }
        else {
            rank[pX]++;
            parent[pY] = pX;
        }
        return true;
    }
};
class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        vector<int> ans1 = {-1, -1};
        vector<int> ans2 = {-1, -1}; 
        int n = edges.size();
        vector<int> parent(n, -1);
        for (auto& edge : edges) {
            int from = edge[0] - 1;
            int to = edge[1] - 1;
            if (parent[to] != -1) {
                ans1 = {parent[to] + 1, to + 1};
                ans2 = edge;
                edge[0] = -1;
                edge[1] = -1;
            }
            parent[to] = from;
        }
        DisjointSet* disjointSet = new DisjointSet(n);
        for (auto& edge : edges) {
            if (edge[0] == -1) continue;
            bool success = disjointSet->join(edge[0] - 1, edge[1] - 1);
            if (!success) {
                if (ans1[0] != -1) return ans1; // example 1
                return edge; // example 2
            }
        }
        return ans2; 
    }
};

// V2
// class DisjointSet {
// private:
//     vector<int> parent;
//     vector<int> rank;
// public:
//     DisjointSet(int n) {
//         parent.resize(n, 0);
//         for (int i = 0; i < n; ++i) parent[i] = i;
//         rank.resize(n, 0);
//     }
//     int find(int x) {
//         if (parent[x] != x) {
//             parent[x] = find(parent[x]);
//         }
//         return parent[x];
//     }
//     bool join(int x, int y) {
//         int pX = find(x);
//         int pY = find(y);
//         if (pX == pY) return false;
//         if (rank[pX] > rank[pY]) {
//             parent[pY] = pX;
//         }
//         else if (rank[pX] < rank[pY]) {
//             parent[pX] = pY;
//         }
//         else {
//             rank[pX]++;
//             parent[pY] = pX;
//         }
//         return true;
//     }
// };
// class Solution {
// public:
//     void dfs(int node, vector<vector<int>>& graph, vector<int>& visited, int& from, int& to) {
//         visited[node] = 0;
//         for (auto& neighbor : graph[node]) {
//             if (visited[neighbor] == 0) {
//                 from = node + 1;
//                 to = neighbor + 1;
//             }
//             else dfs(neighbor, graph, visited, from, to);
//         }
//         visited[node] = 1;
        
//     }
//     vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
//         // check inDegrees
//         int n = edges.size();
//         vector<int> inDegrees(n, 0);
//         vector<vector<int>> graph(n);
//         for (auto& edge : edges) {
//             inDegrees[edge[1] - 1]++;
//             graph[edge[0] - 1].push_back(edge[1] - 1);
//         }
//         int node = -1;
//         for (int i = 0; i < n; ++i) {
//             if (inDegrees[i] > 1) {
//                 node = i + 1;
//                 break;
//             }
//         }
//         vector<int> indegreeEdge = {-1, -1};
//         if (node != -1) {
//             for (int i = n - 1; i >=0; --i) {
//                 if (edges[i][1] == node) {
//                     indegreeEdge = edges[i];
//                     break;
//                 }
//             }
//         }
        
//         // check cycle
//         vector<int> cycleEdge = {-1, -1};
//         vector<int> visited(n, -1);
//         int from = -1;
//         int to = -1;
//         for (int i = 0; i < n; ++i) {
//             if (visited[i] != -1) continue;
//             dfs(i, graph, visited, from, to);
//         }
//         cycleEdge[0] = from;
//         cycleEdge[1] = to;
//         if (indegreeEdge[0] == cycleEdge[0] && indegreeEdge[1] == cycleEdge[1]) return cycleEdge;
//         if (indegreeEdge[0] != -1 && cycleEdge[0] != -1) {
//             int start = indegreeEdge[1] - 1;
//             int current = graph[start][0];
//             int prev = start;
//             while (current != start) {
//                 prev = current;
//                 current = graph[current][0];
//             }
//             return {prev + 1, current + 1};
//         }
//         else if (indegreeEdge[0] != -1) return indegreeEdge;
//         DisjointSet* disjointSet = new DisjointSet(n);
//         for (auto& edge : edges) {
//             bool success = disjointSet->join(edge[0] - 1, edge[1] - 1);
//             if (!success) {
//                 return edge;
//             }

//         }
//         return cycleEdge;
//     }
// };