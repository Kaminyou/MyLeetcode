typedef tuple<int, int, int> T;
class Solution {
public:
    vector<pair<int, int>> directions = {{0, 1}, {0, - 1}, {1, 0}, {-1, 0}};
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        
        priority_queue<T, vector<T>, greater<T>> pq;
        pq.push(make_tuple(grid[0][0], 0, 0));
        
        int res = 0;
        while (!pq.empty()) {
            auto t = pq.top();
            pq.pop();
            int level = get<0>(t);
            int x = get<1>(t);
            int y = get<2>(t);
            
            res = max(res, level);
            if (x == n - 1 && y == n - 1) return res;
            for (auto& direction : directions) {
                int nextX = x + direction.first;
                int nextY = y + direction.second;
                if (nextX < 0 || nextX >= n || nextY < 0 || nextY >= n) continue;
                if (visited[nextX][nextY]) continue;
                pq.push(make_tuple(grid[nextX][nextY], nextX, nextY));
                visited[nextX][nextY] = true;
            }
        }
        return -1;
    }
};