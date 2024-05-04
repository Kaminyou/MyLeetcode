typedef pair<int, pair<int, int>> P;
class Solution {
public:
    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int k = queries.size();
        vector<int> ans(k, 0);
        
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        vector<pair<int, int>> queriesWithIdx;
        for (int i = 0; i < k; ++i) {
            queriesWithIdx.push_back(make_pair(queries[i], i));
        }
        sort(queriesWithIdx.begin(), queriesWithIdx.end());
        
        int count = 0;
        priority_queue<P, vector<P>, greater<P>> minPQ;
        minPQ.push({grid[0][0], {0, 0}});
        visited[0][0] = true;
        
        
        for (int i = 0; i < k; ++i) {
            int number = queriesWithIdx[i].first;
            int index = queriesWithIdx[i].second;
            while (minPQ.size() > 0 && number > minPQ.top().first) {
                count++;
                int x = minPQ.top().second.first;
                int y = minPQ.top().second.second;
                minPQ.pop();
                for (auto& direction : directions) {
                    int nextX = x + direction.first;
                    int nextY = y + direction.second;
                    if (nextX < 0 || nextX >= m || nextY < 0 || nextY >= n) continue;
                    if (visited[nextX][nextY]) continue;
                    minPQ.push({grid[nextX][nextY], {nextX, nextY}});
                    visited[nextX][nextY] = true;
                }
            }
            ans[index] = count;
            
        }
        return ans;
    }
};