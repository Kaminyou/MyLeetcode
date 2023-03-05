class Solution {
public:
    int minJumps(vector<int>& arr) {
        unordered_map<int, vector<int>> mp;
        unordered_map<int, bool> mpUsed;
        int n = arr.size();
        for (int i = 0; i < n; ++i) {
            mp[arr[i]].push_back(i);
            mpUsed[arr[i]] = false;
        }

        vector<bool> visited(n, false);
        queue<int> q;
        q.push(0);
        visited[0] = true;

        int step = 0;
        while (!q.empty()) {
            int m = q.size();
            for (int i = 0; i < m; ++i) {
                int node = q.front();
                q.pop();
                if (node == n - 1) return step;
                if (node - 1 >= 0 && !visited[node - 1]) {
                    q.push(node - 1);
                    visited[node - 1] = true;
                }
                if (node + 1 < n && !visited[node + 1]) {
                    q.push(node + 1);
                    visited[node + 1] = true;
                }
                if (!mpUsed[arr[node]]) {
                    mpUsed[arr[node]] = true;
                    for (auto& neighbor : mp[arr[node]]) {
                        if (visited[neighbor]) continue;
                        q.push(neighbor);
                        visited[neighbor] = true;
                    }
                }
            }
            step++;
        }
        return -1;
    }
};