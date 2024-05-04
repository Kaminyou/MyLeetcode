class Solution {
public:
    vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    unordered_map<string, int> memo;
    
    int shortestPathAllKeys(vector<string>& grid) {
        unordered_set<string> visited;
        int m = grid.size();
        int n = grid[0].size();
        int x = -1;
        int y = -1;
        int cnt = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '@') {
                    x = i;
                    y = j;
                }
                else if (grid[i][j] >= 'a' && grid[i][j] <= 'f') cnt++;
            }
        }
        queue<pair<string, pair<int, int>>> q;
        q.push({"",{x, y}});
        visited.insert("#" + to_string(x) + "#" + to_string(y));
        int level = 0;
        while (!q.empty()) {
            int K = q.size();
            for (int k = 0; k < K; ++k) {
                auto [oldKeys, position] = q.front();
                q.pop();
                auto [posX, posY] = position;
                if (oldKeys.size() == cnt) return level;
                for (auto& direction : directions) {
                    int nextX = posX + direction.first;
                    int nextY = posY + direction.second;
                    if (nextX < 0 || nextX >= m || nextY < 0 || nextY >= n) continue;
                    if (grid[nextX][nextY] == '#') continue;
                    string keys = oldKeys;
                    if (grid[nextX][nextY] >= 'A' && grid[nextX][nextY] <= 'F') {
                        if (keys.find(grid[nextX][nextY] - 'A' + 'a') == string::npos) continue;
                        string hash = keys + "#" + to_string(nextX) + "#" + to_string(nextY);
                        if (visited.find(hash) != visited.end()) continue;
                        q.push({keys, {nextX, nextY}});
                        visited.insert(hash);
                    }
                    else if (grid[nextX][nextY] >= 'a' && grid[nextX][nextY] <= 'f') {
                        if (keys.find(grid[nextX][nextY]) == string::npos) {
                            keys.push_back(grid[nextX][nextY]);
                        }
                        string hash = keys + "#" + to_string(nextX) + "#" + to_string(nextY);
                        if (visited.find(hash) != visited.end()) continue;
                        q.push({keys, {nextX, nextY}});
                        visited.insert(hash);
                    }
                    else {
                        string hash = keys + "#" + to_string(nextX) + "#" + to_string(nextY);
                        if (visited.find(hash) != visited.end()) continue;
                        q.push({keys, {nextX, nextY}});
                        visited.insert(hash);
                    }
                }
            }
            level++;
        }
        return -1;
    }
};