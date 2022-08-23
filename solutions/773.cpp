class Solution {
public:
    int res = INT_MAX;
    bool isEnd(vector<vector<int>>& board) {
        if (board[0][0] != 1) return false;
        if (board[0][1] != 2) return false;
        if (board[0][2] != 3) return false;
        if (board[1][0] != 4) return false;
        if (board[1][1] != 5) return false;
        if (board[1][2] != 0) return false;
        return true;
    }
    vector<pair<int, int>> directions = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
    int board2state(vector<vector<int>>& board) {
        int state = 0;
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 3; ++j) {
                state += board[i][j];
                state <<= 3;
            }
        }
        return state;
    }
    unordered_map<int, int> memo;
    unordered_set<int> visited;
    
    int slidingPuzzle(vector<vector<int>>& board) {
        // get position
        int x = -1, y = -1;
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[i][j] == 0) {
                    x = i;
                    y = j;
                    break;
                }
            }
            if (x != -1) break;
        }
        int state = board2state(board);
        visited.insert(state);
        queue<pair<vector<vector<int>>, pair<int, int>>> q;
        q.push({board, {x, y}});
        int res = -1;
        while (!q.empty()) {
            res++;
            int n = q.size();
            for (int i = 0; i < n; ++i) {
                auto [b, position] = q.front();
                auto [x_, y_] = position;
                q.pop();
                if (isEnd(b)) {
                    return res;
                }
                for (auto& direction : directions) {
                    int nX = x_ + direction.first;
                    int nY = y_ + direction.second;
                    if (nX < 0 || nX >= 2 || nY < 0 || nY >= 3) continue;
                    
                    vector<vector<int>> newB = b;
                    swap(newB[x_][y_], newB[nX][nY]);
                    
                    int nextState = board2state(newB);
                    if (visited.find(nextState) == visited.end()) {
                        visited.insert(nextState);
                        q.push({newB, {nX, nY}});
                    }
                }
            }
        }
        return -1;
    }
};