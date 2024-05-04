class Solution {
public:
    int M;
    int N;
    vector<pair<char, pair<int, int>>> directions = {{'u', {-1, 0}}, {'d', {1, 0}}, {'l', {0, -1}}, {'r', {0, 1}}};
    bool checkMove(int x, int y, vector<vector<int>>& maze) {
        if (x < 0 || x >= M) return false;
        if (y < 0 || y >= N) return false;
        if (maze[x][y] == 1) return false;
        return true;
     }
    string findShortestWay(vector<vector<int>>& maze, vector<int>& ball, vector<int>& hole) {
        M = maze.size();
        N = maze[0].size();
        typedef tuple<int, string, int, int> Node;
        
        priority_queue<Node, vector<Node>, greater<Node>> pq;
        vector<vector<int>> distances(M, vector<int>(N, INT_MAX));
        
        pq.push(make_tuple(0, "", ball[0], ball[1]));
        distances[ball[0]][ball[1]] = 0;
        
        while (!pq.empty()) {
            auto [dist, path, x, y] = pq.top();
            pq.pop();
            
            if (x == hole[0] && y == hole[1]) {
                return path;
            }
            
            for (auto direction : directions) {
                int _x = x;
                int _y = y;
                auto [way, vec] = direction;
                auto [i, j] = vec;
                int move = 0;
                while (checkMove(_x + i, _y + j, maze)) {
                    _x += i;
                    _y += j;
                    move++;
                    if (_x == hole[0] && _y == hole[1]) break;
                }
                if (!move) continue;
                int currMove = dist + move;
                if (currMove <= distances[_x][_y]) {
                    distances[_x][_y] = currMove;
                    string _path = path;
                    _path.push_back(way);
                    pq.push(make_tuple(currMove, _path, _x, _y));
                }
            }
        }
        return "impossible";
    }
};