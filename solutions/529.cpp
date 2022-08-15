class Solution {
public:
    vector<pair<int, int>> directions = {{1, 1}, {1, 0}, {1, -1}, {0, 1}, {0, -1}, {-1, 1}, {-1, 0}, {-1, -1}};
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int m = board.size();
        int n = board[0].size();
        
        int x = click[0];
        int y = click[1];
        char c = board[x][y];
        if (c == 'M') {
            board[x][y] = 'X';
            return board;
        }
        queue<pair<int, int>> q;
        q.push({x, y});
        board[x][y] = 'B';
        while (!q.empty()) {
            auto [currX, currY] = q.front();
            q.pop();
            
            int count = 0;
            vector<pair<int, int>> neighbors;
            for (auto& [i, j] : directions) {
                int nextX = currX + i;
                int nextY = currY + j;
                if (nextX < 0 || nextX >= m || nextY < 0 || nextY >= n) continue;
                if (board[nextX][nextY] == 'M') count++;
                if (board[nextX][nextY] != 'E') continue;
                neighbors.push_back({nextX, nextY});
            }
            if (count == 0) {
                for (auto neighbor : neighbors) {
                    q.push(neighbor);
                    board[neighbor.first][neighbor.second] = 'B';
                }
            }
            else {
                board[currX][currY] = count + '0';
            }
        }
        return board;
    }
};