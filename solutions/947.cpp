class Solution {
public:
    void dfs(int node, vector<vector<int>>& graph, vector<bool>& visited) {
        if (visited[node]) return;
        visited[node] = true;
        for (auto neighbor : graph[node]) {
            dfs(neighbor, graph, visited);
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<vector<int>> graph(n, vector<int>());
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }
        
        vector<bool> visited(n, false);
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (visited[i] == false) {
                count++;
                dfs(i, graph, visited);
            }
        }
        return n - count;
    }
};

// class DisjointSet {
// private:
//     vector<int> parent;
//     vector<int> rank;
//     int N;
// public:
//     DisjointSet(int n) {
//         parent.resize(n, 0);
//         for (int i = 0; i < n; ++i) parent[i] = i;
//         rank.resize(n, 0);
//         N = n;
//     }
//     int find(int x) {
//         if (x != parent[x]) {
//             parent[x] = find(parent[x]);
//         }
//         return parent[x];
//     }
//     void join(int x, int y) {
//         int pX = find(x);
//         int pY = find(y);
//         if (pX == pY) return;
//         N--;
//         if (rank[pX] > rank[pY]) {
//             parent[pY] = parent[pX];
//         }
//         else if (rank[pX] < rank[pY]) {
//             parent[pX] = parent[pY];
//         }
//         else {
//             parent[pY] = parent[pX];
//             rank[pX]++;
//         }
//     }
//     int getSize() {
//         return N;
//     }
// };
// class Solution {
// public:
//     int removeStones(vector<vector<int>>& stones) {
//         int n = stones.size();
//         DisjointSet* disjointSet = new DisjointSet(n);
//         for (int i = 0; i < n; ++i) {
//             for (int j = i + 1; j < n; ++j) {
//                 if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
//                     disjointSet->join(i, j);
//                 }
//             }
//         }
//         return n - disjointSet->getSize();
//     }
// };