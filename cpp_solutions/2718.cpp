class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& queries) {
        vector<bool> rowHash(n, false);
        vector<bool> columnHash(n, false);
        int row = 0;
        int column = 0;
        int m = queries.size();
        long long res = 0;
        for (int i = m - 1; i >= 0; --i) {
            int type = queries[i][0];
            int index = queries[i][1];
            int value = queries[i][2];
            // row
            if (type == 0) {
                if (rowHash[index]) continue;
                rowHash[index] = true;
                row += 1;
                res += (n - column) * value;
            }
            // col
            else {
                if (columnHash[index]) continue;
                columnHash[index] = true;
                column += 1;
                res += (n - row) * value;
            }
        }
        return res;
    }
};