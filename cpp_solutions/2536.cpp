class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> difference(n + 1, vector<int>(n + 1, 0));
        for (auto& query : queries) {
            int row1 = query[0];
            int col1 = query[1];
            int row2 = query[2];
            int col2 = query[3];
            difference[row1][col1] += 1;
            difference[row2 + 1][col1] -= 1;
            difference[row1][col2 + 1] -= 1;
            difference[row2 + 1][col2 + 1] += 1;
        }
        vector<vector<int>> answer(n, vector<int>(n, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int a = (i >= 1 && j >= 1) ? answer[i - 1][j - 1] : 0;
                int b = (i >= 1) ? answer[i - 1][j] : 0;
                int c = (j >= 1) ? answer[i][j - 1] : 0;
                answer[i][j] = difference[i][j] - a + b + c;
            }
        }
        return answer;
    }
};