class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        long long sum = 0;
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                sum += grid[i][j];
            }
        }
        if (m == 1) {
            long long temp = 0;
            for (int i = 0; i < n; ++i) {
                if (temp == sum - temp - grid[0][i]) return true;
                temp += grid[0][i];
            }
        }
        if (n == 1) {
            long long temp = 0;
            for (int j = 0; j < m; ++j) {
                if (temp == sum - temp - grid[j][0]) return true;
                temp += grid[j][0];
            }
        }
        long long temp = 0;
        unordered_set<long long> st;
        for (int i = 0; i < m - 1; ++i) {
            for (int j = 0; j < n; ++j) {
                temp += grid[i][j];
                st.insert(grid[i][j]);
            }
            long long target = 2 * temp - sum;
            if (temp == sum - temp) return true;
            if (st.count(target)) {
                if (target == grid[0][0] || target == grid[0][n - 1]) return true;
                if (i != 0) {
                    if (n >= 2) return true;
                }
            }
        }
        temp = 0;
        st.clear();
        for (int i = m - 1; i >= 0; --i) {
            for (int j = 0; j < n; ++j) {
                temp += grid[i][j];
                st.insert(grid[i][j]);
            }
            long long target = 2 * temp - sum;
            if (temp == sum - temp) return true;
            if (st.count(target)) {
                if (target == grid[m - 1][0] || target == grid[m - 1][n - 1]) return true;
                if (i != m - 1) {
                    if (n >= 2) return true;
                }
            }
        }

        temp = 0;
        st.clear();
        for (int j = 0; j < n - 1; ++j) {
            for (int i = 0; i < m; ++i) {
                temp += grid[i][j];
                st.insert(grid[i][j]);
            }
            long long target = 2 * temp - sum;
            if (temp == sum - temp) return true;
            if (st.count(target)) {
                if (target == grid[0][0] || target == grid[m - 1][0]) return true;
                if (j != 0) {
                    if (m >= 2) return true;
                }
            }
        }


        temp = 0;
        st.clear();
        for (int j = n - 1; j >= 0; --j) {
            for (int i = 0; i < m; ++i) {
                temp += grid[i][j];
                st.insert(grid[i][j]);
            }
            long long target = 2 * temp - sum;
            if (temp == sum - temp) return true;
            if (st.count(target)) {
                if (target == grid[0][n - 1] || target == grid[m - 1][n - 1]) return true;
                if (j != n - 1) {
                    if (m >= 2) return true;
                }
            }
        }
        return false;
    }
};
