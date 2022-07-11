class Solution {
public:
    int minFlips(vector<vector<int>>& mat) {
        vector<pair<int, int>> neighbors = {{0, 0}, {1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        
        int m = mat.size();
        int n = mat[0].size();
        int encode = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                encode |= (mat[i][j] << (i * n + j));
            }
        }
        
        unordered_set<int> visited;
        queue<pair<int, int>> q;
        q.push(make_pair(encode, 0));
        visited.insert(encode);
        
        while (!q.empty()) {
            auto [state, count] = q.front();
            q.pop();
            if (state == 0) return count;
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    int nextState = state;
                    for (auto neighbor : neighbors) {
                        int ni = i + neighbor.first;
                        int nj = j + neighbor.second;
                        if (ni < 0 || ni >= m || nj < 0 || nj >= n) continue;
                        nextState ^= 1 << (ni * n + nj);
                    }
                    if (visited.find(nextState) == visited.end()) {
                        q.push(make_pair(nextState, count + 1));
                        visited.insert(nextState);
                    }
                }
            }
        }
        return -1;
    }
};