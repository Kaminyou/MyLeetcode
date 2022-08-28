typedef pair<int, pair<int, int>> P; // {height, {x, y}}
class Solution {
public:
    int M;
    int N;
    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int bfs(int srcX, int srcY, int desX, int desY, vector<vector<int>>& forest) {
        vector<vector<int>> copyForest = forest;
        queue<pair<int, int>> q;
        q.push({srcX, srcY});
        int distance = 0;
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; ++i) {
                auto [currX, currY] = q.front();
                q.pop();
                if (currX == desX && currY == desY) return distance;
                for (auto& direction : directions) {
                    int nextX = currX + direction.first;
                    int nextY = currY + direction.second;
                    if (nextX < 0 || nextX >= M || nextY < 0 || nextY >= N) continue;
                    if (copyForest[nextX][nextY] == 0) continue;
                    q.push({nextX, nextY});
                    copyForest[nextX][nextY] = 0;
                }
            }
            distance++;
        }
        return -1;
    }
    int cutOffTree(vector<vector<int>>& forest) {
        vector<P> collections;
        int m = forest.size();
        int n = forest[0].size();
        M = m;
        N = n;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (forest[i][j] > 1) {
                    collections.push_back(make_pair(forest[i][j], make_pair(i, j)));
                }
            }
        }
        sort(collections.begin(), collections.end());
        
        int res = 0;
        if (collections[0].second.first != 0 || collections[0].second.second != 0) {
            collections.insert(collections.begin(), {0, {0, 0}});
        }
        int k = collections.size();
        for (int i = 1; i < k; ++i) {
            int srcX = collections[i - 1].second.first;
            int srcY = collections[i - 1].second.second;
            int desX = collections[i].second.first;
            int desY = collections[i].second.second;
            int plus = bfs(srcX, srcY, desX, desY, forest);
            if (plus == -1) return -1;
            res += plus;
        }
        return res;
    }
};