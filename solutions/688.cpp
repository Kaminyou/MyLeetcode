class Solution {
public:
    vector<pair<int, int>> directions = {{1, 2}, {2, 1}, {-1, 2}, {-2, 1}, {1, -2}, {2, -1}, {-1, -2}, {-2, -1}};
    double dp(vector<vector<vector<double>>>& memo, int n, int row, int col, int k) {
        if (k == 0) return memo[row][col][k] = 1.0;
        if (memo[row][col][k] != 0) return memo[row][col][k];
        for (auto direction : directions) {
            int _x = row + direction.first;
            int _y = col + direction.second;
            if (_x < 0 || _x >= n || _y < 0 || _y >= n) continue;
            memo[row][col][k] += dp(memo, n, _x, _y, k - 1);
        }
        return memo[row][col][k];
    }
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<vector<double>>> memo(n, vector<vector<double>>(n, vector<double>(k + 1, 0)));
        return dp(memo, n, row, column, k) / pow(8, k);
    }
};