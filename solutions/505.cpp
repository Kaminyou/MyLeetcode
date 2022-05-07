class Solution {
public:
    int M;
    int N;
    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    bool checkMove(int x, int y, vector<vector<int>>& maze) {
        if (x < 0 || x >= M) return false;
        if (y < 0 || y >= N) return false;
        if (maze[x][y] == 1) return false;
        return true;
    }
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        typedef pair<int, pair<int, int>> Point;
        M = maze.size();
        N = maze[0].size();
        int currDistance = 0;
        vector<vector<int>> distances(M, vector<int>(N, INT_MAX));
        distances[start[0]][start[1]] = 0;
        
        priority_queue<Point, vector<Point>, greater<Point>> pq;
        pq.push(make_pair(0, make_pair(start[0], start[1])));
        bool flag = false;
        while (!pq.empty()) {
            auto [dist, pos] = pq.top();
            auto [x, y] = pos;
            pq.pop();
            
            // if current position is the destination, break the loop
            if (x == destination[0] && y == destination[1]) break;
            for (auto direction : directions) {
                int _x = x;
                int _y = y;
                int move = 0;
                while (checkMove(_x + direction.first, _y + direction.second, maze)) {
                    _x += direction.first;
                    _y += direction.second;
                    move++;
                }
                if (!move) continue;
                if (move + dist < distances[_x][_y]) {
                    distances[_x][_y] = move + dist;
                    pq.push(make_pair(move + dist, make_pair(_x, _y)));
                }
            }
        }
        
        int res = distances[destination[0]][destination[1]];
        return res == INT_MAX ? -1 : res;
    }
};