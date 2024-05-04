class Solution {
public:
    int M;
    int N;
    vector<tuple<int, int, char>> directions = {{0, 1, 'R'}, {0, -1, 'L'}, {1, 0, 'U'}, {-1, 0, 'D'}};
    
    void dfs(vector<vector<int>>& grid, int x, int y, string& path) {
        grid[x][y] = -1;
        for (auto direction : directions) {
            int _x = x + get<0>(direction);
            int _y = y + get<1>(direction);
            if (_x < 0 || _x >= M || _y < 0 || _y >= N) continue;
            if (grid[_x][_y] < 1) continue;
            path.push_back(get<2>(direction));
            dfs(grid, _x, _y, path);
        }
        path.push_back('|');
        // reason: without '|'
        // e.g. 111  111
        //      001  100
        //      RRU  RRU
    }
    int numDistinctIslands(vector<vector<int>>& grid) {
        M = grid.size();
        N = grid[0].size();
        unordered_set<string> st;
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (grid[i][j] == 1) {
                    string path = "";
                    dfs(grid, i, j, path);
                    st.insert(path);
                }
            }
        }
        return st.size();
    }
};
