class Solution {
public:
    int M;
    int N;
    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    bool backtracking(int x, int y, int index, string& word, vector<vector<char>>& board, vector<vector<bool>>& visited) {
        if (index + 1 == word.size()) return true;
        bool found = false;
        for (auto& direction : directions) {
            if (found) break;
            int nextX = x + direction.first;
            int nextY = y + direction.second;
            if (nextX < 0 || nextX >= M || nextY < 0 || nextY >= N) continue;
            if (visited[nextX][nextY]) continue;
            if (board[nextX][nextY] != word[index + 1]) continue;
            visited[nextX][nextY] = true;
            if (backtracking(nextX, nextY, index + 1, word, board, visited)) {
                found = true;
            }
            visited[nextX][nextY] = false;
        }
        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        M = board.size();
        N = board[0].size();
        vector<vector<bool>> visited(M, vector<bool>(N, false));
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (board[i][j] == word[0]) {
                    visited[i][j] = true;
                    if (backtracking(i, j, 0, word, board, visited)) return true;
                    visited[i][j] = false;
                }
            }
        }
        return false;
    }
};