class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        long long sum = 0;
        for (int num : wall[0]) sum += num;
        unordered_map<long long, int> breaks;
        
        int n = wall.size();
        int maxCnt = 0;
        for (int i = 0; i < n; ++i) {
            int current = 0;
            for (int j = 0; j < wall[i].size() - 1; ++j) {
                current += wall[i][j];
                breaks[current]++;
                maxCnt = max(maxCnt, breaks[current]);
            }
        }
        
        return n - maxCnt;
    }
};