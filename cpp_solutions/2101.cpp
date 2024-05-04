typedef long long LL;
class Solution {
public:
    bool isReachable(vector<int>& from, vector<int>& to) {
        LL x1 = from[0];
        LL y1 = from[1];
        LL r1 = from[2];
        LL x2 = to[0];
        LL y2 = to[1];
        LL distance = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
        return distance <= (r1 * r1);
    }
    int dfs(int from, vector<vector<int>>& adjacent, vector<bool>& visited) {
        visited[from] = true;
        int res = 1;
        for (auto neighbor : adjacent[from]) {
            if (!visited[neighbor]) res += dfs(neighbor, adjacent, visited);
        }
        return res;
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>> adjacent(n);
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (isReachable(bombs[i], bombs[j])) adjacent[i].push_back(j);
                if (isReachable(bombs[j], bombs[i])) adjacent[j].push_back(i);
            }
        }
        
        int res = 0;
        for (int i = 0; i < n; ++i) {
            vector<bool> visited(n, false);
            res = max(res, dfs(i, adjacent, visited));
        }
        return res;
    }
};