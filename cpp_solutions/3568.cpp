class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();
        vector<vector<vector<int>>> maxE(m, vector<vector<int>>(n, vector<int>(1025, -1)));
        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        queue<vector<int>> q; // [x, y, mask, e, steps]
        unordered_map<int, int> pos2LIdx;
        int idx = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (classroom[i][j] == 'S') {
                    q.push({i, j, 0, energy, 0});
                }
                if (classroom[i][j] == 'L') {
                    pos2LIdx[i * 32 + j] = idx;
                    idx++;
                }
            }
        }
        int goal = (1 << idx) - 1;
        while (!q.empty()) {
            vector<int> v = q.front();
            q.pop();
            int x = v[0];
            int y = v[1];
            int mask = v[2];
            int e = v[3];
            int steps = v[4];
            if (mask == goal) return steps;
            if (e == 0) continue;
            for (auto& direction : directions) {
                int xx = x + direction.first;
                int yy = y + direction.second;
                int newMask = mask;
                if (xx < 0 || xx >= m || yy < 0 || yy >= n) continue;
                if (classroom[xx][yy] == 'X') continue;
                int newE = e - 1;
                if (classroom[xx][yy] == 'L') {
                    newMask |= (1 << pos2LIdx[xx * 32 + yy]);
                }
                if (classroom[xx][yy] == 'R') {
                    newE = energy;
                }
                if (newE <= maxE[xx][yy][mask]) continue;
                maxE[xx][yy][newMask] = newE;
                q.push({xx, yy, newMask, newE, steps + 1});
            }
        }
        return -1;
    }
};

