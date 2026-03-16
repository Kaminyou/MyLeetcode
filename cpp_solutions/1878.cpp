class Solution {
public:
    int getSum(int y, int x, int size, vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if (y - size < 0) return -1;
        if (y + size >= m) return -1;
        if (x - size < 0) return -1;
        if (x + size >= n) return -1;
        if (size == 0) return grid[y][x];
        // up (y - size, x)
        // left (y, x - size)
        // down (y + size, x)
        // right (y, x + size)
        int sum = 0;
        int diag = x + y - size;
        int revDiag = y - x + size;
        for (int i = 0; i < size; ++i) {
            int currY = y - size + i;
            int currX = diag - currY;
            sum += grid[currY][currX];
        }
        for (int i = 0; i < size; ++i) {
            int currY = y + i;
            int currX = currY - revDiag;
            sum += grid[currY][currX];
        }
        diag = x + y + size;
        revDiag = y - x - size;
        for (int i = 0; i < size; ++i) {
            int currY = y + size - i;
            int currX = diag - currY;
            sum += grid[currY][currX];
        }
        for (int i = 0; i < size; ++i) {
            int currY = y - i;
            int currX = currY - revDiag;
            sum += grid[currY][currX];
        }
        return sum;
    }
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        set<int> st;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k * 2 + 1 <= min(m, n); ++k) {
                    int sum = getSum(i, j, k, grid);
                    if (sum != -1) {
                        st.insert(sum);
                    }
                }
            }
        }
        vector<int> res;
        for (auto it = st.rbegin(); it != st.rend(); ++it) {
            res.push_back(*it);
            if (res.size() >= 3) break;
        }
        return res;
    }
};

