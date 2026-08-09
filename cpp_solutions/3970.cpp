class Solution {
public:
    int hash(int node, int label, int cnt) {
        return node * 26 * 51 + label * 51 + cnt; 
    }
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int, int>>> graph(n);
        for (auto& edge : edges) {
            graph[edge[0]].push_back({edge[1], edge[2]});
        }
        unordered_map<int, int> mp;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, 0, labels[0] - 'a', 1}); // cost, node, label, k
        mp[hash(0, labels[0] - 'a', 1)] = 0;
        while (!pq.empty()) {
            vector<int> info = pq.top();
            pq.pop();
            int cost = info[0];
            int node = info[1];
            int label = info[2];
            int cnt = info[3];
            if (node == n - 1) return cost;
            for (auto& neighborInfo : graph[node]) {
                int neighbor = neighborInfo.first;
                int neighborCost = neighborInfo.second;
                int neighborLabel = labels[neighbor] - 'a';
                if (neighborLabel == label && cnt + 1 > k) continue;
                int newCost = cost + neighborCost;
                int newCnt = 1;
                if (neighborLabel == label) {
                    newCnt = cnt + 1;
                }
                int minCost = INT_MAX;
                if (mp.count(hash(neighbor, neighborLabel, newCnt))) minCost = mp[hash(neighbor, neighborLabel, newCnt)];
                if (newCost >= minCost) continue;
                pq.push({newCost, neighbor, neighborLabel, newCnt});
                mp[hash(neighbor, neighborLabel, newCnt)] = newCost;
            }
        }
        return -1;
    }
};
