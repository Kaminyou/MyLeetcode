class Solution {
public:
    int oneDimSum(vector<int>& array, int median) {
        int sum = 0;
        for (auto& num : array) {
            sum += abs(num - median);
        }
        return sum;
    }
    int minTotalDistance(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        // collect rows
        vector<int> rows;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) rows.push_back(i);
            }
        }
        
        // collect cols
        vector<int> cols;
        for (int j = 0; j < n; ++j) {
            for (int i = 0; i < m; ++i) {
                if (grid[i][j] == 1) cols.push_back(j);
            }
        }
        
        // find median
        int rowMedian = rows[rows.size() / 2];
        int colMedian = cols[cols.size() / 2];
        
        // get sum
        return oneDimSum(rows, rowMedian) + oneDimSum(cols, colMedian);
    }
};