class Solution {
public:
    const int MAX_WIDTH = 304;
    int minKnightMoves(int x, int y) {
        vector<vector<bool>> visited(MAX_WIDTH * 2 + 1, vector<bool>(MAX_WIDTH * 2 + 1, false));
        
        vector<pair<int, int>> directions = {{1, 2}, {2, 1}, {-1, 2}, {-2, 1}, {1, -2}, {2, -1}, {-1, -2}, {-2, -1}};
        queue<pair<int, int>> q;
        q.push(make_pair(0, 0));
        visited[MAX_WIDTH][MAX_WIDTH] = true;
        
        int move = 0;
        while (!q.empty()) {
            int n = q.size();
            while (n--) {
                auto [xx, yy] = q.front();
                q.pop();
                if (xx == x && yy == y) return move;
                
                for (auto direction : directions) {
                    int _xx = xx + direction.first;
                    int _yy = yy + direction.second;
                    if (_xx <= -MAX_WIDTH || _xx >= MAX_WIDTH || _yy <= -MAX_WIDTH || _yy >= MAX_WIDTH) continue;
                    if (visited[MAX_WIDTH + _xx][MAX_WIDTH + _yy]) continue;
                    q.push(make_pair(_xx, _yy));
                    visited[MAX_WIDTH + _xx][MAX_WIDTH + _yy] = true;
                }
            }
            move++;
        }
        return -1;
    }
};