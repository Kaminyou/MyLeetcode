class Graph {
public:
    int N;
    vector<vector<pair<int, int>>> adjacency;
    Graph(int n, vector<vector<int>>& edges) {
        this->N = n;
        adjacency.resize(n);
        for (auto& edge : edges) {
            adjacency[edge[0]].push_back({edge[1], edge[2]});
        }
    }
    
    void addEdge(vector<int> edge) {
        adjacency[edge[0]].push_back({edge[1], edge[2]});
    }
    
    int shortestPath(int node1, int node2) {
        vector<int> costs(N, INT_MAX);
        vector<bool> visited(N, false);
        priority_queue<pair<int, int>> pq;
        pq.push({0, node1});
        costs[node1] = 0;
        
        while (!pq.empty()) {
            auto [cost, node] = pq.top();
            visited[node] = true;
            cost = -cost;
            pq.pop();
            for (auto& [neighbor, pathCost] : adjacency[node]) {
                int newCost = cost + pathCost;
                if (newCost < costs[neighbor]) {
                    costs[neighbor] = newCost;
                    if (!visited[neighbor]) pq.push({-newCost, neighbor});
                }
            }
        }
        
        if (costs[node2] == INT_MAX) return -1;
        return costs[node2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */