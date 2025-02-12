typedef pair<int, pair<int, int>> P;
class Solution {
public:
    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();
        
        priority_queue<P, vector<P>, greater<P>> q; // <time, <x, y>>
        q.push({0, {0, 0}});
        while (!q.empty()) {
            P node = q.top();
            q.pop();
            int time = node.first;
            int x = node.second.first;
            int y = node.second.second;
            if (moveTime[x][y] == -1) continue;
            moveTime[x][y] = -1;
            if (x == n - 1 && y == m - 1) return time;
            for (auto& direction : directions) {
                int xx = x + direction.first;
                int yy = y + direction.second;
                if (xx < 0 || xx >= n || yy < 0 || yy >= m) continue;
                if (moveTime[xx][yy] == -1) continue;
                int nextTime = max(time + 1, moveTime[xx][yy] + 1);
                q.push({nextTime, {xx, yy}});
            }
        }
        return -1;
    }
};
