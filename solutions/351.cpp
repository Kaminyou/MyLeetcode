class Solution {
public:
    int backtracking(int num, int curr, int m, int n, vector<bool>& visited, vector<vector<int>>& jump) {
        int res = 0;
        _backtracking(num, curr, m, n, visited, jump, res);
        return res;
    }
    void _backtracking(int num, int curr, int m, int n, vector<bool>& visited, vector<vector<int>>& jump, int& res) {
        curr++;
        if (curr == n) {
            res++;
            return;
        }
        if (curr >= m) {
            res++;
        }
        visited[num] = true;
        for (int neighbor = 1; neighbor <= 9; neighbor++) {
            int jp = jump[num][neighbor];
            if (!visited[neighbor] && (jp == 0 || visited[jp])) {
                _backtracking(neighbor, curr, m, n, visited, jump, res);
            }
        }
        visited[num] = false;
    }
    int numberOfPatterns(int m, int n) {
        vector<bool> visited(10, false);
        vector<vector<int>> jump(10, vector<int>(10, 0));
        jump[1][3] = jump[3][1] = 2;
        jump[4][6] = jump[6][4] = 5;
        jump[7][9] = jump[9][7] = 8;
        jump[1][7] = jump[7][1] = 4;
        jump[2][8] = jump[8][2] = 5;
        jump[3][9] = jump[9][3] = 6;
        jump[1][9] = jump[9][1] = jump[3][7] = jump[7][3] = 5;
        int res = 0;
        res += backtracking(1, 0, m, n, visited, jump) * 4;
        res += backtracking(2, 0, m, n, visited, jump) * 4;
        res += backtracking(5, 0, m, n, visited, jump);
        return res;
    }
};