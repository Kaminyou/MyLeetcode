class Solution {
public:
    bool isPossibleToCutPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        queue<pair<int, int>> q;
        q.push({m - 1, n - 1});
        visited[m - 1][n - 1] = true;
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            if (x - 1 >= 0 && visited[x - 1][y] == false && grid[x - 1][y]) {
                q.push({x - 1, y});
                visited[x - 1][y] = true;
            }
            if (y - 1 >= 0 && visited[x][y - 1] == false && grid[x][y - 1]) {
                q.push({x, y - 1});
                visited[x][y - 1] = true;
            }
        }
        if (visited[0][0] == false) return true;

        unordered_set<int> st;
        // right -> down
        int x = 0;
        int y = 0;
        while (x != m - 1 || y != n - 1) {
            if (y + 1 < n && visited[x][y + 1]) {
                y += 1;
                if (x != m - 1 || y != n - 1) {
                    st.insert(x * n + y);
                }
            }
            else if (x + 1 < m && visited[x + 1][y]){
                x += 1;
                if (x != m - 1 || y != n - 1) {
                    st.insert(x * n + y);
                }
            }
        }

        // down -> right
        x = 0;
        y = 0;
        while (x != m - 1 || y != n - 1) {
            if (x + 1 < m && visited[x + 1][y]) {
                x += 1;
                if (st.count(x * n + y)) return true;
            }
            else if (y + 1 < n && visited[x][y + 1]) {
                y += 1;
                if (st.count(x * n + y)) return true;
            }
        }
        return false;
    }
};