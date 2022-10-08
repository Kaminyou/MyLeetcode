class Solution {
public:
    vector<vector<vector<int>>> memo;
    int catMouseGame(vector<vector<int>>& graph) {
        int n = graph.size();
        memo.resize(n, vector<vector<int>>(n, vector<int>(3, 0))); // memo[mouse][cat][turn]
        
        queue<vector<int>> q;
        for (int i = 0; i < n; ++i) {
            for (int j = 1; j <= 2; ++j) {
                memo[0][i][j] = 1;
                q.push({0, i, j});
                if (i != 0) {
                    memo[i][i][j] = 2;
                    q.push({i, i, j});
                }
            }
        }
        
        while (!q.empty()) {
            int mouse = q.front()[0];
            int cat = q.front()[1];
            int turn = q.front()[2];
            int status = memo[mouse][cat][turn];
            q.pop();
            if (turn == 1) { // mouse -> cat
                for (auto& neighbor : graph[cat]) {
                    if (neighbor == 0) continue;
                    if (memo[mouse][neighbor][2] != 0) continue;
                    if (status == 2) {
                        memo[mouse][neighbor][2] = 2;
                        q.push({mouse, neighbor, 2});
                    }
                    else if (allChildrenWin(mouse, neighbor, 2, graph)) {
                        memo[mouse][neighbor][2] = 1;
                        q.push({mouse, neighbor, 2});
                    }
                }
            }
            else {
                for (auto& neighbor : graph[mouse]) {
                    if (memo[neighbor][cat][1] != 0) continue;
                    if (status == 1) {
                        memo[neighbor][cat][1] = 1;
                        q.push({neighbor, cat, 1});
                    }
                    else if (allChildrenWin(neighbor, cat, 1, graph)) {
                        memo[neighbor][cat][1] = 2;
                        q.push({neighbor, cat, 1});
                    }
                }
            }
        }
        return memo[1][2][1];
    }
    bool allChildrenWin(int mouse, int cat, int turn, vector<vector<int>>& graph) {
        if (turn == 1) {
            for (auto& neighbor : graph[mouse]) {
                if (memo[neighbor][cat][2] != 2) return false;
            }
            return true;
        }
        else {
            for (auto& neighbor : graph[cat]) {
                if (neighbor != 0 && memo[mouse][neighbor][1] != 1) return false;
            }
            return true;
        }
    }
};