class Solution {
public:
    vector<pair<int, int>> directions = {{1, 2}, {-1, 2}, {1, -2}, {-1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};
    bool checkValidGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<pair<int, int>> locations(n * n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                locations[grid[i][j]] = {i, j};
            }    
        }
        
        int currentX = 0;
        int currentY = 0;
        for (int i = 1; i < n * n; ++i) {
            int diffX = locations[i].first - currentX;
            int diffY = locations[i].second - currentY;
            pair<int, int> p = {diffX, diffY};
            bool have = false;
            for (auto& direction : directions) {
                if (p == direction) have = true;
            }
            if (!have) return false;
            currentX = locations[i].first;
            currentY = locations[i].second;
        }
        return true;
    }
};