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

// V2
// class Solution {
// public:
//     vector<vector<int>> check;
    
//     void _backtracking(int from, int curr, vector<bool>& visited, int m, int n, int& res) {
//         if (curr >= m && curr <= n) {
//             res++;
//         }
//         if (curr > 9) return;
//         for (int to = 1; to <= 9; ++to) {
//             if (visited[to] == true) continue;
//             if (check[from][to] != -1 && visited[check[from][to]] == false) continue;
//             visited[to] = true;
//             _backtracking(to, curr + 1, visited, m, n, res);
//             visited[to] = false;
//         }
//     }
//     int backtracking(int from, int curr, vector<bool>& visited, int m, int n) {
//         int res = 0;
//         visited[from] = true;
//         _backtracking(from, 1, visited, m, n, res);
//         visited[from] = false;
//         return res;
//     }
//     int numberOfPatterns(int m, int n) {
//         check.resize(10, vector<int>(10, -1));
//         check[1][3] = check[3][1] = 2;
//         check[4][6] = check[6][4] = check[1][9] = check[9][1] = check[3][7] = check[7][3]  = 5;
//         check[7][9] = check[9][7] = 8;
//         check[1][7] = check[7][1] = 4;
//         check[2][8] = check[8][2] = 5;
//         check[3][9] = check[9][3] = 6;

//         vector<bool> visited(10, false);
//         int a = backtracking(1, 0, visited, m, n);
//         int b = backtracking(2, 0, visited, m, n);
//         int c = backtracking(5, 0, visited, m, n);
//         return a * 4 + b * 4 + c;
//     }
// };