class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector<vector<bool>> matrix(n, vector<bool>(n, true));
        for (auto& mine : mines) {
            matrix[mine[0]][mine[1]] = false;
        }
        
        vector<vector<int>> left(n, vector<int>(n, 0));
        vector<vector<int>> right(n, vector<int>(n, 0));
        vector<vector<int>> up(n, vector<int>(n, 0));
        vector<vector<int>> down(n, vector<int>(n, 0));
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == false) right[i][j] = 0;
                else {
                    if (j > 0) right[i][j] = right[i][j - 1] + 1;
                    else right[i][j] = 1;
                }
            }
            for (int j = n - 1; j >= 0; --j) {
                if (matrix[i][j] == false) left[i][j] = 0;
                else {
                    if (j < n - 1) left[i][j] = left[i][j + 1] + 1;
                    else left[i][j] = 1;
                }
            }
        }

        for (int j = 0; j < n; ++j) {
            for (int i = 0; i < n; ++i) {
                if (matrix[i][j] == false) down[i][j] = 0;
                else {
                    if (i > 0) down[i][j] = down[i - 1][j] + 1;
                    else down[i][j] = 1;
                }
            }
            for (int i = n - 1; i >= 0; --i) {
                if (matrix[i][j] == false) up[i][j] = 0;
                else {
                    if (i < n - 1) up[i][j] = up[i + 1][j] + 1;
                    else up[i][j] = 1;
                }
            }
        }
        
        int res = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                res = max(res, min({up[i][j], down[i][j], left[i][j], right[i][j]}));
            }
        }
        return res;
    }
};
